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
    \  return res;\n    }\n};\n/**\n * @brief Two-Edge-Connected Components\n*/\n"
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
    \  return res;\n    }\n};\n/**\n * @brief Two-Edge-Connected Components\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/twoedgeconnectedcomponents.hpp
  requiredBy: []
  timestamp: '2023-12-21 14:35:59+09:00'
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
