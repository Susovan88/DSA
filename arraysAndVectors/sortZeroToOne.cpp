#include<iostream>
#include<vector>
using namespace std;
void display(int n,vector<int>& v){
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void sort01(int n,vector<int>& v){
    int no1=0,no0=0;
    for(int i=0;i<n;i++){
        if(v[i]==1) no1++;
        else no0++;
    }
    // filling elements
    for(int i=0;i<n;i++){
        if(i<no0) v[i]=0;
        else v[i]=1;
    }
}
int main(){
  int n;
  cout<<"Enter size of array : ";
  cin>>n;
  vector<int>v;
  cout<<"Enter element :";
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    v.push_back(x);
  }
  int b=v.size();
  sort01(b,v);
  display(b,v);
}
