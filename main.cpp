#include <iostream>
#include <string>
using namespace std;
void shift(char* s,int length,string test,int* count){
    for(int i=0;i<length;i++){
        *s = *(s+1);
        s+=1;
    }
    s -=1;
    if (*count< test.length()){
        *s = test[*count];
        *count += 1;
    }
    
}

int main()
{
    int sliding_window = 3200, look_ahead = 256,counter = 0,counter1 = 0;
    char window[sliding_window];
    int offset,starter = 0, length = 0, items_checked = 0;
    string line, encoded_string = "", test_string = "";
    bool found = false;
    cin >> line;
    for(int i = 0;i<sliding_window;i++){
        
        if(i>=sliding_window-look_ahead){
            window[i] = line[counter1];
            counter1++;
        }
        else{
            window[i] = '\0';
        }
    }
    while (1)
    {
    
        if(items_checked > line.length()){
            break;
        }
        for(int i=starter;i<sliding_window-look_ahead;i++){
            while (window[i] == window[sliding_window-look_ahead+counter] && window[i] != '\0')
            {
                length++;
                test_string += window[i]; 
                offset = sliding_window-look_ahead+counter-i;
                i++;
                counter++;
                  
                found = true;
            }
            if(found){
                break;
            }
        }
        if(found){
            if(("("+to_string(offset)+','+to_string(length)+")").length()<test_string.length()){
                encoded_string += "("+to_string(offset)+','+to_string(length)+")";
            }
            else{
                encoded_string += test_string;
            }
            for(int k=0;k<test_string.length();k++){
                shift(window,sliding_window,line,&counter1);
            }

            test_string = "";
            items_checked += length;
            length = 0;
            counter = 0;
            found = false;
        }
        else{
            encoded_string += window[sliding_window-look_ahead];
            shift(window,sliding_window,line, &counter1);
            items_checked +=1;
        }

    }
    cout<<encoded_string;
}
