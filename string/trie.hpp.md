---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: string/ahocorasick.hpp
    title: Aho-Corasick
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/string/trie.md
    document_title: Trie
    links: []
  bundledCode: "#line 2 \"string/trie.hpp\"\n\n#include<vector>\n#include<string>\n\
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
    \ * @brief Trie\n * @docs docs/string/trie.md\n*/\n"
  code: "#pragma once\n\n#include<vector>\n#include<string>\nusing namespace std;\n\
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
    \ * @brief Trie\n * @docs docs/string/trie.md\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.hpp
  requiredBy:
  - string/ahocorasick.hpp
  timestamp: '2023-11-28 18:38:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/trie.hpp
layout: document
redirect_from:
- /library/string/trie.hpp
- /library/string/trie.hpp.html
title: Trie
---
## Trie

#### 概要

文字列の prefix を木状に管理するデータ構造。頂点 0 は根を表す。

#### 使い方
##### コンストラクタ
`trie<char_size,margin,T,e> t`
- char_size：文字の種類数
- margin：0番目の文字
- T：ノードに乗せるデータ型
- e：ノードのデータの初期値を返す関数

例：`trie<26,'A',int,e> t`

##### 文字の追加
`int t.add(string s)`<br>
Trie に文字列 S を追加する。末端のノードの番号を返す。
###### 計算量
$O(|S|)$

##### 頂点の移動
`int t.move(int u,string s)`<br>
`int t.move(int u,char c)`<br>
頂点 u から、文字列 s\(c\) だけ進んだ場所にある頂点を返す。存在しないときは -1 を返す。
###### 計算量
$O(|S|)$

##### その他
`int t.getpar(int u)`：頂点 u の親を返す。 u が根の場合は -1 を返す。<br>
`int t.size()`：現在の頂点数を返す。根のノードも個数に含まれる。<br>
`T t[u]`：頂点 u の現在の値を返す。代入も可。<br>