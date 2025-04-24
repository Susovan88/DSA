#include<iostream>
using namespace std;
int main(){
	int m=2; //row-> rollno. , marks
	int n;
	cout<<"enter number of students :";
	cin>>n;
	int arr[m][n];
	//taking input
	cout<<"enter elements :";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	//print
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	
}
