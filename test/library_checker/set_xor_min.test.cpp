#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

#include "data/binarytrie.hpp"

#include<set>
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin>>q;
    binary_trie<int,30> trie;
    set<int> s;
    while(q--){
        int op;
        cin>>op;
        if(op==0){
            int x;
            cin>>x;
            if(s.count(x)==0){
                s.insert(x);
                trie.insert(x);
            }
        }else if(op==1){
            int x;
            cin>>x;
            if(s.count(x)){
                s.erase(x);
                trie.erase(x);
            }
        }else{
            int x;
            cin>>x;
            trie.xor_all(x);
            cout<<trie.min_element()<<endl;
            trie.xor_all(x);
        }
    }
}
