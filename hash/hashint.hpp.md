---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: hash/rollinghash.hpp
    title: Rolling Hash
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Hashint
    links: []
  bundledCode: "#line 1 \"hash/hashint.hpp\"\nusing namespace std;\n\n#include<vector>\n\
    #include<chrono>\n#include<random>\nstruct hashint{\n    using ull = unsigned\
    \ long long;\n\n    ull x;\n    const static ull mod = (1ll<<61) - 1;\n    hashint():x(0){}\n\
    \n    hashint(ull _x):x(_x){}\n\n    hashint& operator+=(const hashint a) {\n\
    \        x += a.x;\n        if(x>=mod) x -= mod;\n        return (*this);\n  \
    \  }\n\n    hashint& operator-=(const hashint a) {\n        x += mod - a.x;\n\
    \        if(x>=mod) x -= mod;\n        return (*this);\n    }\n\n    hashint&\
    \ operator*=(const hashint a) {\n        x = mul(x,a.x);\n        return (*this);\n\
    \    }\n\n    hashint operator+(const hashint a) const {\n        hashint res(*this);\n\
    \        return res += a;\n    }\n\n    hashint operator-(const hashint a) const\
    \ {\n        hashint res(*this);\n        return res -= a;\n    }\n\n    hashint\
    \ operator*(const hashint a) const {\n        hashint res(*this);\n        return\
    \ res *= a;\n    }\n\n    ull val(){\n        return x;\n    }\n\n    bool operator==(const\
    \ hashint a) const {\n        return x == a.x;\n    }\n    \n    bool operator<(const\
    \ hashint a) const {\n        return a < a.x;\n    }\n\n    static ull mul(const\
    \ ull a,const ull b) {\\\n        ull au = a >> 31;\n        ull ad = a & ((1ull<<31)-1);\n\
    \        ull bu = b >> 31;\n        ull bd = b & ((1ull<<31)-1);\n        ull\
    \ res = au * bu * 2;\n        ull mid = au * bd + ad * bu;\n        ull midu =\
    \ mid >> 30;\n        ull midd = mid & ((1ull<<30)-1);\n        res += midu +\
    \ midd * (1ull<<31);\n        res += ad * bd;\n        res = (res>>61) + (res&((1ull<<61)-1));\n\
    \        if(res>=mod) res -= mod;\n        return res;\n    }\n\n    static ull\
    \ modpow(ull x,ull k){\n        ull res = 1;\n        while(k){\n            if(k&1)\
    \ res = mul(res,x);\n            x = mul(x,x);\n            k >>= 1;\n       \
    \ }\n        return x;\n    }\n\n    static bool isPrimitive(ull x) {\n      \
    \  for (auto &now:vector<ull>{2, 3, 5, 7, 11, 13, 31, 41, 61, 151, 331, 1321})\n\
    \            if (modpow(x,(mod-1)/now)<=1) return false;\n        return true;\n\
    \    }\n    \n    static hashint get_base(){\n        long long seed = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();\n\
    \        mt19937_64 rnd(seed);\n        uniform_int_distribution<ull> now(1,mod-1);\n\
    \        ull base{};\n        while (true){\n            base = now(rnd);\n  \
    \          if(isPrimitive(base)) break;\n        }\n        return base;\n   \
    \ }\n};\n/**\n * @brief Hashint\n * \n*/\n"
  code: "using namespace std;\n\n#include<vector>\n#include<chrono>\n#include<random>\n\
    struct hashint{\n    using ull = unsigned long long;\n\n    ull x;\n    const\
    \ static ull mod = (1ll<<61) - 1;\n    hashint():x(0){}\n\n    hashint(ull _x):x(_x){}\n\
    \n    hashint& operator+=(const hashint a) {\n        x += a.x;\n        if(x>=mod)\
    \ x -= mod;\n        return (*this);\n    }\n\n    hashint& operator-=(const hashint\
    \ a) {\n        x += mod - a.x;\n        if(x>=mod) x -= mod;\n        return\
    \ (*this);\n    }\n\n    hashint& operator*=(const hashint a) {\n        x = mul(x,a.x);\n\
    \        return (*this);\n    }\n\n    hashint operator+(const hashint a) const\
    \ {\n        hashint res(*this);\n        return res += a;\n    }\n\n    hashint\
    \ operator-(const hashint a) const {\n        hashint res(*this);\n        return\
    \ res -= a;\n    }\n\n    hashint operator*(const hashint a) const {\n       \
    \ hashint res(*this);\n        return res *= a;\n    }\n\n    ull val(){\n   \
    \     return x;\n    }\n\n    bool operator==(const hashint a) const {\n     \
    \   return x == a.x;\n    }\n    \n    bool operator<(const hashint a) const {\n\
    \        return a < a.x;\n    }\n\n    static ull mul(const ull a,const ull b)\
    \ {\\\n        ull au = a >> 31;\n        ull ad = a & ((1ull<<31)-1);\n     \
    \   ull bu = b >> 31;\n        ull bd = b & ((1ull<<31)-1);\n        ull res =\
    \ au * bu * 2;\n        ull mid = au * bd + ad * bu;\n        ull midu = mid >>\
    \ 30;\n        ull midd = mid & ((1ull<<30)-1);\n        res += midu + midd *\
    \ (1ull<<31);\n        res += ad * bd;\n        res = (res>>61) + (res&((1ull<<61)-1));\n\
    \        if(res>=mod) res -= mod;\n        return res;\n    }\n\n    static ull\
    \ modpow(ull x,ull k){\n        ull res = 1;\n        while(k){\n            if(k&1)\
    \ res = mul(res,x);\n            x = mul(x,x);\n            k >>= 1;\n       \
    \ }\n        return x;\n    }\n\n    static bool isPrimitive(ull x) {\n      \
    \  for (auto &now:vector<ull>{2, 3, 5, 7, 11, 13, 31, 41, 61, 151, 331, 1321})\n\
    \            if (modpow(x,(mod-1)/now)<=1) return false;\n        return true;\n\
    \    }\n    \n    static hashint get_base(){\n        long long seed = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();\n\
    \        mt19937_64 rnd(seed);\n        uniform_int_distribution<ull> now(1,mod-1);\n\
    \        ull base{};\n        while (true){\n            base = now(rnd);\n  \
    \          if(isPrimitive(base)) break;\n        }\n        return base;\n   \
    \ }\n};\n/**\n * @brief Hashint\n * \n*/"
  dependsOn: []
  isVerificationFile: false
  path: hash/hashint.hpp
  requiredBy:
  - hash/rollinghash.hpp
  timestamp: '2023-12-21 23:43:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: hash/hashint.hpp
layout: document
redirect_from:
- /library/hash/hashint.hpp
- /library/hash/hashint.hpp.html
title: Hashint
---
