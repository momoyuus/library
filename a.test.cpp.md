---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"a.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n\ntemplate<typename\
    \ T>\nstruct cumsum{\n    int n;\n    vector<T> dat;\n    cumsum(){}\n    cumsum(const\
    \ vector<T>a):n(a.size()),dat(a.size()+1,0){\n        for(int i = 0;i<n;i++) dat[i+1]\
    \ = dat[i] + a[i];\n    }\n    \n    T sum(int l,int r){\n        return dat[r]\
    \ - dat[l];\n    }\n};\n\nint main(){\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    \n     int n,q;\n     cin>>n>>q;\n     vector<ll> a(n);\n     for(int i =\
    \ 0;i<n;i++) cin>>a[i];\n     cumsum<ll> sum(a);\n     for(int i = 0;i<q;i++){\n\
    \         int l,r;\n         cin>>l>>r;\n         cout<<sum.sum(l,r)<<'\\n';\n\
    \     }\n\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nusing ll = long long;\n\ntemplate<typename T>\nstruct\
    \ cumsum{\n    int n;\n    vector<T> dat;\n    cumsum(){}\n    cumsum(const vector<T>a):n(a.size()),dat(a.size()+1,0){\n\
    \        for(int i = 0;i<n;i++) dat[i+1] = dat[i] + a[i];\n    }\n    \n    T\
    \ sum(int l,int r){\n        return dat[r] - dat[l];\n    }\n};\n\nint main(){\n\
    \    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    \n     int n,q;\n\
    \     cin>>n>>q;\n     vector<ll> a(n);\n     for(int i = 0;i<n;i++) cin>>a[i];\n\
    \     cumsum<ll> sum(a);\n     for(int i = 0;i<q;i++){\n         int l,r;\n  \
    \       cin>>l>>r;\n         cout<<sum.sum(l,r)<<'\\n';\n     }\n\n}\n\n"
  dependsOn: []
  isVerificationFile: true
  path: a.test.cpp
  requiredBy: []
  timestamp: '2023-10-16 17:29:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: a.test.cpp
layout: document
redirect_from:
- /verify/a.test.cpp
- /verify/a.test.cpp.html
title: a.test.cpp
---
