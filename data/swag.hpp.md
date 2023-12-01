---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/deque_operate_all_composite.test.cpp
    title: test/library_checker/deque_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/queue_operate_all_composite.test.cpp
    title: test/library_checker/queue_operate_all_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data/swag.md
    document_title: SWAG
    links: []
  bundledCode: "#line 1 \"data/swag.hpp\"\n#include<stack>\n#include<cassert>\nusing\
    \ namespace std;\n\ntemplate<typename T,T (*op)(T,T),T (*e)()>\nstruct swag{\n\
    \    stack<T> front,back;\n    stack<T> front_prod,back_prod;\n    swag(){}\n\n\
    \    void move_back(int use){\n        stack<T> tmp;\n        back_prod = stack<T>();\n\
    \        while((int)back.size()>use){\n            tmp.push(back.top());\n   \
    \         back.pop();\n        }\n        while(!back.empty()){\n            this->push_front(back.top());\n\
    \            back.pop();\n        }\n        while(!tmp.empty()){\n          \
    \  this->push_back(tmp.top());\n            tmp.pop();\n        }\n    }\n   \
    \ \n    void move_front(int use){\n        stack<T> tmp;\n        front_prod =\
    \ stack<T>();\n        while((int)front.size()>use){\n            tmp.push(front.top());\n\
    \            front.pop();\n        }\n        while(!front.empty()){\n       \
    \     this->push_back(front.top());\n            front.pop();\n        }\n   \
    \     while(!tmp.empty()){\n            this->push_front(tmp.top());\n       \
    \     tmp.pop();\n        }\n    }\n\n    void push_front(T x){\n        front.push(x);\n\
    \        if(front_prod.empty()) front_prod.push(x);\n        else front_prod.push(op(x,front_prod.top()));\n\
    \    }\n\n    void push_back(T x){\n        back.push(x);\n        if(back_prod.empty())\
    \ back_prod.push(x);\n        else back_prod.push(op(back_prod.top(),x));\n  \
    \  }\n\n    void pop_front(){\n        assert(this->size()>0);\n        if(front.empty())\
    \ move_back(((int)back.size()+1)>>1);\n        front.pop();\n        front_prod.pop();\n\
    \    }\n\n    void pop_back(){\n        assert(this->size()>0);\n        if(back.empty())\
    \ move_front(((int)front.size()+1)>>1);\n        back.pop();\n        back_prod.pop();\n\
    \    }\n\n    T all_prod(){\n        if(front.empty()&&back.empty()) return e();\n\
    \        if(front.empty()) return back_prod.top();\n        if(back.empty()) return\
    \ front_prod.top();\n        return op(front_prod.top(),back_prod.top());\n  \
    \  }\n\n    int size(){\n        return (int)front.size() + (int)back.size();\n\
    \    }\n};\n/**\n * @brief SWAG\n * @docs docs/data/swag.md\n*/\n"
  code: "#include<stack>\n#include<cassert>\nusing namespace std;\n\ntemplate<typename\
    \ T,T (*op)(T,T),T (*e)()>\nstruct swag{\n    stack<T> front,back;\n    stack<T>\
    \ front_prod,back_prod;\n    swag(){}\n\n    void move_back(int use){\n      \
    \  stack<T> tmp;\n        back_prod = stack<T>();\n        while((int)back.size()>use){\n\
    \            tmp.push(back.top());\n            back.pop();\n        }\n     \
    \   while(!back.empty()){\n            this->push_front(back.top());\n       \
    \     back.pop();\n        }\n        while(!tmp.empty()){\n            this->push_back(tmp.top());\n\
    \            tmp.pop();\n        }\n    }\n    \n    void move_front(int use){\n\
    \        stack<T> tmp;\n        front_prod = stack<T>();\n        while((int)front.size()>use){\n\
    \            tmp.push(front.top());\n            front.pop();\n        }\n   \
    \     while(!front.empty()){\n            this->push_back(front.top());\n    \
    \        front.pop();\n        }\n        while(!tmp.empty()){\n            this->push_front(tmp.top());\n\
    \            tmp.pop();\n        }\n    }\n\n    void push_front(T x){\n     \
    \   front.push(x);\n        if(front_prod.empty()) front_prod.push(x);\n     \
    \   else front_prod.push(op(x,front_prod.top()));\n    }\n\n    void push_back(T\
    \ x){\n        back.push(x);\n        if(back_prod.empty()) back_prod.push(x);\n\
    \        else back_prod.push(op(back_prod.top(),x));\n    }\n\n    void pop_front(){\n\
    \        assert(this->size()>0);\n        if(front.empty()) move_back(((int)back.size()+1)>>1);\n\
    \        front.pop();\n        front_prod.pop();\n    }\n\n    void pop_back(){\n\
    \        assert(this->size()>0);\n        if(back.empty()) move_front(((int)front.size()+1)>>1);\n\
    \        back.pop();\n        back_prod.pop();\n    }\n\n    T all_prod(){\n \
    \       if(front.empty()&&back.empty()) return e();\n        if(front.empty())\
    \ return back_prod.top();\n        if(back.empty()) return front_prod.top();\n\
    \        return op(front_prod.top(),back_prod.top());\n    }\n\n    int size(){\n\
    \        return (int)front.size() + (int)back.size();\n    }\n};\n/**\n * @brief\
    \ SWAG\n * @docs docs/data/swag.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: data/swag.hpp
  requiredBy: []
  timestamp: '2023-12-01 14:37:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/queue_operate_all_composite.test.cpp
  - test/library_checker/deque_operate_all_composite.test.cpp
documentation_of: data/swag.hpp
layout: document
redirect_from:
- /library/data/swag.hpp
- /library/data/swag.hpp.html
title: SWAG
---
## SWAG

#### 概要

モノイドの演算結果を保持した deque。

#### 使い方
##### コンストラクタ
`swag<T,op,e> s`<br>
- T：データの型
- T op(T x,T y)：二項演算
- T e()：単位元

以下、二項演算の計算量を $O(f(x))$ とする。

##### 要素の追加
`void s.push_front(T x)`<br>
`void s.push_back(T x)`<br>
先頭(末尾) に要素を追加する。
###### 計算量
$O(f(x))$

##### 要素の削除
`void s.pop_front()`<br>
`void s.pop_back()`<br>
先頭(末尾)の要素を削除する。
###### 計算量
ならし$O(Nf(x))$ ($N$ は全体で要素を追加する回数)

##### 演算結果
`T s.all_prod()`<br>
列にある要素を $a_1,\ldots ,a_n$ として、 $op(a_1,\ldots ,a_n)$ を返す。列が空の場合は $e$ が返される。
###### 計算量
$O(f(x))$

##### その他
`int t.size()`：列の現在の要素数を返す。
