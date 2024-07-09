#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

#include "graph/twoedgeconnectedcomponents.hpp"

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n,m;
    cin>>n>>m;
    two_edge_connected_components_graph g(n);
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.add_edge(u,v);
    }
    g.build();
    auto ans = g.groups();
    cout<<ans.size()<<endl;
    for(auto&now:ans){
        cout<<now.size();
        for(int i = 0;i<now.size();i++){
            cout<<" "<<now[i];
        }
        cout<<endl;
    }
}
