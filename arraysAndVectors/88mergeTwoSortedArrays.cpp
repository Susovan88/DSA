#include<iostream>
#include<vector>
using namespace std;


// 88. Merge Sorted Array
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) { // without use extra space , inplace
    int i=m+n-1;
    int x=m-1;
    int y=n-1;
    if(m==0)for(int i=0;i<n;i++)nums1[i]=nums2[i];
    while(i>=0 && x>=0 && y>=0){
        if(nums1[x]>nums2[y]){
            nums1[i]=nums1[x];
            if(x!=i)nums1[x]=0;
            x--;
        }else{
            nums1[i]=nums2[y];
            y--;
        }
        i--;
    }
    if(y>=0)for(int j=y;j>=0;j--)nums1[i--]=nums2[j];
}

void display(vector<int>& v3){
  for(int i=0;i<v3.size();i++){
        cout<<v3[i]<<" ";
    }
    cout<<endl;
}

vector<int> merge1(vector<int>& v1,vector<int>& v2){
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
  vector<int>arr1={1,4,6,9,14,16,17,0,0,0,0,0};
  vector<int>arr2={2,4,7,11,18};
  merge(arr1,7,arr2,5);
  display(arr1);
}
