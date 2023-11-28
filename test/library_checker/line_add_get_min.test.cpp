#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#include "data/dynamiclichaotree.hpp"

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n,q;
    cin>>n>>q;
    dynamic_li_chao_tree<ll> li(-1e9,1e9,9e18);
    for(int i = 0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        li.add_line(a,b);
    }
    while(q--){
        int op;
        cin>>op;
        if(op==0){
            ll a,b;
            cin>>a>>b;
            li.add_line(a,b);
        }else{
            ll p;
            cin>>p;
            cout<<li.query(p)<<endl;
        }
    }
}

