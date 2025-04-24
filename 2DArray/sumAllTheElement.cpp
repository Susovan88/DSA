#include<iostream>
using namespace std;
int main(){
	int m;
	cout<<"enter number of rows :";
	cin>>m;
	int n;
	cout<<"enter number of columns :";
	cin>>n;
	int arr[m][n];
	//taking input...
	cout<<"enter elements :";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	//print...
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	int sum=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			sum+=arr[i][j];
		}
	}
	cout<<"sum is : "<<sum;
}
