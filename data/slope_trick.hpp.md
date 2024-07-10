---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/data/slope_trick.md
    document_title: slope_trick
    links: []
  bundledCode: "#line 1 \"data/slope_trick.hpp\"\n\n#include<queue>\ntemplate<typename\
    \ T>\nstruct slope_trick{\n    priority_queue<T> l;\n    priority_queue<T,vector<T>,greater<T>>\
    \ r;\n    T m,add_l,add_r;\n    slope_trick(){\n        m = 0;\n    }\n\n    T\
    \ get_min(){\n        return m;\n    }\n\n    pair<T,T> get_min_interval(){\n\
    \        // not yet\n    }\n\n    void add_all(T a){\n        m += a;\n    }\n\
    \n    // max(0,x-a)\n    void add_plus(T a){\n        if(!l.empty()) m += max<T>(0,(l.top()+add_l)-a);\n\
    \        if(!l.empty()&&(l.top()+add_l)<=a) r.push(a-add_r);\n        else{\n\
    \            l.push(a-add_l);\n            r.push(l.top()+add_l-add_r);\n    \
    \        l.pop();\n        }\n    }\n\n    // max(0,a-x)\n    void add_minus(T\
    \ a){\n        if(!r.empty()) m += max<T>(0,a-(r.top()+add_r));\n        if(!r.empty()&&a<=(r.top()+add_r))\
    \ l.push(a-add_l);\n        else{\n            r.push(a-add_r);\n            l.push(r.top()+add_r-add_l);\n\
    \            r.pop();\n        }\n    }\n\n    void add_abs(T a){\n        add_plus(a);\n\
    \        add_minus(a);\n    }\n\n    void min_left(){\n        r.clear();\n  \
    \      add_r = 0;\n    }\n\n    void min_right(){\n        l.clear();\n      \
    \  add_l = 0;\n    }\n\n    void move(T a){\n        add_l += a;\n        add_r\
    \ += a;\n    }\n\n    // g(x) = min_{y \\in [x-le,x+ri]} f(y)\n    void sliding_min(T\
    \ le,T ri){\n        add_r += le;\n        add_l -= ri;\n    }\n\n    //O(n)\n\
    \    T get(T x){\n        T now = m;\n        if(!r.empty()&&r.top()+add_r<=x){\n\
    \            vector<T> use;\n            while(!r.empty()){\n                if(x<=r.top()+add_r)\
    \ break;\n                use.push_back(r.top()+add_r);\n                r.pop();\n\
    \            }\n            for(int i = 0;i<use.size();i++) now += x - use[i];\n\
    \            for(int i = 0;i<use.size();i++) r.push(use[i]-add_r);\n        }else\
    \ if(!l.empty()&&x<=l.top()+add_l){\n            vector<T> use;\n            while(!l.empty()){\n\
    \                if(l.top()+add_l<=x) break;\n                use.push_back(l.top()+add_l);\n\
    \                l.pop();\n            }\n            for(int i = 0;i<use.size();i++)\
    \ now += use[i] - x;\n            for(int i = 0;i<use.size();i++) l.push(use[i]-add_l);\n\
    \        }\n        return now;\n    }\n};\n/**\n * @brief slope_trick\n * @docs\
    \ docs/data/slope_trick.md\n*/\n"
  code: "\n#include<queue>\ntemplate<typename T>\nstruct slope_trick{\n    priority_queue<T>\
    \ l;\n    priority_queue<T,vector<T>,greater<T>> r;\n    T m,add_l,add_r;\n  \
    \  slope_trick(){\n        m = 0;\n    }\n\n    T get_min(){\n        return m;\n\
    \    }\n\n    pair<T,T> get_min_interval(){\n        // not yet\n    }\n\n   \
    \ void add_all(T a){\n        m += a;\n    }\n\n    // max(0,x-a)\n    void add_plus(T\
    \ a){\n        if(!l.empty()) m += max<T>(0,(l.top()+add_l)-a);\n        if(!l.empty()&&(l.top()+add_l)<=a)\
    \ r.push(a-add_r);\n        else{\n            l.push(a-add_l);\n            r.push(l.top()+add_l-add_r);\n\
    \            l.pop();\n        }\n    }\n\n    // max(0,a-x)\n    void add_minus(T\
    \ a){\n        if(!r.empty()) m += max<T>(0,a-(r.top()+add_r));\n        if(!r.empty()&&a<=(r.top()+add_r))\
    \ l.push(a-add_l);\n        else{\n            r.push(a-add_r);\n            l.push(r.top()+add_r-add_l);\n\
    \            r.pop();\n        }\n    }\n\n    void add_abs(T a){\n        add_plus(a);\n\
    \        add_minus(a);\n    }\n\n    void min_left(){\n        r.clear();\n  \
    \      add_r = 0;\n    }\n\n    void min_right(){\n        l.clear();\n      \
    \  add_l = 0;\n    }\n\n    void move(T a){\n        add_l += a;\n        add_r\
    \ += a;\n    }\n\n    // g(x) = min_{y \\in [x-le,x+ri]} f(y)\n    void sliding_min(T\
    \ le,T ri){\n        add_r += le;\n        add_l -= ri;\n    }\n\n    //O(n)\n\
    \    T get(T x){\n        T now = m;\n        if(!r.empty()&&r.top()+add_r<=x){\n\
    \            vector<T> use;\n            while(!r.empty()){\n                if(x<=r.top()+add_r)\
    \ break;\n                use.push_back(r.top()+add_r);\n                r.pop();\n\
    \            }\n            for(int i = 0;i<use.size();i++) now += x - use[i];\n\
    \            for(int i = 0;i<use.size();i++) r.push(use[i]-add_r);\n        }else\
    \ if(!l.empty()&&x<=l.top()+add_l){\n            vector<T> use;\n            while(!l.empty()){\n\
    \                if(l.top()+add_l<=x) break;\n                use.push_back(l.top()+add_l);\n\
    \                l.pop();\n            }\n            for(int i = 0;i<use.size();i++)\
    \ now += use[i] - x;\n            for(int i = 0;i<use.size();i++) l.push(use[i]-add_l);\n\
    \        }\n        return now;\n    }\n};\n/**\n * @brief slope_trick\n * @docs\
    \ docs/data/slope_trick.md\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: data/slope_trick.hpp
  requiredBy: []
  timestamp: '2024-07-10 21:47:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data/slope_trick.hpp
layout: document
redirect_from:
- /library/data/slope_trick.hpp
- /library/data/slope_trick.hpp.html
title: slope_trick
---
## SWAG

#### 概要

参考：https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8#toc17
