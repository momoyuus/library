#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

template<typename T>
struct cumsum{
    int n;
    vector<T> dat;
    cumsum(){}
    cumsum(const vector<T>a):n(a.size()),dat(a.size()+1,0){
        for(int i = 0;i<n;i++) dat[i+1] = dat[i] + a[i];
    }
    
    T sum(int l,int r){
        return dat[r] - dat[l];
    }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
     int n,q;
     cin>>n>>q;
     vector<ll> a(n);
     for(int i = 0;i<n;i++) cin>>a[i];
     cumsum<ll> sum(a);
     for(int i = 0;i<q;i++){
         int l,r;
         cin>>l>>r;
         cout<<sum.sum(l,r)<<endl;
     }

}

