#include<iostream>
#include<vector>
using namespace std;
void reversePart(int i,int j,vector<int>& v){
	while(i<=j){
	  int temp=v[i];
	  v[i]=v[j];
	  v[j]=temp;
	  i++;
	  j--;
	}
}
void display(vector<int>& a){
	for(int i=0;i<a.size();i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main(){
  int x;
  cout<<"Enter size of array : ";
  cin>>x;
  vector<int>v;
  cout<<"Enter element :";
  for(int i=0;i<x;i++){
    int x;
    cin>>x;
    v.push_back(x);
  }
  int n=v.size(), k;
  cout<<"Enter number : ";
  cin>>k;
  display(v);
  
   // reverse part of array.
   
   if(k>n) k=k%n;
   else if(k%n==0) k=k-n;
   reversePart(0,n-k-1,v);
   reversePart(n-k,n-1,v);
   reversePart(0,n-1,v);
   
   display(v);
}
