---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data/swag.hpp
    title: SWAG
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/deque_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/deque_operate_all_composite
  bundledCode: "#line 1 \"test/library_checker/deque_operate_all_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/deque_operate_all_composite\"\
    \n\n#include<iostream>\nusing namespace std;\nusing ll = long long;\n\n#line 1\
    \ \"data/swag.hpp\"\n#include<stack>\n#include<cassert>\nusing namespace std;\n\
    \ntemplate<typename T,T (*op)(T,T),T (*e)()>\nstruct swag{\n    stack<T> front,back;\n\
    \    stack<T> front_prod,back_prod;\n    swag(){}\n\n    void move_back(int use){\n\
    \        stack<T> tmp;\n        back_prod = stack<T>();\n        while((int)back.size()>use){\n\
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
    \ SWAG\n*/\n#line 8 \"test/library_checker/deque_operate_all_composite.test.cpp\"\
    \n\nconst ll mod = 998244353;\nll add(ll x,ll y){\n    ll res = x + y;\n    if(res>=mod)\
    \ return res - mod;\n    return res;\n}\nll product(ll x,ll y){\n    return (x*y)%mod;\n\
    }\n\nusing dat = pair<ll,ll>;\ndat op(dat a,dat b){\n    return make_pair(product(a.first,b.first),add(product(b.first,a.second),b.second));\n\
    }\n\ndat e(){\n    return make_pair(1,0);\n}\n\nint main(){\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    swag<dat,op,e> sw;\n    int q;\n    cin>>q;\n\
    \    while(q--){\n        int t;\n        cin>>t;\n        if(t==0){\n       \
    \     int a,b;\n            cin>>a>>b;\n            sw.push_front(make_pair(a,b));\n\
    \        }else if(t==1){\n            int a,b;\n            cin>>a>>b;\n     \
    \       sw.push_back(make_pair(a,b));\n        }else if(t==2){\n            sw.pop_front();\n\
    \        }else if(t==3){\n            sw.pop_back();\n        }else{\n       \
    \     int x;\n            cin>>x;\n            dat now = sw.all_prod();\n    \
    \        int ans = add(product(now.first,x),now.second);\n            cout<<ans<<endl;\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/deque_operate_all_composite\"\
    \n\n#include<iostream>\nusing namespace std;\nusing ll = long long;\n\n#include\
    \ \"data/swag.hpp\"\n\nconst ll mod = 998244353;\nll add(ll x,ll y){\n    ll res\
    \ = x + y;\n    if(res>=mod) return res - mod;\n    return res;\n}\nll product(ll\
    \ x,ll y){\n    return (x*y)%mod;\n}\n\nusing dat = pair<ll,ll>;\ndat op(dat a,dat\
    \ b){\n    return make_pair(product(a.first,b.first),add(product(b.first,a.second),b.second));\n\
    }\n\ndat e(){\n    return make_pair(1,0);\n}\n\nint main(){\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    swag<dat,op,e> sw;\n    int q;\n    cin>>q;\n\
    \    while(q--){\n        int t;\n        cin>>t;\n        if(t==0){\n       \
    \     int a,b;\n            cin>>a>>b;\n            sw.push_front(make_pair(a,b));\n\
    \        }else if(t==1){\n            int a,b;\n            cin>>a>>b;\n     \
    \       sw.push_back(make_pair(a,b));\n        }else if(t==2){\n            sw.pop_front();\n\
    \        }else if(t==3){\n            sw.pop_back();\n        }else{\n       \
    \     int x;\n            cin>>x;\n            dat now = sw.all_prod();\n    \
    \        int ans = add(product(now.first,x),now.second);\n            cout<<ans<<endl;\n\
    \        }\n    }\n}\n"
  dependsOn:
  - data/swag.hpp
  isVerificationFile: true
  path: test/library_checker/deque_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2023-11-30 18:29:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/deque_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/deque_operate_all_composite.test.cpp
- /verify/test/library_checker/deque_operate_all_composite.test.cpp.html
title: test/library_checker/deque_operate_all_composite.test.cpp
---
