#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

#include "hash/rollinghash.hpp"

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin>>s;
    rhash rh(s);
    for(int i = 0;i<s.size();i++){
        if(i) cout<<" ";
        cout<<rh.lcp(0,i);
    }
    cout<<endl;
}
