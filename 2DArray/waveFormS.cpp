#include<iostream>
using namespace std;
int main(){
  int m;
  cout<<"enter  row :";
  cin>>m;
  int n;
  cout<<"enter column :";
  cin>>n;
  int arr[m][n];
  //taking input...
  cout<<"enter elements of array :";
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      cin>>arr[i][j];
    }
  }
  bool flag=true;
  for(int i=m-1;i>=0;i--){
  	if(flag==true){
  		for(int j=0;j<n;j++){
  			cout<<arr[i][j]<<" ";
		}
		flag=false;
	}
	else{
		for(int j=n-1;j>=0;j--){
			cout<<arr[i][j]<<" ";
		}
		flag=true;
	}
  }

}
