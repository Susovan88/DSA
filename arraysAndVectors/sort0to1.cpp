#include<iostream>
#include<vector>
using namespace std;
void sort0to1(vector<int>& v){
	int n=v.size();
	int i=0,j=n-1;
	while(i<=j){
		if(v[i]==0) i++;
		if(v[j]==1) j--;
		if(i>j) break;
		if(v[i]==1 && v[j]==0){
			int temp=v[i];
			v[i]=0;
			v[j]=1;
			i++;
		    j--;
		}
	}
}
void display(vector<int>& v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
  int n;
  cout<<"Enter size of array : ";
  cin>>n;
  vector<int>v;
  cout<<"Enter element :";
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    v.push_back(x);
  }
  
  sort0to1(v);  //method 2
  
  display(v);
}
