---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/min_plus_convolution_convex_convex.test.cpp
    title: test/library_checker/min_plus_convolution_convex_convex.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/minplusconvolutionconvex.hpp\"\n#include<vector>\n\
    #include<cassert>\nstd::vector<long long> min_plus_convolution(std::vector<long\
    \ long>&a,std::vector<long long>&b){\n    int n = a.size();\n    int m = b.size();\n\
    \    assert(n>0&&m>0);\n    std::vector<long long> res(n+m-1);\n    int ni = 0;\n\
    \    int nj = 0;\n    res[0] = a[0] + b[0];\n    while(ni+1<n||nj+1<m){\n    \
    \    long long use = 9e18;\n        if(ni+1<n) use = a[ni+1] - a[ni];\n      \
    \  if(nj+1<m) use = std::min(use,b[nj+1]-b[nj]);\n        if(ni+1<n&&a[ni+1]-a[ni]==use)\
    \ ni++;\n        else nj++;\n        res[ni+nj] = res[ni+nj-1] + use; \n    }\n\
    \    return res;\n}\n"
  code: "#include<vector>\n#include<cassert>\nstd::vector<long long> min_plus_convolution(std::vector<long\
    \ long>&a,std::vector<long long>&b){\n    int n = a.size();\n    int m = b.size();\n\
    \    assert(n>0&&m>0);\n    std::vector<long long> res(n+m-1);\n    int ni = 0;\n\
    \    int nj = 0;\n    res[0] = a[0] + b[0];\n    while(ni+1<n||nj+1<m){\n    \
    \    long long use = 9e18;\n        if(ni+1<n) use = a[ni+1] - a[ni];\n      \
    \  if(nj+1<m) use = std::min(use,b[nj+1]-b[nj]);\n        if(ni+1<n&&a[ni+1]-a[ni]==use)\
    \ ni++;\n        else nj++;\n        res[ni+nj] = res[ni+nj-1] + use; \n    }\n\
    \    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/minplusconvolutionconvex.hpp
  requiredBy: []
  timestamp: '2023-10-17 14:20:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/min_plus_convolution_convex_convex.test.cpp
documentation_of: math/minplusconvolutionconvex.hpp
layout: document
redirect_from:
- /library/math/minplusconvolutionconvex.hpp
- /library/math/minplusconvolutionconvex.hpp.html
title: math/minplusconvolutionconvex.hpp
---
