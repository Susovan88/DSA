#include<iostream>
#include<climits>
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
	//largest element...
	int max1=INT_MIN;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]>max1) max1=arr[i][j];
		}
	}
	cout<<"largest element : "<<max1<<endl;
	//2nd largest element...
	int max2=INT_MIN;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]>max2 && max2!=max1) max2=arr[i][j];
		}
	}
    cout<<"2nd largest element : "<<max2;

}



