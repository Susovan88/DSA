#include<iostream>
#include<vector>
using namespace std;
void sort(vector<int>& v){
    int n=v.size();
	int i=0,j=n-1;
	while(i<=j){
		if(v[i]>=0) i++;
		if(v[j]<0) j--;
		if(i>j) break;
		if(v[i]<0 && v[j]>=0){
			int temp=v[i];
			v[i]=v[j];
			v[j]=temp;
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
  
  sort(v);  
  
  display(v);
}
