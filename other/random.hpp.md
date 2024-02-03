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
  bundledCode: "#line 1 \"other/random.hpp\"\n#include <random>\n#include <chrono>\n\
    int64_t seed = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();\n\
    mt19937_64 rnd(seed);\nint random(int l,int r){\n    uniform_int_distribution<int>\
    \ now(l,r);\n    return now(rnd);\n}\n"
  code: "#include <random>\n#include <chrono>\nint64_t seed = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();\n\
    mt19937_64 rnd(seed);\nint random(int l,int r){\n    uniform_int_distribution<int>\
    \ now(l,r);\n    return now(rnd);\n}"
  dependsOn: []
  isVerificationFile: false
  path: other/random.hpp
  requiredBy: []
  timestamp: '2024-02-03 20:45:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/random.hpp
layout: document
redirect_from:
- /library/other/random.hpp
- /library/other/random.hpp.html
title: other/random.hpp
---
