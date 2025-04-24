#include<iostream>
#include<vector>
using namespace std;
void change2D(vector< vector<int> > &v){
	v[0][2]=100;
}
int main(){
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(9);
	v1.push_back(4);
	
	vector<int> v2;
	v2.push_back(8);
	v2.push_back(0);
	v2.push_back(6);
	
	vector<int> v3;
	v3.push_back(18);
	v3.push_back(10);
	v3.push_back(6);
	
	vector< vector<int> > v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
    
    cout<<v.size()<<endl; // row
	cout<<v[0].size()<<endl; // column
	
	cout<<v[0][2]<<endl;
	change2D(v);
	cout<<v[0][2]<<endl;
	
    vector< vector<int> > a(3,vector<int>(4,100));
    
    for(int i=0;i<3;i++){
    	for(int j=0;j<4;j++){
    		cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}

	
	
	
}
