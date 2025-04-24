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
    //spiral form...
    int minr=0,maxr=m-1;
    int minc=0,maxc=n-1;
    int tne=m*n; //total number of elements
    int count=0;
    while(minr<=maxr && minc<=maxc){
    	//right
    	for(int j=minc;j<=maxc && count<tne;j++){
    		cout<<arr[minr][j]<<" ";
    		count++;
		}
		minr++;
		//down
		for(int i=minr;i<=maxr && count<tne;i++){
			cout<<arr[i][maxc]<<" ";
			count++;
		}
		maxc--;
		//left
		for(int j=maxc;j>=minc && count<tne;j--){
			cout<<arr[maxr][j]<<" ";
			count++;
		}
		maxr--;
		//up
		for(int i=maxr;i>=minr && count<tne;i--){
			cout<<arr[i][minc]<<" ";
			count++;
		}
		minc++;
	}
}
 
 
 
 
    
    
    
    
