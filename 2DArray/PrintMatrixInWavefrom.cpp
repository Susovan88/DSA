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
////wave from...my code
//  bool flag=true; 
//  for(int i=0;i<m;i++){
//  	if(flag==true){  // true means -> j=0 to n-1
//  		for(int j=0;j<n;j++){
//  			cout<<arr[i][j]<<" ";
//		}
//		flag=false;
//    }
//    else{ //flag==false   false means -> j=n-1 to 0
//    	for(int j=n-1;j>=0;j--){
//    		cout<<arr[i][j]<<" ";
//		}
//		flag=true;
//	}
//  }
   
   
   //pw...
  for(int i=0;i<m;i++){
  	if(i%2==0){  
  		for(int j=0;j<n;j++){
  			cout<<arr[i][j]<<" ";
		}
    }
    else{ 
    	for(int j=n-1;j>=0;j--){
    		cout<<arr[i][j]<<" ";
		}
	}
  }

}
