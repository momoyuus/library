---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/trie.hpp
    title: Trie
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/430.test.cpp
    title: test/yukicoder/430.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/string/ahocorasick.md
    document_title: Aho-Corasick
    links: []
  bundledCode: "#line 2 \"string/ahocorasick.hpp\"\n\n#line 2 \"string/trie.hpp\"\n\
    \n#include<vector>\n#include<string>\n#include<cstring>\nusing namespace std;\n\
    \ntemplate<int char_size,char margin,typename T,T (*e)()>\nstruct trie{\n    struct\
    \ node{\n        int nxt[char_size];\n        int par;\n        T dat;\n     \
    \   node(int p):par(p){\n            memset(nxt,-1,sizeof(nxt));\n           \
    \ dat = e();\n        }\n    };\n\n    vector<node> nodes;\n    int root;\n  \
    \  trie(){\n        root = 0;\n        nodes.push_back(node(-1));\n    }\n\n \
    \   int add(int ni,int i,const string&s){\n        if(i==(int)s.size()) return\
    \ ni;\n        int now = s[i] - margin;\n        if(nodes[ni].nxt[now]==-1){\n\
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
    \ * @brief Trie\n * @docs docs/string/trie.md\n*/\n#line 4 \"string/ahocorasick.hpp\"\
    \n\n#line 7 \"string/ahocorasick.hpp\"\nusing namespace std;\n\ntemplate<int char_size,int\
    \ margin,typename T,T (*e)()>\nstruct aho_corasick:trie<char_size,margin,T,e>\
    \ {\n    vector<int> fail;\n    vector<vector<int>> match;\n    vector<int> bfs;\n\
    \    aho_corasick(){}\n\n    void build(){\n        fail = vector<int>(this->size(),this->root);\n\
    \        match = vector<vector<int>>(this->size(),vector<int>(char_size,-1));\n\
    \        vector<pair<int,int>> que;\n        vector<int> vis(this->size(),0);\n\
    \        que.push_back(make_pair(this->root,this->root));\n        vis[0] = 1;\n\
    \        for(int i = 0;i<(int)que.size();i++){\n            int ni = que[i].first;\n\
    \            bfs.push_back(ni);\n            int last = que[i].second;\n     \
    \       int nj = this->getpar(ni);\n            if(ni!=this->root){\n        \
    \        fail[ni] = match[fail[nj]][last];\n                if(fail[ni]==ni) fail[ni]\
    \ = this->root;\n                for(int j = 0;j<char_size;j++){\n           \
    \         if(this->nodes[ni].nxt[j]!=-1) match[ni][j] = this->nodes[ni].nxt[j];\n\
    \                    else match[ni][j] = match[fail[ni]][j];\n               \
    \ }\n            }else{\n                for(int j = 0;j<char_size;j++){\n   \
    \                 if(this->nodes[ni].nxt[j]!=-1) match[ni][j] = this->nodes[ni].nxt[j];\n\
    \                    else match[ni][j] = ni;\n                }\n            }\n\
    \            for(int j = 0;j<char_size;j++){\n                if(this->nodes[ni].nxt[j]!=-1)\
    \ que.push_back(make_pair(this->nodes[ni].nxt[j],j));\n            }\n       \
    \ }\n    }\n    int move(int ni,int i,const string&s){\n        if(i==(int)s.size())\
    \ return ni;\n        return move(match[ni][s[i]-margin],i+1,s);\n    }\n    int\
    \ move(int ni,const string&s){\n        return move(ni,0,s);\n    }\n    int move(int\
    \ ni,const char&c){\n        string s(1,c);\n        return move(ni,0,s);\n  \
    \  }\n    int getfail(int ni){\n        return fail[ni];\n    }\n    vector<int>\
    \ getbfs(){\n        return bfs;\n    }\n};\n\n/**\n * @brief Aho-Corasick\n *\
    \ @docs docs/string/ahocorasick.md\n*/\n"
  code: "#pragma once\n\n#include\"string/trie.hpp\"\n\n#include<vector>\n#include<cstring>\n\
    using namespace std;\n\ntemplate<int char_size,int margin,typename T,T (*e)()>\n\
    struct aho_corasick:trie<char_size,margin,T,e> {\n    vector<int> fail;\n    vector<vector<int>>\
    \ match;\n    vector<int> bfs;\n    aho_corasick(){}\n\n    void build(){\n  \
    \      fail = vector<int>(this->size(),this->root);\n        match = vector<vector<int>>(this->size(),vector<int>(char_size,-1));\n\
    \        vector<pair<int,int>> que;\n        vector<int> vis(this->size(),0);\n\
    \        que.push_back(make_pair(this->root,this->root));\n        vis[0] = 1;\n\
    \        for(int i = 0;i<(int)que.size();i++){\n            int ni = que[i].first;\n\
    \            bfs.push_back(ni);\n            int last = que[i].second;\n     \
    \       int nj = this->getpar(ni);\n            if(ni!=this->root){\n        \
    \        fail[ni] = match[fail[nj]][last];\n                if(fail[ni]==ni) fail[ni]\
    \ = this->root;\n                for(int j = 0;j<char_size;j++){\n           \
    \         if(this->nodes[ni].nxt[j]!=-1) match[ni][j] = this->nodes[ni].nxt[j];\n\
    \                    else match[ni][j] = match[fail[ni]][j];\n               \
    \ }\n            }else{\n                for(int j = 0;j<char_size;j++){\n   \
    \                 if(this->nodes[ni].nxt[j]!=-1) match[ni][j] = this->nodes[ni].nxt[j];\n\
    \                    else match[ni][j] = ni;\n                }\n            }\n\
    \            for(int j = 0;j<char_size;j++){\n                if(this->nodes[ni].nxt[j]!=-1)\
    \ que.push_back(make_pair(this->nodes[ni].nxt[j],j));\n            }\n       \
    \ }\n    }\n    int move(int ni,int i,const string&s){\n        if(i==(int)s.size())\
    \ return ni;\n        return move(match[ni][s[i]-margin],i+1,s);\n    }\n    int\
    \ move(int ni,const string&s){\n        return move(ni,0,s);\n    }\n    int move(int\
    \ ni,const char&c){\n        string s(1,c);\n        return move(ni,0,s);\n  \
    \  }\n    int getfail(int ni){\n        return fail[ni];\n    }\n    vector<int>\
    \ getbfs(){\n        return bfs;\n    }\n};\n\n/**\n * @brief Aho-Corasick\n *\
    \ @docs docs/string/ahocorasick.md\n*/"
  dependsOn:
  - string/trie.hpp
  isVerificationFile: false
  path: string/ahocorasick.hpp
  requiredBy: []
  timestamp: '2023-11-28 19:13:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/430.test.cpp
documentation_of: string/ahocorasick.hpp
layout: document
redirect_from:
- /library/string/ahocorasick.hpp
- /library/string/ahocorasick.hpp.html
title: Aho-Corasick
---
## Aho-Corasick

#### 概要

文字列の prefix を木状に管理するデータ構造。頂点 0 は根を表す。遷移失敗時の動きが Trie 木と異なる。

#### 使い方
##### コンストラクタ
`aho_corasick<char_size,margin,T,e> t`<br>
- char_size：文字の種類数
- margin：0番目の文字
- T：ノードに乗せるデータ型
- e：ノードのデータの初期値を返す関数

例：`aho_corasick<26,'A',int,e> t`

##### 文字の追加
`int t.add(string s)`<br>
Trie に文字列 S を追加する。末端のノードの番号を返す。
###### 計算量
$O(|S|)$

##### 構築
`void t.build()`<br>
Aho-Corasick を構築する。
###### 計算量
$O(\sigma \sum |S|)$ ($\sigma =$ char_size)

##### 頂点の移動
`int t.move(int u,string s)`<br>
`int t.move(int u,char c)`<br>
頂点 u から、文字列 s\(c\) だけ進んだ場所にある頂点を返す。
###### 計算量
$O(|S|)$

##### その他
`int t.getpar(int u)`：頂点 u の親を返す。 u が根の場合は -1 を返す。<br>
`int t.getfail(int u)`：頂点 u の遷移失敗時の頂点を返す。<br>
`vector<int> t.getbfs()`：構築時の BFS 順を返す。<br>
`int t.size()`：現在の頂点数を返す。根のノードも個数に含まれる。<br>
`T t[u]`：頂点 u の現在の値を返す。代入も可。
