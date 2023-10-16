#define PROBLEM "https://judge.yosupo.jp/problem/nim_product_64"
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#include "math/nimber.hpp"

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int t;
    cin>>t;
    while(t--){
        unsigned long long a,b;
        cin>>a>>b;
        cout<<nimber(a)*nimber(b)<<'\n';
    }
}

