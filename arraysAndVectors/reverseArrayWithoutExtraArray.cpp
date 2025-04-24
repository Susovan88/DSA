#include<iostream>
#include<vector>
using namespace std;
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
  
  // reverse
  
//  int i=0,j=v.size()-1;
//  while(i<=j){  // swap v[i]  and v[j]
//  int temp=v[i];
//  	v[i]=v[j];
//  	v[j]=temp;
//  	i++;
//  	j--;
//  }

//reverse(v.begin(),v.end());

for(int i=0,j=v.size()-1;i<=j;i++,j--){
	int temp=v[i];
	v[i]=v[j];
	v[j]=temp;
} 
for(int i=0;i<v.size();i++){
  	cout<<v[i]<<" ";
  }
}
