#include<iostream>
#include<vector>
using namespace std;
void display(vector<int>& v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void sort012(vector<int>& nums){
	int n=nums.size();
	int low=0,mid=0,hi=n-1;
	// 1) mid ke baare me socho
	// 2) 0 to low-1 -> 0, hi+1 to end ->2
	// 3) lo to mid-> 1
	while(mid<=hi){
		if(nums[mid]==2){
			int temp=nums[mid];
			nums[mid]=nums[hi];
			nums[hi]=temp;
			hi--;
		}
		else if(nums[mid]==0){
			int temp=nums[mid];
			nums[mid]=nums[low];
			nums[low]=temp;
			low++;
			mid++;
		}
		else if(nums[mid]==1){
			mid++;
		}
		
	}
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
  sort012(v);
  display(v);
}
