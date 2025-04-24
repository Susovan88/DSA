#include <iostream>
#include <vector>
using namespace std;

int maze(int sr,int sc){
    if(sr<0 || sc<0 )return 0;
    if(sr==0 && sc==0) return 1;

    int rightWays=maze(sr,sc-1);
    int downWays=maze(sr-1,sc);
    return rightWays + downWays;
}

void PrintPaths(int sr,int sc,string s){
    if(sr<0 || sc<0 ) return;
    if(sr==0 && sc==0){ // after reatch the distination.
        cout<<s<<endl;
    }
    PrintPaths(sr,sc-1,s+" R "); // right ways...
    PrintPaths(sr-1,sc,s+" D ");  // Down Ways...
}


int main(){

    cout<<"Total Ways : "<<maze(2,2)<<endl;

    PrintPaths(2,2,"");
}