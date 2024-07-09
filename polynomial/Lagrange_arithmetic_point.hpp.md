---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/polynomial/Lagrange_arithmetic_point.md
    document_title: Lagrange_arithmetic_point
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
    \ inv *= a[i] - a[n-1];\n    }\n\n    return ans;\n}\n/**\n * @brief Lagrange_arithmetic_point\n\
    \ * @docs docs/polynomial/Lagrange_arithmetic_point.md\n*/\n"
  code: "#include<vector>\n#include<cassert>\ntemplate <typename T>\nT Lagrange_arithmetic_point(std::vector<T>a,std::vector<T>b,long\
    \ long k){\n    int n = a.size();\n    assert(a.size()==b.size());\n    assert(n>0);\n\
    \n    T ans = 0;\n    T inv = 1;\n    for(int i = 1;i<n;i++){\n        inv *=\
    \ (a[0]-a[i]).inv();\n    }\n\n    std::vector<T> use(n,1);\n    T now = 1;\n\
    \    for(int i = 0;i<n;i++){\n        use[i] *= now;\n        now *= T(k) - a[i];\n\
    \    }\n    now = 1;\n    for(int i = n-1;i>=0;i--){\n        use[i] *= now;\n\
    \        now *= T(k) - a[i];\n    }\n\n    for(int i = 0;i<n;i++){\n        if(i>0)\
    \ inv *= (a[i]-a[0]).inv();\n        ans += b[i] * use[i] * inv;\n        if(i+1<n)\
    \ inv *= a[i] - a[n-1];\n    }\n\n    return ans;\n}\n/**\n * @brief Lagrange_arithmetic_point\n\
    \ * @docs docs/polynomial/Lagrange_arithmetic_point.md\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: polynomial/Lagrange_arithmetic_point.hpp
  requiredBy: []
  timestamp: '2024-07-09 12:15:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: polynomial/Lagrange_arithmetic_point.hpp
layout: document
redirect_from:
- /library/polynomial/Lagrange_arithmetic_point.hpp
- /library/polynomial/Lagrange_arithmetic_point.hpp.html
title: Lagrange_arithmetic_point
---
## Lagrange_arithmetic_point

#### 概要

評価点が等差数列であり，一点取得をするラグランジュ補間．主にACLのmodintでの使用を想定．

#### 使い方
`T Lagrange_arithmetic_point(vector<T>a,vector<T>b,long long k)`：$f(a[\mathrm{i}])=b[\mathrm{i}]$ を満たす $(|a|-1)$ 次多項式 $f(x)$ における $f(k)$ の値を返す．計算量は $O(|a|f(p))\ (\text{ただし }f(p)\text{ は逆元を求める計算量})$ ．配列 $a$ の値は等差数列であることを仮定している．