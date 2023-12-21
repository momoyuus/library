---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/two_edge_connected_components.test.cpp
    title: test/library_checker/two_edge_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/twoedgeconnectedcomponents.md
    document_title: Two-Edge-Connected Components
    links: []
  bundledCode: "#line 1 \"graph/twoedgeconnectedcomponents.hpp\"\nusing namespace\
    \ std;\n\n#include<vector>\n#include<cassert>\nstruct two_edge_connected_components_graph{\n\
    \    struct edge{\n        int to,id;\n        edge(){}\n        edge(int _to,int\
    \ _id):to(_to),id(_id){\n\n        }\n    };\n\n    int n,cnt,now;\n    vector<vector<edge>>\
    \ g;\n    vector<int> cmp;\n    vector<vector<int>> G;\n    two_edge_connected_components_graph(int\
    \ _n):n(_n){\n        cnt = 0;\n        now = 0;\n        g.resize(n);\n     \
    \   cmp.resize(n);\n    }\n    \n    void add_edge(int u,int v){\n        assert(0<=u&&u<n);\n\
    \        assert(0<=v&&v<n);\n        g[u].push_back({v,cnt});\n        g[v].push_back({u,cnt});\n\
    \        cnt++;\n    }\n\n    void build(){\n        vector<int> vis(n,0),use(cnt,0),ord(n,-1),low(n,1e9);\n\
    \        auto dfs = [&](auto dfs,int ni) -> void {\n            vis[ni] = 1;\n\
    \            for(auto&e:g[ni]){\n                if(use[e.id]) continue;\n   \
    \             if(vis[e.to]) {\n                    use[e.id] = 2;\n          \
    \          low[ni] = min(low[ni],ord[e.to]);\n                }else{\n       \
    \             use[e.id] = 1;\n                    ord[e.to] = low[e.to] = ord[ni]\
    \ + 1;\n                    dfs(dfs,e.to);\n                    low[ni] = min(low[ni],low[e.to]);\n\
    \                }\n            }\n        };\n\n        auto compress = [&](auto\
    \ compress,int ni,int t) -> void {\n            if(G.size()>=t) G.push_back(vector<int>(0));\n\
    \            G[t].push_back(ni);\n            cmp[ni] = t;\n            for(auto&e:g[ni])\
    \ if(use[e.id]==1&&ord[e.to]>ord[ni]){\n                if(ord[ni]<low[e.to])\
    \ compress(compress,e.to,now++);\n                else compress(compress,e.to,cmp[ni]);\n\
    \            }\n        };\n        \n        for(int i = 0;i<n;i++) if(vis[i]==0){\n\
    \            ord[i] = low[i] = 0;\n            dfs(dfs,i);\n            compress(compress,i,now++);\n\
    \        }\n    }\n\n    int operator[] (int u){\n        assert(0<=u&&u<n);\n\
    \        return cmp[u];\n    }\n\n    vector<vector<int>> graph(){\n        return\
    \ G;\n    }\n\n    vector<vector<int>> groups(){\n        vector<vector<int>>\
    \ res(now);\n        for(int i = 0;i<n;i++) res[cmp[i]].push_back(i);\n      \
    \  return res;\n    }\n\n    pair<vector<int>,vector<int>> two_way(int ni,int\
    \ nj){\n        assert(0<=ni&&ni<n);\n        assert(0<=nj&&nj<n);\n        assert(ni!=nj);\n\
    \n        vector<int> a,b;\n        if(cmp[ni]!=cmp[nj]){\n            a.push_back(-1);\n\
    \            b.push_back(-1);\n            return make_pair(a,b);\n        }\n\
    \        vector<int> bfs;\n        bfs.push_back(nj);\n        vector<int> vis(n,1e9);\n\
    \        vis[nj] = 0;\n        for(int i = 0;i<(int)bfs.size();i++){\n       \
    \     for(auto&e:g[bfs[i]]){\n                if(cmp[e.to]!=cmp[nj]) continue;\n\
    \                if(vis[e.to]<=vis[bfs[i]]+1) continue;\n                vis[e.to]\
    \ = vis[bfs[i]] + 1;\n                bfs.push_back(e.to);\n            }\n  \
    \      }\n        int nni = ni;\n        vector<int> use(cnt,0);\n        while(nni!=nj){\n\
    \            for(auto&e:g[nni]){\n                if(cmp[e.to]!=cmp[nj]) continue;\n\
    \                if(vis[e.to]==vis[nni]-1){\n                    nni = e.to;\n\
    \                    a.push_back(e.id);\n                    use[e.id] = 1;\n\
    \                    break;\n                }\n            }\n        }\n   \
    \     bfs.clear();\n        bfs.push_back(nj);\n        for(int i = 0;i<n;i++)\
    \ vis[i] = 1e9;\n        vis[nj] = 0;\n        for(int i = 0;i<(int)bfs.size();i++){\n\
    \            for(auto&e:g[bfs[i]]){\n                if(cmp[e.to]!=cmp[nj]) continue;\n\
    \                if(vis[e.to]<=vis[bfs[i]]+1) continue;\n                if(use[e.id])\
    \ continue;\n                vis[e.to] = vis[bfs[i]] + 1;\n                bfs.push_back(e.to);\n\
    \            }\n        }\n        nni = ni;\n        while(nni!=nj){\n      \
    \      for(auto&e:g[nni]){\n                if(cmp[e.to]!=cmp[nj]) continue;\n\
    \                if(vis[e.to]==vis[nni]-1){\n                    nni = e.to;\n\
    \                    b.push_back(e.id);\n                    use[e.id] = 1;\n\
    \                    break;\n                }\n            }\n        }\n   \
    \     return make_pair(a,b);\n    }\n};\n/**\n * @brief Two-Edge-Connected Components\n\
    \ * @docs docs/graph/twoedgeconnectedcomponents.md\n*/\n"
  code: "using namespace std;\n\n#include<vector>\n#include<cassert>\nstruct two_edge_connected_components_graph{\n\
    \    struct edge{\n        int to,id;\n        edge(){}\n        edge(int _to,int\
    \ _id):to(_to),id(_id){\n\n        }\n    };\n\n    int n,cnt,now;\n    vector<vector<edge>>\
    \ g;\n    vector<int> cmp;\n    vector<vector<int>> G;\n    two_edge_connected_components_graph(int\
    \ _n):n(_n){\n        cnt = 0;\n        now = 0;\n        g.resize(n);\n     \
    \   cmp.resize(n);\n    }\n    \n    void add_edge(int u,int v){\n        assert(0<=u&&u<n);\n\
    \        assert(0<=v&&v<n);\n        g[u].push_back({v,cnt});\n        g[v].push_back({u,cnt});\n\
    \        cnt++;\n    }\n\n    void build(){\n        vector<int> vis(n,0),use(cnt,0),ord(n,-1),low(n,1e9);\n\
    \        auto dfs = [&](auto dfs,int ni) -> void {\n            vis[ni] = 1;\n\
    \            for(auto&e:g[ni]){\n                if(use[e.id]) continue;\n   \
    \             if(vis[e.to]) {\n                    use[e.id] = 2;\n          \
    \          low[ni] = min(low[ni],ord[e.to]);\n                }else{\n       \
    \             use[e.id] = 1;\n                    ord[e.to] = low[e.to] = ord[ni]\
    \ + 1;\n                    dfs(dfs,e.to);\n                    low[ni] = min(low[ni],low[e.to]);\n\
    \                }\n            }\n        };\n\n        auto compress = [&](auto\
    \ compress,int ni,int t) -> void {\n            if(G.size()>=t) G.push_back(vector<int>(0));\n\
    \            G[t].push_back(ni);\n            cmp[ni] = t;\n            for(auto&e:g[ni])\
    \ if(use[e.id]==1&&ord[e.to]>ord[ni]){\n                if(ord[ni]<low[e.to])\
    \ compress(compress,e.to,now++);\n                else compress(compress,e.to,cmp[ni]);\n\
    \            }\n        };\n        \n        for(int i = 0;i<n;i++) if(vis[i]==0){\n\
    \            ord[i] = low[i] = 0;\n            dfs(dfs,i);\n            compress(compress,i,now++);\n\
    \        }\n    }\n\n    int operator[] (int u){\n        assert(0<=u&&u<n);\n\
    \        return cmp[u];\n    }\n\n    vector<vector<int>> graph(){\n        return\
    \ G;\n    }\n\n    vector<vector<int>> groups(){\n        vector<vector<int>>\
    \ res(now);\n        for(int i = 0;i<n;i++) res[cmp[i]].push_back(i);\n      \
    \  return res;\n    }\n\n    pair<vector<int>,vector<int>> two_way(int ni,int\
    \ nj){\n        assert(0<=ni&&ni<n);\n        assert(0<=nj&&nj<n);\n        assert(ni!=nj);\n\
    \n        vector<int> a,b;\n        if(cmp[ni]!=cmp[nj]){\n            a.push_back(-1);\n\
    \            b.push_back(-1);\n            return make_pair(a,b);\n        }\n\
    \        vector<int> bfs;\n        bfs.push_back(nj);\n        vector<int> vis(n,1e9);\n\
    \        vis[nj] = 0;\n        for(int i = 0;i<(int)bfs.size();i++){\n       \
    \     for(auto&e:g[bfs[i]]){\n                if(cmp[e.to]!=cmp[nj]) continue;\n\
    \                if(vis[e.to]<=vis[bfs[i]]+1) continue;\n                vis[e.to]\
    \ = vis[bfs[i]] + 1;\n                bfs.push_back(e.to);\n            }\n  \
    \      }\n        int nni = ni;\n        vector<int> use(cnt,0);\n        while(nni!=nj){\n\
    \            for(auto&e:g[nni]){\n                if(cmp[e.to]!=cmp[nj]) continue;\n\
    \                if(vis[e.to]==vis[nni]-1){\n                    nni = e.to;\n\
    \                    a.push_back(e.id);\n                    use[e.id] = 1;\n\
    \                    break;\n                }\n            }\n        }\n   \
    \     bfs.clear();\n        bfs.push_back(nj);\n        for(int i = 0;i<n;i++)\
    \ vis[i] = 1e9;\n        vis[nj] = 0;\n        for(int i = 0;i<(int)bfs.size();i++){\n\
    \            for(auto&e:g[bfs[i]]){\n                if(cmp[e.to]!=cmp[nj]) continue;\n\
    \                if(vis[e.to]<=vis[bfs[i]]+1) continue;\n                if(use[e.id])\
    \ continue;\n                vis[e.to] = vis[bfs[i]] + 1;\n                bfs.push_back(e.to);\n\
    \            }\n        }\n        nni = ni;\n        while(nni!=nj){\n      \
    \      for(auto&e:g[nni]){\n                if(cmp[e.to]!=cmp[nj]) continue;\n\
    \                if(vis[e.to]==vis[nni]-1){\n                    nni = e.to;\n\
    \                    b.push_back(e.id);\n                    use[e.id] = 1;\n\
    \                    break;\n                }\n            }\n        }\n   \
    \     return make_pair(a,b);\n    }\n};\n/**\n * @brief Two-Edge-Connected Components\n\
    \ * @docs docs/graph/twoedgeconnectedcomponents.md\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/twoedgeconnectedcomponents.hpp
  requiredBy: []
  timestamp: '2023-12-21 19:33:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/two_edge_connected_components.test.cpp
documentation_of: graph/twoedgeconnectedcomponents.hpp
layout: document
redirect_from:
- /library/graph/twoedgeconnectedcomponents.hpp
- /library/graph/twoedgeconnectedcomponents.hpp.html
title: Two-Edge-Connected Components
---
## Two-Edge-Connected Components

#### 概要

グラフを二辺連結成分分解するライブラリ。

#### 使い方
##### コンストラクタ
`two_edge_connected_components_graph g(n)`<br>
$n$ 頂点のグラフを作成する。

##### 辺の追加
`void g.add_edge(u,v)`<br>
$uv$ 間に辺を貼る。

###### 計算量
$O(1)$

##### 構築
`void g.build()`<br>
二辺連結成分分解を行う。これ以降のメソッドは build が呼ばれた後に呼ばれることが想定されている。
###### 計算量
$O(n + m)$ ($m =$ 追加した辺の数)

##### 成分の列挙
`vector<vector<int>> g.groups()`<br>
二辺連結成分ごとに頂点を分割した vector を返す。
###### 計算量
$O(n)$

##### 成分を縮約したグラフ
`vector<vector<int>> g.graph()`<br>
二辺連結成分を縮約したグラフを返す。
###### 計算量
$O(1)$

##### 辺素なパスの構築
`pair<vector<int>,vector<int>> g.two_way(int u,int v)`<br>
頂点 u から頂点 v への辺素なパスを 2 つ返す。ただし、頂点 u と頂点 v が同じ成分内に含まれないときは -1 が格納された vector を 2 つ返す。パスは辺の番号の列で表され、始点が u 、終点が v となっている。辺の番号は辺を追加した順に 0,1,...,m となる。<br>
[https://codeforces.com/gym/104871/problem/K](https://codeforces.com/gym/104871/problem/K)

###### 計算量
$O(n+m)$

##### その他
`int g[u]`：頂点 u の縮約後の頂点番号を返す。<br>

