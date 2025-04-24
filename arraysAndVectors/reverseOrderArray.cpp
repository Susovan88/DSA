#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n;
  cout<<"Enter size of array : ";
  cin>>n;
  vector<int>v1;
  cout<<"Enter element :";
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    v1.push_back(x);
  }
  vector<int>v2(v1.size());
  for(int i=0;i<v2.size();i++){
    int j=v1.size()-1-i;
    v2[i]=v1[j];
  } 
  for(int i=0;i<v2.size();i++){
      cout<<v2[i]<<" ";
    }
  
}
