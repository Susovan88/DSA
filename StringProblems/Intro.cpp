#include <iostream>
#include<vector>
#include<string>
using namespace std;

int main(){

    // char str[]={'d','f','w','\0','s','e','a'};
    // char str[5]="suso";
    // for(int i=0;str[i]!='\0';i++) cout<< str[i] << " ";
    // cout<<endl;

    // char ch='\0';  // '\0' => null char
    // cout<<(int)ch << endl;

    // cout<< str[5]<<endl;
    // cout<<str;


    // // string as a data type.


    // vowel count....
    string str; 
    int count=0;
    cout<<"vowel :"<< endl;

    getline(cin,str);
    cout<<"your string: "<<str<<endl;

    int i=0;
    while(str[i]!='\0'){
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')count++;
        i++;
    }

    cout<<"total vowle- "<<count;

    cout<<"change the char of even position"<<endl;

    for(int i=0;str[i]!='\0';i++){
        if(i%2==0) str[i]='A';
    }

    cout<<str;

}
