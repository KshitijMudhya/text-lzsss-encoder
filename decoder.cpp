
#include <bits/stdc++.h>

using namespace std;
struct comp
{
    int length = 0,offset = 0;
};

comp convertor(string wem){
    comp data;
    string line = ""; 
    for(int i =0; i < wem.length();i ++){
        if(wem[i] == ','){
            for(int j=0;j<line.length();j++){
                data.offset += (int(line[j])-int('1')+1) * pow(10,line.length() - j-1);
            }
            line = "";

        }
        else{
            line += wem[i];
        }
        
    }
    for(int j=0;j<line.length();j++){
            data.length += (int(line[j])-int('1')+1) * pow(10,line.length() - j-1);
        }
    return data;
}


 

int main(){
    bool run = true;
    string line,line2 = "",line3 = "";
    int offset =0 , length = 0,string_length;
    cin>>line;
    comp data2;
    for(int i =0;i<line.length();i++){
        if(line[i] == '('){
            for(int j = i+1;line[j] != ')';j++){
                line2 += line[j];
            }
            data2 = convertor(line2);
            string_length = line3.length();
            for(int k=string_length-data2.offset;k<string_length-data2.offset+data2.length;k++){
                
                line3 += line3[k];
            }

            i += line2.length()+1;
            line2 = ""; 

        }
        else{
            line3 += line[i];
        }
       
        
    }
    
    cout<<line3<<endl;
    
}
