---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: hash/hashint.hpp
    title: Hashint
  - icon: ':heavy_check_mark:'
    path: hash/rollinghash.hpp
    title: Rolling Hash
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/library_checker/zalgorithm_rollinghash.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include<iostream>\n\
    #include<vector>\n#include<algorithm>\n\nusing namespace std;\nusing ll = long\
    \ long;\n\n#line 1 \"hash/hashint.hpp\"\nusing namespace std;\n\n#line 4 \"hash/hashint.hpp\"\
    \n#include<chrono>\n#include<random>\nstruct hashint{\n    using ull = unsigned\
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
    \ hashint a) const {\n        return x < a.x;\n    }\n\n    static ull mul(const\
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
    \ }\n};\n/**\n * @brief Hashint\n * @docs docs/hash/hashint.md\n*/\n#line 2 \"\
    hash/rollinghash.hpp\"\n\n#include<cassert>\ntemplate<typename H,typename T>\n\
    struct rolling_hash{\n    using ull = unsigned long long;\n    struct hash{\n\
    \        H x,b;\n        hash():x(0),b(1){}\n        hash(ull _x,ull _b):x(_x),b(_b){}\n\
    \        hash(H _x,H _b):x(_x),b(_b){}\n\n        ull val(){\n            return\
    \ x.val();\n        }\n\n        hash operator+=(const hash a){\n            x\
    \ = x * a.b + a.x;\n            b *= a.b;\n            return (*this);\n     \
    \   }\n\n        hash operator+(const hash a){\n            hash res(*this);\n\
    \            return res += a;\n        }\n\n        bool operator==(const hash\
    \ a){\n            return x == a.x;\n        }\n\n        bool operator<(const\
    \ hash a){\n            return x < a.x;\n        }\n    };\n\n    int n;\n   \
    \ static H base;\n    vector<H> sum,powb;\n    rolling_hash(T x){\n        n =\
    \ x.size();\n        sum = vector<H>(n+1,0);\n        powb = vector<H>(n+1,1);\n\
    \        for(int i = 0;i<n;i++){\n            sum[i+1] = sum[i] * base + x[i];\n\
    \            powb[i+1] = powb[i] * base;\n        }\n    }\n\n    hash get(int\
    \ l,int r){\n        assert(0<=l&&l<r&&r<=n);\n        return hash(sum[r]-sum[l]*powb[r-l],powb[r-l]);\n\
    \    }\n\n    int lcp(int a,int b){\n        int mx = min(n-a,n-b);\n        int\
    \ right = mx + 1;\n        int left = 0;\n        while(right-left>1){\n     \
    \       int mid = (right+left) / 2;\n            if(get(a,a+mid).val()==get(b,b+mid).val())\
    \ left = mid;\n            else right = mid;\n        }\n        return left;\n\
    \    }\n};\n\nusing rhash = rolling_hash<hashint,string>;\nusing hint = rhash::hash;\n\
    template<>\nhashint rhash::base = hashint::get_base();\n\n/**\n * @brief Rolling\
    \ Hash\n * @docs docs/hash/rollinghash.md\n*/\n#line 11 \"test/library_checker/zalgorithm_rollinghash.test.cpp\"\
    \n\nint main(){\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n \
    \   string s;\n    cin>>s;\n    rhash rh(s);\n    for(int i = 0;i<s.size();i++){\n\
    \        if(i) cout<<\" \";\n        cout<<rh.lcp(0,i);\n    }\n    cout<<endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include<iostream>\n\
    #include<vector>\n#include<algorithm>\n\nusing namespace std;\nusing ll = long\
    \ long;\n\n#include \"hash/rollinghash.hpp\"\n\nint main(){\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n\n    string s;\n    cin>>s;\n    rhash rh(s);\n\
    \    for(int i = 0;i<s.size();i++){\n        if(i) cout<<\" \";\n        cout<<rh.lcp(0,i);\n\
    \    }\n    cout<<endl;\n}\n"
  dependsOn:
  - hash/rollinghash.hpp
  - hash/hashint.hpp
  isVerificationFile: true
  path: test/library_checker/zalgorithm_rollinghash.test.cpp
  requiredBy: []
  timestamp: '2023-12-29 23:27:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/zalgorithm_rollinghash.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/zalgorithm_rollinghash.test.cpp
- /verify/test/library_checker/zalgorithm_rollinghash.test.cpp.html
title: test/library_checker/zalgorithm_rollinghash.test.cpp
---
