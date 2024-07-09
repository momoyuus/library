---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"polynomial/Lagrange_arithmetic_point.hpp\"\n#include<vector>\n\
    #include<cassert>\ntemplate <typename T>\nT Lagrange_arithmetic_point(std::vector<T>a,std::vector<T>b,long\
    \ long k){\n    int n = a.size();\n    assert(a.size()==b.size());\n    assert(n>0);\n\
    \n    T ans = 0;\n    T inv = 1;\n    for(int i = 1;i<n;i++){\n        inv *=\
    \ (a[0]-a[i]).inv();\n    }\n\n    std::vector<T> use(n,1);\n    T now = 1;\n\
    \    for(int i = 0;i<n;i++){\n        use[i] *= now;\n        now *= T(k) - a[i];\n\
    \    }\n    now = 1;\n    for(int i = n-1;i>=0;i--){\n        use[i] *= now;\n\
    \        now *= T(k) - a[i];\n    }\n\n    for(int i = 0;i<n;i++){\n        if(i>0)\
    \ inv *= (a[i]-a[0]).inv();\n        ans += b[i] * use[i] * inv;\n        if(i+1<n)\
    \ inv *= a[i] - a[n-1];\n    }\n\n    return ans;\n}\n"
  code: "#include<vector>\n#include<cassert>\ntemplate <typename T>\nT Lagrange_arithmetic_point(std::vector<T>a,std::vector<T>b,long\
    \ long k){\n    int n = a.size();\n    assert(a.size()==b.size());\n    assert(n>0);\n\
    \n    T ans = 0;\n    T inv = 1;\n    for(int i = 1;i<n;i++){\n        inv *=\
    \ (a[0]-a[i]).inv();\n    }\n\n    std::vector<T> use(n,1);\n    T now = 1;\n\
    \    for(int i = 0;i<n;i++){\n        use[i] *= now;\n        now *= T(k) - a[i];\n\
    \    }\n    now = 1;\n    for(int i = n-1;i>=0;i--){\n        use[i] *= now;\n\
    \        now *= T(k) - a[i];\n    }\n\n    for(int i = 0;i<n;i++){\n        if(i>0)\
    \ inv *= (a[i]-a[0]).inv();\n        ans += b[i] * use[i] * inv;\n        if(i+1<n)\
    \ inv *= a[i] - a[n-1];\n    }\n\n    return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: polynomial/Lagrange_arithmetic_point.hpp
  requiredBy: []
  timestamp: '2024-07-09 11:47:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: polynomial/Lagrange_arithmetic_point.hpp
layout: document
redirect_from:
- /library/polynomial/Lagrange_arithmetic_point.hpp
- /library/polynomial/Lagrange_arithmetic_point.hpp.html
title: polynomial/Lagrange_arithmetic_point.hpp
---
