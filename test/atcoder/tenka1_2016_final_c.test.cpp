#define PROBLEM "https://atcoder.jp/contests/tenka1-2016-final/tasks/tenka1_2016_final_c"
#include<algorithm>
#include<iostream>
#include<vector>
#include<cassert>

using namespace std;
using ll = long long;

#include<string/trie>

ll e(){
    return 0;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    trie<26,'a',ll,e> t;
    string s;
    cin>>s;
    int m;
    cin>>m;
    vector<string> ss(m);
    vector<ll> w(m);
    for(int i = 0;i<m;i++) cin>>ss[i];
    for(int i = 0;i<m;i++) cin>>w[i];
    for(int i = 0;i<m;i++){
        int ni = t.add(ss[i]);
        t[ni] = max(t[ni],w[i]);
    }
    int n = s.size();
    const int len = 200;
    vector<ll> dp(n+1,0);
    for(int i = 0;i<n;i++){
        dp[i+1] = max(dp[i+1],dp[i]);
        int ni = 0;
        for(int j = 0;j<len;j++){
            int nj = i + j;
            if(nj>=s.size()) break;
            ni = t.move(ni,s[nj]);
            if(ni==-1) break;
            dp[nj+1] = max(dp[nj+1],dp[i]+t[ni]);
        }
    }
    cout<<dp[n]<<endl;

}

