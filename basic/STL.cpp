#include<iostream>
#include <algorithm>
#include<vector>
#include<list>
#include<stack>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include <functional> 
using namespace std;


int main(){

    vector<int> a={5,6,2,6,9,12,0};

    vector<int>::iterator i;
    for(i=a.begin();i!=a.end();i++){
        cout<<*(i)<<" ";
    }
    cout<<endl;

    vector<int>::reverse_iterator it;
    for(it=a.rbegin();it!=a.rend();it++){
        cout<<*(it)<<" ";
    }
    cout<<endl;

    list<int>li;

    li.push_back(8);
    li.push_front(80);
    li.push_back(8);
    li.emplace_back(9);
    li.emplace_front(90);

    for(int l : li) cout<<l<<" ";
    cout<<endl;

    li.pop_back();
    li.pop_front();

    for(int l : li) cout<<l<<" ";
    cout<<endl;

    pair<int,int>p1={9,8};
    cout<<p1.first<<" "<<p1.second<<endl;
    pair<int, pair<int,char>>p2={9,{67,'S'}};
    cout<<p2.first<<" "<<p2.second.first<<" "<<p2.second.second<<endl;

    vector<pair<char,int>>arr={{'U',90},{'S',67},{'T',137}};
    arr.push_back({'P',89});
    arr.emplace_back('Q',9); //
    for(auto v : arr){
        cout<<v.first<<" "<<v.second<<endl;
    }

    stack<int>s;
    s.push(1);
    s.push(8);
    s.push(9);
    s.push(2);

    stack<int>s1;
    s1.swap(s);
    s1.push(87654);

    while (!s1.empty()) {  
        cout << s1.top() << " ";
        s1.pop();
    }
    cout<<"s1 size "<<s1.size()<<" s size "<<s.size()<<endl;


    queue<int>q;
    q.push(1);
    q.push(8);
    q.push(9);
    q.push(2);

    queue<int>q1;
    q1.swap(q);

    
    while (!q1.empty()) { 
        cout << q1.front() << " ";
        q1.pop();
    }
    cout<<endl;
    
    // priority_queue<int>q2;
    priority_queue<int,vector<int>,greater<int>>q2;
    q2.push(1);
    q2.push(8);
    q2.push(9);
    q2.push(87);
    q2.push(2);
    
    while (!q2.empty()) { 
        cout << q2.top() << " ";
        q2.pop();
    }
    cout<<endl;

    map<string,int>m;
    m["susovan"]=90;
    m["pupai"]=87;
    m["paul"]=77;
    m["apple"]=988;
    m["qww"]=9;
    m.insert({"camera",23});

    m.erase("qww");

    for(auto p: m){
        cout<<p.first<<" - "<<p.second<<endl;
    }
    cout<<m.count("paul")<<endl;

    if(m.find("qww")!=m.end()){
        cout<<"Its exist....";
    }
    else cout<<"Not Found";


    multimap<string,int>m1;
    m1.insert({"camera",3});
    m1.insert({"tv",2});
    m1.insert({"camera",38});
    m1.insert({"tv",26});
    m1.insert({"camera",43});
    m1.insert({"tv",23});
    m1.insert({"laptop",33});

    // m1.erase("tv"); // all tv key value pair ar deleted...

    for(auto p: m1){
        cout<<p.first<<" - "<<p.second<<endl;
    }

    if(m1.find("laptop")!=m.end()){
        cout<<"Its exist....";
    }
    else cout<<"Not Found";
    cout<<endl;

    int ar[] = {9,2,4,8,1,4,7};
    sort(ar,ar+7,greater<int>());

    for(int n :ar){
        cout<<n<<" ";
    }
    cout<<endl;
}
