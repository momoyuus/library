#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#include "data/lichaotree.hpp"

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n,q;
    cin>>n>>q;
    dynamic_li_chao_tree<ll> li(-1e9,1e9,9e18);
    for(int i = 0;i<n;i++){
        ll l,r,a,b;
        cin>>l>>r>>a>>b;
        li.add_line(l,r,a,b);
    }
    while(q--){
        int op;
        cin>>op;
        if(op==0){
            ll l,r,a,b;
            cin>>l>>r>>a>>b;
            li.add_line(l,r,a,b);
        }else{
            ll p;
            cin>>p;
            ll ans = li.query(p);
            if(ans==9e18) cout<<"INFINITY"<<endl;
            else cout<<li.query(p)<<endl;
        }
    }
}

