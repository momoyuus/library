---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data/lichaotree.hpp
    title: data/lichaotree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/library_checker/line_add_get_min.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#include<bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n\n#line 1 \"data/lichaotree.hpp\"\
    \ntemplate<typename T>\nstruct dynamic_li_chao_tree{\n    struct Node;\n    using\
    \ node_ptr = Node*;\n\n    struct Line{\n        T a,b;\n        Line(T _a,T _b):a(_a),b(_b){}\n\
    \        inline T get(const T&x) const {\n            return a * x + b;\n    \
    \    }\n    };\n    \n    struct Node{\n        Line x;\n        node_ptr l =\
    \ nullptr,r = nullptr;\n        Node(const Line&_x):x(_x){}\n    };\n    \n  \
    \  T mn,mx,id;\n    node_ptr root;\n    dynamic_li_chao_tree(T _mn,T _mx, T _id):mn(_mn),mx(_mx),id(_id),root(nullptr){}\n\
    \    \n    void add_line(node_ptr& t,Line&x,const T&l,const T&r){\n        if(!t){\n\
    \            t = new Node(x);\n            return;\n        }\n        T x_l =\
    \ x.get(l);\n        T x_r = x.get(r);\n        T t_l = t->x.get(l);\n       \
    \ T t_r = t->x.get(r);\n        if(t_l<=x_l&&t_r<=x_r) return;\n        if(x_l<=t_l&&x_r<=t_r)\
    \ {\n            t->x = x;\n            return;\n        }\n        T mid = ((r-l)>>1)\
    \ + l;\n        if(mid==r) mid--;\n        T x_m = x.get(mid);\n        T t_m\
    \ = t->x.get(mid);\n        if(t_m>x_m){\n            swap(t->x,x);\n        \
    \    if(x_l>=t_l) add_line(t->l,x,l,mid);\n            else add_line(t->r,x,mid+1,r);\n\
    \        }else{\n            if(t_l>=x_l) add_line(t->l,x,l,mid);\n          \
    \  else add_line(t->r,x,mid+1,r);\n        }\n        return;\n    }\n    void\
    \ add_line(const T&a,const T&b){\n        Line x(a,b);\n        add_line(root,x,mn,mx);\n\
    \    }\n    void add_segment(node_ptr&t,const Line&x,const T&l,const T&r,const\
    \ T&L,const T&R){\n        if(r<L||R<l) return;\n        if(l<=L&&R<=r){\n   \
    \         Line y = x;\n            add_line(t,y,L,R);\n            return;\n \
    \       }\n        if(t){\n            T t_l = t->x.get(L);\n            T t_r\
    \ = t->x.get(R);\n            if(t_l<=x.get(L)&&t_r<=x.get(R)) return;\n     \
    \   }else{\n            t = new Node(Line(0,id));\n        }\n        T mid =\
    \ ((R-L)>>1) + L;\n        if(mid==R) mid--;\n        add_segment(t->l,x,l,r,L,mid);\n\
    \        add_segment(t->r,x,l,r,mid+1,R);\n    }\n\n    void add_segment(const\
    \ T&l,const T&r,const T&a,const T&b){\n        Line x(a,b);\n        add_segment(root,x,l,r-1,mn,mx);\n\
    \    }\n\n    T query(const node_ptr&t,const T&x,const T&l,const T&r) const {\n\
    \        if(!t) return id;\n        if(l==r) return t->x.get(x);\n        T mid\
    \ = ((r-l)>>1) + l;\n        if(mid==r) mid--;\n        if(x<=mid) return min(t->x.get(x),query(t->l,x,l,mid));\n\
    \        else return min(t->x.get(x),query(t->r,x,mid+1,r));\n    }\n    T query(const\
    \ T&x) const {\n        return query(root,x,mn,mx);\n    }\n};\n#line 7 \"test/library_checker/line_add_get_min.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n   \
    \ \n    int n,q;\n    cin>>n>>q;\n    dynamic_li_chao_tree<ll> li(-1e9,1e9,9e18);\n\
    \    for(int i = 0;i<n;i++){\n        ll a,b;\n        cin>>a>>b;\n        li.add_line(a,b);\n\
    \    }\n    while(q--){\n        int op;\n        cin>>op;\n        if(op==0){\n\
    \            ll a,b;\n            cin>>a>>b;\n            li.add_line(a,b);\n\
    \        }else{\n            ll p;\n            cin>>p;\n            cout<<li.query(p)<<endl;\n\
    \        }\n    }\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#include<bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n\n#include \"data/lichaotree.hpp\"\
    \n\nint main(){\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n   \
    \ \n    int n,q;\n    cin>>n>>q;\n    dynamic_li_chao_tree<ll> li(-1e9,1e9,9e18);\n\
    \    for(int i = 0;i<n;i++){\n        ll a,b;\n        cin>>a>>b;\n        li.add_line(a,b);\n\
    \    }\n    while(q--){\n        int op;\n        cin>>op;\n        if(op==0){\n\
    \            ll a,b;\n            cin>>a>>b;\n            li.add_line(a,b);\n\
    \        }else{\n            ll p;\n            cin>>p;\n            cout<<li.query(p)<<endl;\n\
    \        }\n    }\n}\n\n"
  dependsOn:
  - data/lichaotree.hpp
  isVerificationFile: true
  path: test/library_checker/line_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2023-10-23 17:41:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/line_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/line_add_get_min.test.cpp
- /verify/test/library_checker/line_add_get_min.test.cpp.html
title: test/library_checker/line_add_get_min.test.cpp
---
