---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/minplusconvolutionconvex.hpp
    title: math/minplusconvolutionconvex.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex
    links:
    - https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex
  bundledCode: "#line 1 \"test/library_checker/min_plus_convolution_convex_convex.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n#line\
    \ 3 \"math/minplusconvolutionconvex.hpp\"\nstd::vector<long long> min_plus_convolution(std::vector<long\
    \ long>&a,std::vector<long long>&b){\n    int n = a.size();\n    int m = b.size();\n\
    \    assert(n>0&&m>0);\n    std::vector<long long> res(n+m-1);\n    int ni = 0;\n\
    \    int nj = 0;\n    res[0] = a[0] + b[0];\n    while(ni+1<n||nj+1<m){\n    \
    \    long long use = 9e18;\n        if(ni+1<n) use = a[ni+1] - a[ni];\n      \
    \  if(nj+1<m) use = std::min(use,b[nj+1]-b[nj]);\n        if(ni+1<n&&a[ni+1]-a[ni]==use)\
    \ ni++;\n        else nj++;\n        res[ni+nj] = res[ni+nj-1] + use; \n    }\n\
    \    return res;\n}\n#line 7 \"test/library_checker/min_plus_convolution_convex_convex.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n   \
    \ \n    int n,m;\n    cin>>n>>m;\n    vector<ll> a(n),b(m);\n    for(int i = 0;i<n;i++)\
    \ cin>>a[i];\n    for(int i = 0;i<m;i++) cin>>b[i];\n    auto ans = min_plus_convolution(a,b);\n\
    \    for(int i = 0;i<ans.size();i++){\n        if(i) cout<<' ';\n        cout<<ans[i];\n\
    \    }\n    cout<<'\\n';\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n#include\
    \ \"math/minplusconvolutionconvex.hpp\"\n\nint main(){\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    \n    int n,m;\n    cin>>n>>m;\n    vector<ll>\
    \ a(n),b(m);\n    for(int i = 0;i<n;i++) cin>>a[i];\n    for(int i = 0;i<m;i++)\
    \ cin>>b[i];\n    auto ans = min_plus_convolution(a,b);\n    for(int i = 0;i<ans.size();i++){\n\
    \        if(i) cout<<' ';\n        cout<<ans[i];\n    }\n    cout<<'\\n';\n}\n\
    \n"
  dependsOn:
  - math/minplusconvolutionconvex.hpp
  isVerificationFile: true
  path: test/library_checker/min_plus_convolution_convex_convex.test.cpp
  requiredBy: []
  timestamp: '2023-10-17 14:24:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/min_plus_convolution_convex_convex.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/min_plus_convolution_convex_convex.test.cpp
- /verify/test/library_checker/min_plus_convolution_convex_convex.test.cpp.html
title: test/library_checker/min_plus_convolution_convex_convex.test.cpp
---
