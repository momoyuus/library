---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/deque_operate_all_composite.test.cpp
    title: test/library_checker/deque_operate_all_composite.test.cpp
  - icon: ':x:'
    path: test/library_checker/queue_operate_all_composite.test.cpp
    title: test/library_checker/queue_operate_all_composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
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
    \    }\n};\n/**\n * @brief SWAG\n*/\n"
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
    \ SWAG\n*/"
  dependsOn: []
  isVerificationFile: false
  path: data/swag.hpp
  requiredBy: []
  timestamp: '2023-11-30 18:25:36+09:00'
  verificationStatus: LIBRARY_SOME_WA
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