#include <bits/stdc++.h>
using namespace std;

int main()
{
    int sliding_window = 15, look_ahead = 4, counter = 0,counter1 = 0;
    char window[sliding_window];
    int offset = 0, length = 0, items_checked = 0;
    string line, encoded_string = "";

    cin >> line;

    for (int i = 0; i < sliding_window; i++)
    {
        window[i] = '0';
    }
    for (int i = sliding_window - look_ahead; i < sliding_window; i++)
    {
        window[i] = line[counter1];
        counter1++;
    }
   
    while (1)
    {
        if(items_checked == line.length()){
            break;
        }
        for (int i = 0; i < sliding_window - look_ahead; i++)
        {
            
            while (window[i] == window[sliding_window - look_ahead + counter])
            {
                length++;
                offset = sliding_window - look_ahead + counter - i;
                i++;
                counter++;
            }
        }
        if (length == 0)
        {   
    
            items_checked += 1;
            encoded_string += window[sliding_window - look_ahead + counter];
            for (int i = 0; i < sliding_window; i++)
                {
                    window[i] = window[i + 1];
                }
                if(line.length()>counter1){
                    
                    window[sliding_window-1] = line[counter1]; 
                    
                    counter1++;
                }
        }
        else
        {
            for (int j = 0; j < length; j++)
            {
                for (int i = 0; i < sliding_window; i++)
                {
                    window[i] = window[i + 1];
                }
                
                if(line.length()>counter1){
                    window[sliding_window-1] = line[counter1];
                    
                    counter1++;
                }
                
            }
            encoded_string += "<"+to_string(length)+"," +to_string(offset)+">";
            items_checked += length;
            length = 0;
            counter = 0;
        }
    
        
    }
    cout << encoded_string;
}
