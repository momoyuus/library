---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/set_xor_min.test.cpp
    title: test/library_checker/set_xor_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: BinaryTrie
    links: []
  bundledCode: "#line 1 \"data/binarytrie.hpp\"\nusing namespace std;\n\n#include<vector>\n\
    template<typename T,int LOG = 60>\nstruct binary_trie{\n    using ull = unsigned\
    \ long long;\n    struct node{\n        int l,r;\n        T dat;\n        int\
    \ cnt;\n        node():l(-1),r(-1){\n            cnt = 0;\n        }\n    };\n\
    \n    vector<node> nodes;\n    ull lazy;\n    int root;\n\n    binary_trie(){\n\
    \        root = 0;\n        lazy = 0;\n        nodes.push_back(node());\n    }\n\
    \n    void push(int&i){\n        i = nodes.size();\n        nodes.push_back(node());\n\
    \    }\n\n    int insert(ull x){\n        int ni = root;\n        int k = LOG;\n\
    \        for(int k = LOG;k>=0;k--){\n            nodes[ni].cnt++;\n          \
    \  if(x>>k&1){\n                if(nodes[ni].r==-1) push(nodes[ni].r);\n     \
    \           ni = nodes[ni].r;\n            }else{\n                if(nodes[ni].l==-1)\
    \ push(nodes[ni].l);\n                ni = nodes[ni].l;\n            }\n     \
    \   }\n        nodes[ni].cnt++;\n        return ni;\n    }\n\n    void erase(ull\
    \ x){\n        int ni = 0;\n        int k = LOG;\n        for(int k = LOG;k>=0;k--){\n\
    \            nodes[ni].cnt--;\n            if(x>>k&1) ni = nodes[ni].r;\n    \
    \        else ni = nodes[ni].l;\n        }\n        nodes[ni].cnt--;\n    }\n\n\
    \    void xor_all(ull x){\n        lazy ^= x;\n    }\n\n    ull min_element(){\n\
    \        int ni = 0;\n        int k = LOG;\n        ull res = 0;\n        for(int\
    \ k = LOG;k>=0;k--){\n            if(lazy>>k&1){\n                if(nodes[ni].r!=-1&&nodes[nodes[ni].r].cnt>0){\n\
    \                    res += 1ull << k;\n                    ni = nodes[ni].r;\n\
    \                }else{\n                    ni = nodes[ni].l;\n             \
    \   }\n            }else{\n                if(nodes[ni].l!=-1&&nodes[nodes[ni].l].cnt>0){\n\
    \                    ni = nodes[ni].l;\n                }else{\n             \
    \       res += 1ull << k;\n                    ni = nodes[ni].r;\n           \
    \     }\n            }\n        }\n        return res^lazy;\n    }\n};\n/**\n\
    \ * @brief BinaryTrie\n*/\n"
  code: "using namespace std;\n\n#include<vector>\ntemplate<typename T,int LOG = 60>\n\
    struct binary_trie{\n    using ull = unsigned long long;\n    struct node{\n \
    \       int l,r;\n        T dat;\n        int cnt;\n        node():l(-1),r(-1){\n\
    \            cnt = 0;\n        }\n    };\n\n    vector<node> nodes;\n    ull lazy;\n\
    \    int root;\n\n    binary_trie(){\n        root = 0;\n        lazy = 0;\n \
    \       nodes.push_back(node());\n    }\n\n    void push(int&i){\n        i =\
    \ nodes.size();\n        nodes.push_back(node());\n    }\n\n    int insert(ull\
    \ x){\n        int ni = root;\n        int k = LOG;\n        for(int k = LOG;k>=0;k--){\n\
    \            nodes[ni].cnt++;\n            if(x>>k&1){\n                if(nodes[ni].r==-1)\
    \ push(nodes[ni].r);\n                ni = nodes[ni].r;\n            }else{\n\
    \                if(nodes[ni].l==-1) push(nodes[ni].l);\n                ni =\
    \ nodes[ni].l;\n            }\n        }\n        nodes[ni].cnt++;\n        return\
    \ ni;\n    }\n\n    void erase(ull x){\n        int ni = 0;\n        int k = LOG;\n\
    \        for(int k = LOG;k>=0;k--){\n            nodes[ni].cnt--;\n          \
    \  if(x>>k&1) ni = nodes[ni].r;\n            else ni = nodes[ni].l;\n        }\n\
    \        nodes[ni].cnt--;\n    }\n\n    void xor_all(ull x){\n        lazy ^=\
    \ x;\n    }\n\n    ull min_element(){\n        int ni = 0;\n        int k = LOG;\n\
    \        ull res = 0;\n        for(int k = LOG;k>=0;k--){\n            if(lazy>>k&1){\n\
    \                if(nodes[ni].r!=-1&&nodes[nodes[ni].r].cnt>0){\n            \
    \        res += 1ull << k;\n                    ni = nodes[ni].r;\n          \
    \      }else{\n                    ni = nodes[ni].l;\n                }\n    \
    \        }else{\n                if(nodes[ni].l!=-1&&nodes[nodes[ni].l].cnt>0){\n\
    \                    ni = nodes[ni].l;\n                }else{\n             \
    \       res += 1ull << k;\n                    ni = nodes[ni].r;\n           \
    \     }\n            }\n        }\n        return res^lazy;\n    }\n};\n/**\n\
    \ * @brief BinaryTrie\n*/"
  dependsOn: []
  isVerificationFile: false
  path: data/binarytrie.hpp
  requiredBy: []
  timestamp: '2023-12-15 17:45:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/set_xor_min.test.cpp
documentation_of: data/binarytrie.hpp
layout: document
redirect_from:
- /library/data/binarytrie.hpp
- /library/data/binarytrie.hpp.html
title: BinaryTrie
---
