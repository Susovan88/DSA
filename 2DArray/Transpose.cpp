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
	cout<<endl;
	//transpose...
	int tran[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			tran[i][j]=arr[j][i];
			cout<<tran[i][j]<<" "; // print...
		}
		cout<<endl;
	}
	
}
