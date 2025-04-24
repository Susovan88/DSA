#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(9);
	v1.push_back(4);
	
	vector<int> v2;
	v2.push_back(8);
	v2.push_back(0);
	v2.push_back(6);
	v2.push_back(2);
	
	vector<int> v3;
	v3.push_back(18);
	v3.push_back(10);
	v3.push_back(6);
	v3.push_back(2);
	v3.push_back(8);
	v3.push_back(0);
	v3.push_back(6);
	
	vector< vector<int> > v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	
	cout<< v[2][4]<<endl;
	cout<< v[1][0]<<endl;
	cout<< v[0][1]<<endl;
	cout<< v[2][6]<<endl;
}
