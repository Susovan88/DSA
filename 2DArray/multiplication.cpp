#include<iostream>
using namespace std;
int main(){
  int m;
  cout<<"enter 1st row :";
  cin>>m;
  int n;
  cout<<"enter 1st column :";
  cin>>n;
  int arr[m][n];
  //taking input...
  cout<<"enter elements of first array :";
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      cin>>arr[i][j];
    }
  }
  int p;
  cout<<"enter 2nd row :";
  cin>>p;
  int q;
  cout<<"enter 2nd column :";
  cin>>q;
  int brr[p][q];
    //taking input...
  cout<<"enter elements of 2nd array :";
  for(int i=0;i<p;i++){
    for(int j=0;j<q;j++){
      cin>>brr[i][j];
    }
  } 
    // mutiplitation...
    if(n==q){
    	int res[m][q];
    	for(int i=0;i<m;i++){
    		for(int j=0;j<q;j++){
    			res[i][j]=0;
    			for(int k=0;k<p;k++){
    				res[i][j]+=arr[i][k]*brr[k][j];
				}
			}
		}
		// print resultant array...		
	    for(int i=0;i<m;i++){
		    for(int j=0;j<q;j++){
		       cout<<res[i][j]<<" ";
	    	}
	    	cout<<endl;
    	}
	}
    else cout<<"Not prosible. ";

}
