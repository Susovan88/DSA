#include<iostream>
#include<vector>
using namespace std;
int main(){
	//int arr[3][3]={{1,2,2},{3,4,2},{9,8,5}};
	int arr[3][3]={1,2,2,3,4,2,9,8,5};
	// row->3 (0 1 2) , columns->3 (0 1 2)	
	cout<<arr[1][2]<<endl;
	cout<<arr[0][1]<<endl;
	
	int brr[][3]={1,2,3,4,4,5,8,9,0};
	cout<<arr[0][2]<<endl;
	cout<<arr[0][1]<<endl;
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	
}
