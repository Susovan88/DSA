#include<iostream>
#include<vector>
using namespace std;
void display(vector<int>& a){
	for(int i=0;i<a.size();i++){
		cout<<a[i]<<" ";
	}
}
void reversePart(int i,int j,vector<int>& v){
	while(i<=j){
		int temp=v[i];
		v[i]=v[j];
		v[j]=temp;
		i++;
		j--;
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
  
   // reverse part of array.
   
   reversePart(0,3,v);
   display(v);
   
}
