#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include<iostream>
using namespace std;
using ll = long long;

#include "data/swag.hpp"

const ll mod = 998244353;
ll add(ll x,ll y){
    ll res = x + y;
    if(res>=mod) return res - mod;
    return res;
}
ll product(ll x,ll y){
    return (x*y)%mod;
}

using dat = pair<ll,ll>;
dat op(dat a,dat b){
    return make_pair(product(a.first,b.first),add(product(b.first,a.second),b.second));
}

dat e(){
    return make_pair(1,0);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    swag<dat,op,e> sw;
    int q;
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        if(t==0){
            int a,b;
            cin>>a>>b;
            sw.push_front(make_pair(a,b));
        }else if(t==1){
            sw.pop_front();
        }else{
            int x;
            cin>>x;
            dat now = sw.all_prod();
            int ans = add(product(now.first,x),now.second);
            cout<<ans<<endl;
        }
    }
}
