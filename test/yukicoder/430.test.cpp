#define PROBLEM "https://yukicoder.me/problems/no/430"

#include<algorithm>
#include<iostream>
#include<vector>
#include<cassert>

#include "string/ahocorasick.hpp"

using namespace std;
using ll = long long;
int e(){
    return 0;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    aho_corasick<26,'A',int,e> t;
    string s;
    cin>>s;
    int m;
    cin>>m;
    for(int i = 0;i<m;i++){
        string c;
        cin>>c;
        int ni = t.add(c);
        t[ni]++;
    }
    t.build();
    vector<ll> cnt(t.size(),0);
    for(int i:t.getbfs()) cnt[i] += cnt[t.fail[i]] + t[i];
    ll ans = 0;
    int ni = 0;
    for(int i = 0;i<s.size();i++){
        ni = t.move(ni,s[i]);
        ans += cnt[ni];
    }
    cout<<ans<<endl;
}
