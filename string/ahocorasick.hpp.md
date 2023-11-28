---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: string/trie.hpp
    title: Trie
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/string/aho-corasick.md
    document_title: Aho-Corasick
    links: []
  bundledCode: "#line 2 \"string/ahocorasick.hpp\"\n\n#include<string/trie.hpp>\n\n\
    #include<vector>\n#include<cstring>\nusing namespace std;\n\ntemplate<int char_size,int\
    \ margin,typename T,T (*e)()>\nstruct aho_corasick:trie<char_size,margin,T,e>\
    \ {\n    vector<int> fail;\n    vector<vector<int>> match;\n    aho_corasick(){}\n\
    \n    void build(){\n        fail = vector<int>(this->size(),this->root);\n  \
    \      match = vector<vector<int>>(this->size(),vector<int>(char_size,-1));\n\
    \        vector<pair<int,int>> que;\n        vector<int> vis(this->size(),0);\n\
    \        que.push_back(make_pair(this->root,this->root));\n        vis[0] = 1;\n\
    \        for(int i = 0;i<(int)que.size();i++){\n            int ni = que[i].first;\n\
    \            int last = que[i].second;\n            int nj = this->getpar(ni);\n\
    \            if(ni!=this->root){\n                fail[ni] = match[fail[nj]][last];\n\
    \                if(fail[ni]==ni) fail[ni] = this->root;\n                for(int\
    \ j = 0;j<char_size;j++){\n                    if(this->nodes[ni].nxt[j]!=-1)\
    \ match[ni][j] = this->nodes[ni].nxt[j];\n                    else match[ni][j]\
    \ = match[fail[ni]][j];\n                }\n            }else{\n             \
    \   for(int j = 0;j<char_size;j++){\n                    if(this->nodes[ni].nxt[j]!=-1)\
    \ match[ni][j] = this->nodes[ni].nxt[j];\n                    else match[ni][j]\
    \ = ni;\n                }\n            }\n            for(int j = 0;j<char_size;j++){\n\
    \                if(this->nodes[ni].nxt[j]!=-1) que.push_back(make_pair(this->nodes[ni].nxt[j],j));\n\
    \            }\n        }\n    }\n    int move(int ni,int i,const string&s){\n\
    \        if(i==(int)s.size()) return ni;\n        return move(match[ni][s[i]-margin],i+1,s);\n\
    \    }\n    int move(int ni,const string&s){\n        return move(ni,0,s);\n \
    \   }\n    int move(int ni,const char&c){\n        string s(1,c);\n        return\
    \ move(ni,0,s);\n    }\n};\n\n/**\n * @brief Aho-Corasick\n * @docs docs/string/aho-corasick.md\n\
    */\n"
  code: "#pragma once\n\n#include<string/trie.hpp>\n\n#include<vector>\n#include<cstring>\n\
    using namespace std;\n\ntemplate<int char_size,int margin,typename T,T (*e)()>\n\
    struct aho_corasick:trie<char_size,margin,T,e> {\n    vector<int> fail;\n    vector<vector<int>>\
    \ match;\n    aho_corasick(){}\n\n    void build(){\n        fail = vector<int>(this->size(),this->root);\n\
    \        match = vector<vector<int>>(this->size(),vector<int>(char_size,-1));\n\
    \        vector<pair<int,int>> que;\n        vector<int> vis(this->size(),0);\n\
    \        que.push_back(make_pair(this->root,this->root));\n        vis[0] = 1;\n\
    \        for(int i = 0;i<(int)que.size();i++){\n            int ni = que[i].first;\n\
    \            int last = que[i].second;\n            int nj = this->getpar(ni);\n\
    \            if(ni!=this->root){\n                fail[ni] = match[fail[nj]][last];\n\
    \                if(fail[ni]==ni) fail[ni] = this->root;\n                for(int\
    \ j = 0;j<char_size;j++){\n                    if(this->nodes[ni].nxt[j]!=-1)\
    \ match[ni][j] = this->nodes[ni].nxt[j];\n                    else match[ni][j]\
    \ = match[fail[ni]][j];\n                }\n            }else{\n             \
    \   for(int j = 0;j<char_size;j++){\n                    if(this->nodes[ni].nxt[j]!=-1)\
    \ match[ni][j] = this->nodes[ni].nxt[j];\n                    else match[ni][j]\
    \ = ni;\n                }\n            }\n            for(int j = 0;j<char_size;j++){\n\
    \                if(this->nodes[ni].nxt[j]!=-1) que.push_back(make_pair(this->nodes[ni].nxt[j],j));\n\
    \            }\n        }\n    }\n    int move(int ni,int i,const string&s){\n\
    \        if(i==(int)s.size()) return ni;\n        return move(match[ni][s[i]-margin],i+1,s);\n\
    \    }\n    int move(int ni,const string&s){\n        return move(ni,0,s);\n \
    \   }\n    int move(int ni,const char&c){\n        string s(1,c);\n        return\
    \ move(ni,0,s);\n    }\n};\n\n/**\n * @brief Aho-Corasick\n * @docs docs/string/aho-corasick.md\n\
    */"
  dependsOn:
  - string/trie.hpp
  isVerificationFile: false
  path: string/ahocorasick.hpp
  requiredBy: []
  timestamp: '2023-11-28 18:38:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/ahocorasick.hpp
layout: document
redirect_from:
- /library/string/ahocorasick.hpp
- /library/string/ahocorasick.hpp.html
title: Aho-Corasick
---
