#include<iostream>
#include<vector>
using namespace std;

void display(vector<int>& v3){
  for(int i=0;i<v3.size();i++){
        cout<<v3[i]<<" ";
    }
    cout<<endl;
}

vector<int> merge(vector<int>& v1,vector<int>& v2){
  int n=v1.size(),m=v2.size();
  vector<int> v3(n+m);
  int i=0,j=0,k=0;   // i->v1  j->v2  k->v3
  while(i<n && j<m){
    if(v1[i]<v2[j]){
      v3[k]=v1[i];
      i++;
    }
    else{    // (v2[j]<v1[i])
      v3[k]=v2[j];
      j++;
    }
    k++;
    
    // for remaning
    if(i==n){  // v1 ka element utha chucka hoon
      while(j<m){
      v3[k]=v2[j];
      j++;
      k++;
      }  
    }
    if(j==m){  // v2 ka element utha chucka hoon
      while(i<n){
      v3[k]=v1[i];
      i++;
      k++;
      }
    }
  }
  return v3;
}

int main(){
  int n;
  cout<<"Enter size of 1st array : ";
  cin>>n;
  vector<int>v1;
  cout<<"Enter element :";
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    v1.push_back(x);
  }

  int m;
  cout<<"Enter size of 2nd array : ";
  cin>>m;
  vector<int>v2;
  cout<<"Enter element :";
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    v2.push_back(x);
  }
  vector<int> v3 = merge(v1,v2);

  display(v3);

}
