#include<iostream>
#include<vector>
using namespace std;
int main(){
  int sum;
  cout<<"Enter target : ";
  cin>>sum;
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
  for(int i=0;i<v.size()-1;i++){   //i<=v.size()-2
    for(int j=i+1;j<v.size();j++){  //i<=v.size()-1
      if(v[i]+v[j]==sum){
        cout<<"("<<i<<","<<j<<")"<<endl;
      }
    }
  }
}
