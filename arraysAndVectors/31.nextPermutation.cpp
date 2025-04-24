#include<iostream>
#include<vector>
using namespace std;
void rev(vector<int>& nums,int i,int j){
	int temp=nums[i];
	nums[i]=nums[j];
	nums[j]=temp;
}
void display(vector<int>& v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int idx=-1;
        //finding pivot indx
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }           
        }
        if(idx==-1){
            rev(nums,0,n-1);
            //reverse(nums.begin(), nums.end());
            return;
        }
        // sorting/reverse after pivot...
        rev(nums,idx+1,n-1);
        //reverse(nums.begin()+idx+1 , nums.end());
        //finding the just greater number than idx
        int j=0;
        for(int i=idx+1;i>=0;i++){
            if(nums[i]>nums[idx]){
                j=i;
                break;
            }
        }
        // swaping idx and j
        int temp=nums[idx];
        nums[idx]=nums[j];
        nums[j]=temp;
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
  nextPermutation(v);
  display(v);
}
