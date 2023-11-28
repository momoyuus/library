---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/library_checker/nim_product_64.cpp
    title: test/library_checker/nim_product_64.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/nimber.md
    document_title: Nimber
    links: []
  bundledCode: "#line 2 \"math/nimber.hpp\"\n\n#include<iostream>\n#include<cstdint>\n\
    #include<array>\n#include<vector>\n\nstruct Nimber{\n    using ul = unsigned long\
    \ long;\n    using Nimber_table = std::array<std::array<uint8_t,256>,256>;\n \
    \   using Sqrt_table = std::array<uint8_t,256>;\n    using Inv_table = Sqrt_table;\n\
    \    ul n;\n    Nimber():n(0){}\n    Nimber(ul _n):n(_n){}\n    static inline\
    \ Nimber_table table;\n    static inline Sqrt_table sq_table; \n    static inline\
    \ Inv_table inv_table;\n    const static inline uint32_t U32_MAX = ~((uint32_t)0);\n\
    \    const static inline uint16_t U16_MAX = ~((uint16_t)0);\n    const static\
    \ inline uint8_t U8_MAX = ~((uint8_t)0);\n    \n    constexpr static int init(){\n\
    \        const int L = 8;\n        table[1][1] = 1;\n        for(int i = 1;i<L;i<<=1){\n\
    \            int mask = (1<<i) - 1;\n            for(int j = 1<<i;j<1<<(2*i);j++){\n\
    \                for(int k = 1;k<=j;k++){\n                    int a = j & mask;\n\
    \                    int b = k & mask;\n                    int c = j >> i;\n\
    \                    int d = k >> i;\n                    int e = table[a][b];\n\
    \                    table[j][k] = table[k][j] = (table[a^c][b^d]^e) << i | (table[table[c][d]][1<<(i-1)]\
    \ ^ e);\n                }\n            }\n        }\n        for(int i = 0;i<256;i++)\
    \ sq_table[table[i][i]] = i;\n        for(int i = 1;i<256;i++){\n            for(int\
    \ j = 1;j<256;j++){\n                if(table[i][j]==1){\n                   \
    \ inv_table[i] = j;\n                    break;\n                }\n         \
    \   }\n        }\n        return 0;\n    }\n\n    static uint16_t p16(uint16_t\
    \ x,uint16_t y){\n        uint8_t a = x & U8_MAX;\n        uint8_t b = y & U8_MAX;\n\
    \        uint8_t c = x >> 8;\n        uint8_t d = y >> 8;\n        uint8_t e =\
    \ table[a][b];\n        return (uint16_t)(table[a^c][b^d]^e) << 8 | (table[table[c][d]][1<<7]\
    \ ^ e);\n    }\n    static uint16_t h16(uint16_t x,uint16_t y){\n        uint8_t\
    \ a = x & U8_MAX;\n        uint8_t c = x >> 8;\n        uint8_t d = y >> 8;\n\
    \        return (uint16_t)(table[a^c][d]) << 8 | (table[table[c][d]][1<<7]);\n\
    \    }\n    static uint32_t p32(uint32_t x,uint32_t y){\n        uint16_t a =\
    \ x & U16_MAX;\n        uint16_t b = y & U16_MAX;\n        uint16_t c = x >> 16;\n\
    \        uint16_t d = y >> 16;\n        uint16_t e = p16(a,b);\n        return\
    \ (uint32_t)(p16(a^c,b^d)^e) << 16 | (h16(p16(c,d),1<<15) ^ e);\n    }\n    static\
    \ uint32_t h32(uint32_t x,uint32_t y){\n        uint16_t a = x & U16_MAX;\n  \
    \      uint16_t c = x >> 16;\n        uint16_t d = y >> 16;\n        return (uint32_t)(p16(a^c,d))\
    \ << 16 | h16(p16(c,d),1<<15);\n    }\n    static uint64_t p64(uint64_t x,uint64_t\
    \ y){\n        uint32_t a = x & U32_MAX;\n        uint32_t b = y & U32_MAX;\n\
    \        uint32_t c = x >> 32;\n        uint32_t d = y >> 32;\n        uint32_t\
    \ e = p32(a,b);\n        return (uint64_t)(p32(a^c,b^d)^e) << 32 | (h32(p32(c,d),1<<31)\
    \ ^ e);\n    }\n    ul val(){return this->n;}\n    Nimber operator-() const{\n\
    \        return Nimber(*this);\n    }\n    Nimber& operator+=(const Nimber a){\n\
    \        n ^= a.n;\n        return *this;\n    }\n    Nimber& operator-=(const\
    \ Nimber a){\n        return (*this) += a;\n    }\n    Nimber& operator*=(const\
    \ Nimber a){\n        n = p64(n,a.n);\n        return (*this);\n    }\n    Nimber\
    \ operator+(const Nimber&a) const{\n        Nimber res(*this);\n        return\
    \ res+=a;\n    }\n    Nimber operator-(const Nimber&a) const{\n        Nimber\
    \ res(*this);\n        return res-=a;\n    }\n    Nimber operator*(const Nimber&a)\
    \ const{\n        Nimber res(*this);\n        return res*=a;\n    }\n    bool\
    \ operator==(const Nimber&a){\n        return n == a.n;\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream&os,const Nimber&a){\n        os << a.n;\n        return\
    \ os;\n    }\n    Nimber square(){\n        return (*this)*(*this);\n    }\n \
    \   static uint64_t sq64(uint64_t x,int bit){\n        if(bit<=8) return sq_table[x];\n\
    \        bit >>= 1;\n        uint64_t a = x & (((uint64_t)1<<bit) - 1);\n    \
    \    uint64_t c = x >> bit; \n        uint64_t b = sq64(p32(c,(uint64_t)1<<(bit-1))^a,bit);\n\
    \        uint64_t d = sq64(c,bit);\n        return (d<<bit)|b;\n    }\n\n    Nimber\
    \ sqrt(){\n        return Nimber(sq64(n,64));\n    }\n\n    static uint64_t inv64(uint64_t\
    \ x,int bit){\n        if(bit<=8) return inv_table[x];\n        bit >>= 1;\n \
    \       uint64_t a = x & (((uint64_t)1<<bit) - 1);\n        uint64_t c = x >>\
    \ bit;\n        uint64_t tmp = p32(a^c,a) ^ p32(p32(c,c),(uint64_t)1<<(bit-1));\n\
    \        tmp = inv64(tmp,bit); \n        uint64_t b = p32(tmp,a^c);\n        uint64_t\
    \ d = p32(tmp,c);\n        return (d<<bit)|b;\n    }\n\n    Nimber inv(){\n  \
    \      return Nimber(inv64(n,64));\n    }\n    Nimber operator/=(const Nimber\
    \ a){\n        n = p64(n,inv64(a.n,64));\n        return (*this);\n    }\n   \
    \ Nimber operator/(const Nimber&a) const{\n        Nimber res(*this);\n      \
    \  return res/=a;\n    }\n    static uint64_t solve64(uint64_t x,int bit){\n \
    \       if(x==0) return 0;\n        bit >>= 1;\n        uint64_t a = x & (((uint64_t)1<<bit)-1);\n\
    \        uint64_t c = x >> bit;\n        uint64_t d = solve64(c,bit);\n\n    \
    \    uint64_t tmp = p32(p32(d,d),(uint64_t)1<<(bit-1)) ^ a;\n        if(tmp>=((uint64_t)1<<(bit-1))){\n\
    \            d ^= 1;\n            tmp = p32(p32(d,d),(uint64_t)1<<(bit-1)) ^ a;\n\
    \        }\n        uint64_t b = solve64(tmp,bit);\n        return (d<<bit)|b;\n\
    \    }\n\n    static std::vector<Nimber> solve(Nimber b,Nimber c){\n        std::vector<Nimber>\
    \ res;\n        if(b.val()==0){\n            res.push_back(c.sqrt());\n      \
    \      return res;\n        }\n        c = c / (b*b);\n        Nimber tmp = solve64(c.val(),64);\n\
    \        res.push_back(b*tmp);\n        res.push_back(res[0]+Nimber(b));\n   \
    \     return res;\n    }\n\n};\n\nusing nimber = Nimber;\nstatic int Nimber_init\
    \ = Nimber::init();\n\n/**\n * @brief Nimber\n * @docs docs/math/nimber.md\n*/\n\
    \n"
  code: "#pragma once\n\n#include<iostream>\n#include<cstdint>\n#include<array>\n\
    #include<vector>\n\nstruct Nimber{\n    using ul = unsigned long long;\n    using\
    \ Nimber_table = std::array<std::array<uint8_t,256>,256>;\n    using Sqrt_table\
    \ = std::array<uint8_t,256>;\n    using Inv_table = Sqrt_table;\n    ul n;\n \
    \   Nimber():n(0){}\n    Nimber(ul _n):n(_n){}\n    static inline Nimber_table\
    \ table;\n    static inline Sqrt_table sq_table; \n    static inline Inv_table\
    \ inv_table;\n    const static inline uint32_t U32_MAX = ~((uint32_t)0);\n   \
    \ const static inline uint16_t U16_MAX = ~((uint16_t)0);\n    const static inline\
    \ uint8_t U8_MAX = ~((uint8_t)0);\n    \n    constexpr static int init(){\n  \
    \      const int L = 8;\n        table[1][1] = 1;\n        for(int i = 1;i<L;i<<=1){\n\
    \            int mask = (1<<i) - 1;\n            for(int j = 1<<i;j<1<<(2*i);j++){\n\
    \                for(int k = 1;k<=j;k++){\n                    int a = j & mask;\n\
    \                    int b = k & mask;\n                    int c = j >> i;\n\
    \                    int d = k >> i;\n                    int e = table[a][b];\n\
    \                    table[j][k] = table[k][j] = (table[a^c][b^d]^e) << i | (table[table[c][d]][1<<(i-1)]\
    \ ^ e);\n                }\n            }\n        }\n        for(int i = 0;i<256;i++)\
    \ sq_table[table[i][i]] = i;\n        for(int i = 1;i<256;i++){\n            for(int\
    \ j = 1;j<256;j++){\n                if(table[i][j]==1){\n                   \
    \ inv_table[i] = j;\n                    break;\n                }\n         \
    \   }\n        }\n        return 0;\n    }\n\n    static uint16_t p16(uint16_t\
    \ x,uint16_t y){\n        uint8_t a = x & U8_MAX;\n        uint8_t b = y & U8_MAX;\n\
    \        uint8_t c = x >> 8;\n        uint8_t d = y >> 8;\n        uint8_t e =\
    \ table[a][b];\n        return (uint16_t)(table[a^c][b^d]^e) << 8 | (table[table[c][d]][1<<7]\
    \ ^ e);\n    }\n    static uint16_t h16(uint16_t x,uint16_t y){\n        uint8_t\
    \ a = x & U8_MAX;\n        uint8_t c = x >> 8;\n        uint8_t d = y >> 8;\n\
    \        return (uint16_t)(table[a^c][d]) << 8 | (table[table[c][d]][1<<7]);\n\
    \    }\n    static uint32_t p32(uint32_t x,uint32_t y){\n        uint16_t a =\
    \ x & U16_MAX;\n        uint16_t b = y & U16_MAX;\n        uint16_t c = x >> 16;\n\
    \        uint16_t d = y >> 16;\n        uint16_t e = p16(a,b);\n        return\
    \ (uint32_t)(p16(a^c,b^d)^e) << 16 | (h16(p16(c,d),1<<15) ^ e);\n    }\n    static\
    \ uint32_t h32(uint32_t x,uint32_t y){\n        uint16_t a = x & U16_MAX;\n  \
    \      uint16_t c = x >> 16;\n        uint16_t d = y >> 16;\n        return (uint32_t)(p16(a^c,d))\
    \ << 16 | h16(p16(c,d),1<<15);\n    }\n    static uint64_t p64(uint64_t x,uint64_t\
    \ y){\n        uint32_t a = x & U32_MAX;\n        uint32_t b = y & U32_MAX;\n\
    \        uint32_t c = x >> 32;\n        uint32_t d = y >> 32;\n        uint32_t\
    \ e = p32(a,b);\n        return (uint64_t)(p32(a^c,b^d)^e) << 32 | (h32(p32(c,d),1<<31)\
    \ ^ e);\n    }\n    ul val(){return this->n;}\n    Nimber operator-() const{\n\
    \        return Nimber(*this);\n    }\n    Nimber& operator+=(const Nimber a){\n\
    \        n ^= a.n;\n        return *this;\n    }\n    Nimber& operator-=(const\
    \ Nimber a){\n        return (*this) += a;\n    }\n    Nimber& operator*=(const\
    \ Nimber a){\n        n = p64(n,a.n);\n        return (*this);\n    }\n    Nimber\
    \ operator+(const Nimber&a) const{\n        Nimber res(*this);\n        return\
    \ res+=a;\n    }\n    Nimber operator-(const Nimber&a) const{\n        Nimber\
    \ res(*this);\n        return res-=a;\n    }\n    Nimber operator*(const Nimber&a)\
    \ const{\n        Nimber res(*this);\n        return res*=a;\n    }\n    bool\
    \ operator==(const Nimber&a){\n        return n == a.n;\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream&os,const Nimber&a){\n        os << a.n;\n        return\
    \ os;\n    }\n    Nimber square(){\n        return (*this)*(*this);\n    }\n \
    \   static uint64_t sq64(uint64_t x,int bit){\n        if(bit<=8) return sq_table[x];\n\
    \        bit >>= 1;\n        uint64_t a = x & (((uint64_t)1<<bit) - 1);\n    \
    \    uint64_t c = x >> bit; \n        uint64_t b = sq64(p32(c,(uint64_t)1<<(bit-1))^a,bit);\n\
    \        uint64_t d = sq64(c,bit);\n        return (d<<bit)|b;\n    }\n\n    Nimber\
    \ sqrt(){\n        return Nimber(sq64(n,64));\n    }\n\n    static uint64_t inv64(uint64_t\
    \ x,int bit){\n        if(bit<=8) return inv_table[x];\n        bit >>= 1;\n \
    \       uint64_t a = x & (((uint64_t)1<<bit) - 1);\n        uint64_t c = x >>\
    \ bit;\n        uint64_t tmp = p32(a^c,a) ^ p32(p32(c,c),(uint64_t)1<<(bit-1));\n\
    \        tmp = inv64(tmp,bit); \n        uint64_t b = p32(tmp,a^c);\n        uint64_t\
    \ d = p32(tmp,c);\n        return (d<<bit)|b;\n    }\n\n    Nimber inv(){\n  \
    \      return Nimber(inv64(n,64));\n    }\n    Nimber operator/=(const Nimber\
    \ a){\n        n = p64(n,inv64(a.n,64));\n        return (*this);\n    }\n   \
    \ Nimber operator/(const Nimber&a) const{\n        Nimber res(*this);\n      \
    \  return res/=a;\n    }\n    static uint64_t solve64(uint64_t x,int bit){\n \
    \       if(x==0) return 0;\n        bit >>= 1;\n        uint64_t a = x & (((uint64_t)1<<bit)-1);\n\
    \        uint64_t c = x >> bit;\n        uint64_t d = solve64(c,bit);\n\n    \
    \    uint64_t tmp = p32(p32(d,d),(uint64_t)1<<(bit-1)) ^ a;\n        if(tmp>=((uint64_t)1<<(bit-1))){\n\
    \            d ^= 1;\n            tmp = p32(p32(d,d),(uint64_t)1<<(bit-1)) ^ a;\n\
    \        }\n        uint64_t b = solve64(tmp,bit);\n        return (d<<bit)|b;\n\
    \    }\n\n    static std::vector<Nimber> solve(Nimber b,Nimber c){\n        std::vector<Nimber>\
    \ res;\n        if(b.val()==0){\n            res.push_back(c.sqrt());\n      \
    \      return res;\n        }\n        c = c / (b*b);\n        Nimber tmp = solve64(c.val(),64);\n\
    \        res.push_back(b*tmp);\n        res.push_back(res[0]+Nimber(b));\n   \
    \     return res;\n    }\n\n};\n\nusing nimber = Nimber;\nstatic int Nimber_init\
    \ = Nimber::init();\n\n/**\n * @brief Nimber\n * @docs docs/math/nimber.md\n*/\n\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: math/nimber.hpp
  requiredBy:
  - test/library_checker/nim_product_64.cpp
  timestamp: '2023-11-28 16:08:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/nimber.hpp
layout: document
redirect_from:
- /library/math/nimber.hpp
- /library/math/nimber.hpp.html
title: Nimber
---
## Nimber

#### 概要

和が bitwise xor の有限体。位数は $2^{64}$。積は Nim Product。使い方は基本的に ACL の modint と同じ。

参考
https://kyopro-friends.hatenablog.com/entry/2020/04/07/195850
https://natsugiri.hatenablog.com/entry/2020/03/29/073605

#### 使い方
##### コンストラクタ
`Nimber()`：0が格納される。
`Nimber(uint64 x)`：xが格納される。

##### 演算
`- Nimber`
`Nimber + Nimber`
`Nimber - Nimber`
`Nimber * Nimber`
`Nimber / Nimber`
`Nimber += Nimber`
`Nimber -= Nimber`
`Nimber *= Nimber`
`Nimber /= Nimber`
`Nimber == Nimber`
が可能。

##### メソッド
`uint64 x.val()`：値を返す。
`Nimber x.inv()`：$x\otimes y=1$ となる $y$ を返す。
`Nimber x.sqrt()`：$y \otimes y = x$ となる $y$ を返す。
`vector<Nimber> Nimber::solve(Nimber b,Nimber c)`：$x\otimes x \oplus b \otimes x \oplus c = 0$ となる $x$ をすべて返す。

計算量はどれも、 $w=64$ として、 $O(w^{\log 3}\log w)$ とか。


