---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data/binarytrie.hpp
    title: BinaryTrie
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/library_checker/set_xor_min.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include<iostream>\n#include<vector>\n\
    #include<algorithm>\n\nusing namespace std;\nusing ll = long long;\n\n#line 1\
    \ \"data/binarytrie.hpp\"\nusing namespace std;\n\n#line 4 \"data/binarytrie.hpp\"\
    \ntemplate<typename T,int LOG = 60>\nstruct binary_trie{\n    using ull = unsigned\
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
    \ * @brief BinaryTrie\n*/\n#line 11 \"test/library_checker/set_xor_min.test.cpp\"\
    \n\n#include<set>\nint main(){\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int q;\n    cin>>q;\n    binary_trie<int,30> trie;\n    set<int> s;\n  \
    \  while(q--){\n        int op;\n        cin>>op;\n        if(op==0){\n      \
    \      int x;\n            cin>>x;\n            if(s.count(x)==0){\n         \
    \       s.insert(x);\n                trie.insert(x);\n            }\n       \
    \ }else if(op==1){\n            int x;\n            cin>>x;\n            if(s.count(x)){\n\
    \                s.erase(x);\n                trie.erase(x);\n            }\n\
    \        }else{\n            int x;\n            cin>>x;\n            trie.xor_all(x);\n\
    \            cout<<trie.min_element()<<endl;\n            trie.xor_all(x);\n \
    \       }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include<iostream>\n\
    #include<vector>\n#include<algorithm>\n\nusing namespace std;\nusing ll = long\
    \ long;\n\n#include \"data/binarytrie.hpp\"\n\n#include<set>\nint main(){\n  \
    \  cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n    int q;\n    cin>>q;\n\
    \    binary_trie<int,30> trie;\n    set<int> s;\n    while(q--){\n        int\
    \ op;\n        cin>>op;\n        if(op==0){\n            int x;\n            cin>>x;\n\
    \            if(s.count(x)==0){\n                s.insert(x);\n              \
    \  trie.insert(x);\n            }\n        }else if(op==1){\n            int x;\n\
    \            cin>>x;\n            if(s.count(x)){\n                s.erase(x);\n\
    \                trie.erase(x);\n            }\n        }else{\n            int\
    \ x;\n            cin>>x;\n            trie.xor_all(x);\n            cout<<trie.min_element()<<endl;\n\
    \            trie.xor_all(x);\n        }\n    }\n}\n"
  dependsOn:
  - data/binarytrie.hpp
  isVerificationFile: true
  path: test/library_checker/set_xor_min.test.cpp
  requiredBy: []
  timestamp: '2023-12-17 04:36:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/set_xor_min.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/set_xor_min.test.cpp
- /verify/test/library_checker/set_xor_min.test.cpp.html
title: test/library_checker/set_xor_min.test.cpp
---
