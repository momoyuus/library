---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: hash/hashint.hpp
    title: Hashint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/hash/rollinghash.md
    document_title: Rolling Hash
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
    \ Hash\n * @docs docs/hash/rollinghash.md\n*/\n"
  code: "#include \"hash/hashint.hpp\"\n\n#include<cassert>\ntemplate<typename H,typename\
    \ T>\nstruct rolling_hash{\n    using ull = unsigned long long;\n    struct hash{\n\
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
    \ Hash\n * @docs docs/hash/rollinghash.md\n*/"
  dependsOn:
  - hash/hashint.hpp
  isVerificationFile: false
  path: hash/rollinghash.hpp
  requiredBy: []
  timestamp: '2023-12-29 23:26:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: hash/rollinghash.hpp
layout: document
redirect_from:
- /library/hash/rollinghash.hpp
- /library/hash/rollinghash.hpp.html
title: Rolling Hash
---
## Rolling Hash

#### 概要
ローリングハッシュ。ハッシュは`rolling_hash<hashint,T>::hash`という型で返される。以降、この型を`hash`と省略する。


#### 使い方
##### コンストラクタ
`rolling_hash<hashint,T> rh(T S)`<br>
- hashint：ハッシュの演算。`+, - ,*` 等の演算と、`.val()` で値の参照ができる構造体を乗せることができる。
- T：乗せる列のデータ型。基本は`string`か`vector<hoge>`だと思う。
###### 計算量
$O(|S|)$

##### ハッシュの取得
`hash rh.get(l,r)`<br>
部分列 $S[l,r)$ のハッシュを返す。
###### 計算量
$O(1)$

##### その他
`int rh.lcp(int a,int b)` $S[a,n)$, $S[b,n)$ の LCP の長さを返す。<br>

#### hash 型について
##### 文字列の結合
`hash + hash` <br>
`hash += hash`<br>
これらの演算は文字列の結合に対応する演算である。
###### 計算量
$O(1)$
 
##### その他
`.val()` 値を返す。<br>
`hash < hash` 値の大小比較
