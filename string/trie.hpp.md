---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/string/trie.hpp
    document_title: Trie
    links: []
  bundledCode: "#line 1 \"string/trie.hpp\"\n#include<vector>\n#include<string>\n\
    using namespace std;\n\ntemplate<int char_size,char margin,typename T,T (*e)()>\n\
    struct trie{\n    struct node{\n        int nxt[char_size];\n        int par;\n\
    \        T dat;\n        node(int p):par(p){\n            memset(nxt,-1,sizeof(nxt));\n\
    \            dat = e();\n        }\n    };\n\n    vector<node> nodes;\n    int\
    \ root;\n    trie(){\n        root = 0;\n        nodes.push_back(node(-1));\n\
    \    }\n\n    int add(int ni,int i,const string&s){\n        if(i==(int)s.size())\
    \ return ni;\n        int now = s[i] - margin;\n        if(nodes[ni].nxt[now]==-1){\n\
    \            nodes[ni].nxt[now] = nodes.size();\n            nodes.push_back(node(ni));\n\
    \        }\n        return add(nodes[ni].nxt[now],i+1,s);\n    }\n\n    int add(const\
    \ string&s){\n        return add(root,0,s);\n    }\n\n    int move(int ni,int\
    \ i,const string&s){\n        if(i==(int)s.size()) return ni;\n        if(ni==-1)\
    \ return ni;\n        int now = s[i] - margin;\n        return move(nodes[ni].nxt[now],i+1,s);\n\
    \    }\n\n    int move(int ni,const string&s){\n        return move(ni,0,s);\n\
    \    }\n\n    int move(int ni,const char&c){\n        string s(1,c);\n       \
    \ return move(ni,0,s);\n    }\n\n    int getpar(int ni){\n        return nodes[ni].par;\n\
    \    }\n\n    inline T& operator[](int i) {\n        return nodes[i].dat;\n  \
    \  }\n\n    inline int size(){\n        return nodes.size();\n    }\n};\n\n/**\n\
    \ * @brief Trie\n * @docs docs/string/trie.hpp\n*/\n"
  code: "#include<vector>\n#include<string>\nusing namespace std;\n\ntemplate<int\
    \ char_size,char margin,typename T,T (*e)()>\nstruct trie{\n    struct node{\n\
    \        int nxt[char_size];\n        int par;\n        T dat;\n        node(int\
    \ p):par(p){\n            memset(nxt,-1,sizeof(nxt));\n            dat = e();\n\
    \        }\n    };\n\n    vector<node> nodes;\n    int root;\n    trie(){\n  \
    \      root = 0;\n        nodes.push_back(node(-1));\n    }\n\n    int add(int\
    \ ni,int i,const string&s){\n        if(i==(int)s.size()) return ni;\n       \
    \ int now = s[i] - margin;\n        if(nodes[ni].nxt[now]==-1){\n            nodes[ni].nxt[now]\
    \ = nodes.size();\n            nodes.push_back(node(ni));\n        }\n       \
    \ return add(nodes[ni].nxt[now],i+1,s);\n    }\n\n    int add(const string&s){\n\
    \        return add(root,0,s);\n    }\n\n    int move(int ni,int i,const string&s){\n\
    \        if(i==(int)s.size()) return ni;\n        if(ni==-1) return ni;\n    \
    \    int now = s[i] - margin;\n        return move(nodes[ni].nxt[now],i+1,s);\n\
    \    }\n\n    int move(int ni,const string&s){\n        return move(ni,0,s);\n\
    \    }\n\n    int move(int ni,const char&c){\n        string s(1,c);\n       \
    \ return move(ni,0,s);\n    }\n\n    int getpar(int ni){\n        return nodes[ni].par;\n\
    \    }\n\n    inline T& operator[](int i) {\n        return nodes[i].dat;\n  \
    \  }\n\n    inline int size(){\n        return nodes.size();\n    }\n};\n\n/**\n\
    \ * @brief Trie\n * @docs docs/string/trie.hpp\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.hpp
  requiredBy: []
  timestamp: '2023-11-28 17:35:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/trie.hpp
layout: document
redirect_from:
- /library/string/trie.hpp
- /library/string/trie.hpp.html
title: Trie
---
