#include<iostream>
using namespace std;

int main(){
	int arr[2][3]={{2,4,4},{3,9,6}};
	int brr[2][3]={{3,5,8},{9,2,0}};
//	int res[2][3];
//	for(int i=0;i<2;i++){
//		for(int j=0;j<3;j++){
//			res[i][j]=arr[i][j]+brr[i][j];
//		}
//	}
//	for(int i=0;i<2;i++){
//		for(int j=0;j<3;j++){
//			cout<<res[i][j]<<" ";
//		}
//		cout<<endl;
//	}
     
     //M-2
////
////    for(int i=0;i<2;i++){ // no extra array...
////		for(int j=0;j<3;j++){
////			cout<<arr[i][j]+brr[i][j]<<" ";
////		}
////		cout<<endl;
////	}
      
    //M-3
    for(int i=0;i<2;i++){  // b ke andar a add karna hai...
		for(int j=0;j<3;j++){
			brr[i][j]+=arr[i][j];
		}
	}
	
    for(int i=0;i<2;i++){
		for(int j=0;j<3;j++){
			cout<<brr[i][j]<<" ";
		}
		cout<<endl;
	}
}



