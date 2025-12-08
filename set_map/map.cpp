#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include <vector>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int,int>mp;
    unordered_set<int>st;
    for(int el : arr){
        mp[el]++;
    }
    for(auto m : mp)st.insert(m.second);
    return st.size() == mp.size();
}

bool isAnagram(string s, string t) {   //  242. Valid Anagram
    unordered_map<char,int>mp;
    for(char ch : s){
        if(mp.size()==0 || mp.find(ch)==mp.end()){
            mp[ch]=1;
        }else{
            mp[ch]++;
        }
    }
    
    for (char ch : t){
        if( mp.find(ch)==mp.end())return false;
        else{
            mp[ch]--;
            if(mp[ch]==0) mp.erase(ch);
        }
    }
    return mp.size()==0?true:false;
}

int main(){
    unordered_map<string,int>mp;
    pair<string,int>p1;
    p1.first="pupai";
    p1.second=9134309;

    mp.insert(p1);
    
    pair<string,int>p2;
    p2.first="susovan";
    p2.second=9123912;
    mp.insert(p2);

    pair<string,int>p3;
    p3.first="tainya";
    p3.second=122339;

    mp.insert(p3);

    mp.insert({"mimi",122312});

    mp["tiger"]=982367;

    mp["raghav"]=9865;

    cout<<mp.size()<<endl;

    for (auto m : mp){
        cout<<m.first<<" "<<m.second<<endl;
    }
    mp.erase("mimi");

    cout<<mp.size()<<endl;

    for (auto m : mp){
        cout<<m.first<<" "<<m.second<<endl;
    }


    string s = "anagram", t = "nagaram";

    bool ans= isAnagram(s,t);

    cout<<"answer is -> "<<ans<<endl;

    vector<int>arr;
    arr={1,2,3,4,12,12,4,4,4,4,0,0,0,0,12,12,2,2,2,1,1,3,3,2,23,3,3,3,5,2,1,4,5,23,0,78,12,78,78,12,11,2};
    bool ans2=uniqueOccurrences(arr);

    cout<<"answer2 is -> "<<ans2;
}