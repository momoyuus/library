#define PROBLEM "https://yukicoder.me/problems/no/1269"

#include "string/ahocorasick.hpp"

#include<algorithm>
#include<iostream>
#include<vector>
#include<cassert>

using namespace std;
using ll = long long;
int e(){
    return 0;
}

const ll mod = 1000000007;
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    aho_corasick<10,'0',int,e> t;
    ll n,l,r;
    cin>>n>>l>>r;

    vector<ll> fib(100,1);
    for(int i = 0;i<100;i++){
        if(i-2>=0) fib[i] = fib[i-1] + fib[i-2];
        if(r<fib[i]) break;
        if(l>fib[i]) continue;
        int ni = t.add(to_string(fib[i]));
        t[ni] = 1;
    }
    t.build();
    vector<int> no(t.size(),0);
    for(int i:t.getbfs()) no[i] = t[i] | no[t.fail[i]];
    vector<vector<ll>> dp(n+1,vector<ll>(t.size(),0));
    dp[0][0] = 1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<t.size();j++){
            for(int k = 0;k<10;k++){
                int nxt = t.move(j,'0'+k);
                if(no[nxt]==0) dp[i+1][nxt] = (dp[i+1][nxt]+dp[i][j])%mod;
            }
        }
    }
    ll ans = 0;
    for(int i = 0;i<t.size();i++) ans = (ans+dp[n][i])%mod;
    ans = (ans+mod-1)%mod;
    cout<<ans<<endl;
}
