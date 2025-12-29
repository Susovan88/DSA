#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

// leetcode- 1657
bool closeStrings(string word1, string word2) {
    if(word1.size()!=word2.size())return false;
    unordered_map<char,int>box1,box2; // char -> feq
    unordered_map<int,int>feq1,feq2; // feq -> count

    for(int i=0;i<word1.size();i++){
        box1[word1[i]]++;
        box2[word2[i]]++;
    }

    for(auto ele : box1){
        if(box2.find(ele.first)==box2.end()) return false;
        feq1[ele.second]++;
    }
    for(auto ele : box2){
        if(box1.find(ele.first)==box1.end()) return false;
        feq2[ele.second]++;
    }

    return feq1==feq2;
}

int main() {
    string word1, word2;

    cout << "Enter first word: ";
    cin >> word1;

    cout << "Enter second word: ";
    cin >> word2;

    if (closeStrings(word1, word2)) {
        cout << "True (Strings are Close)" << endl;
    } else {
        cout << "False (Strings are NOT Close)" << endl;
    }

    return 0;
}
