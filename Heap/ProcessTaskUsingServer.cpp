#include <iostream>
#include <queue> 
#include <string>
#include <vector>
using namespace std;

// 1882. Process Tasks Using Servers
vector<int> assignTasks(vector<int>& srv, vector<int>& tsk) {
    int n=srv.size();
    int m=tsk.size();
    vector<int>ans(m,0);
    if(n==1)return ans;
    // min weight server => <serverWeight,serverIdx>
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; 
    // which server will free first => <completeTime,serverIdx>
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>fr; 
    queue<pair<int,int>>qu;// task queue...
    for(int i=0;i<n;i++){
        pq.push({srv[i],i});
    }
    int count=0;
    long long t=0;// time -> sec
    while(true){
        if(t<m)qu.push({tsk[t],t});
        if(count==m)break;
        while(qu.size()!=0){
            // insert the free severs from fr to pq
            while(fr.size()!=0 && fr.top().first<=t){
                auto freeS=fr.top();
                pq.push({srv[freeS.second],freeS.second});
                fr.pop();
            }
            if(pq.size()==0){
                if(t>=m)t=fr.top().first-1;
                break;
            }
            auto temp=qu.front(); // single task
            qu.pop(); 
            auto app=pq.top(); // server 
            pq.pop();
            int endP=(t+temp.first); // complete time of the process 
            fr.push({endP,app.second});
            ans[temp.second]=app.second;
            count++;
        }
        t++;
    }

    return ans;
}

int main(){
    vector<int>servers={5,8,2,4,1,6,9,3};
    vector<int>tasks={1,23,4,6,13,45,6,1,3,56,12,3,4,6,3,1,3,1,3,1};
    vector<int>sIdx=assignTasks(servers,tasks);
    for(int i=0;i<sIdx.size();i++){
        cout<<"task id -> "<<i<<" is completed by server id-> "<<sIdx[i]<<endl;
    }
    return 0;
}