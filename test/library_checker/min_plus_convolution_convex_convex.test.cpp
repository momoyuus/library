#define PROBLEM "https://judge.yosupo.jp/problem/nim_product_64"
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#include "math/minplusconvolutionconvex.hpp"

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n,m;
    cin>>n>>m;
    vector<ll> a(n),b(m);
    for(int i = 0;i<n;i++) cin>>a[i];
    for(int i = 0;i<m;i++) cin>>b[i];
    auto ans = min_plus_convolution(a,b);
    for(int i = 0;i<ans.size();i++){
        if(i) cout<<' ';
        cout<<ans[i];
    }
    cout<<'\n';
}

