#pragma once

#include<iostream>
#include<cstdint>
#include<array>
#include<vector>

struct Nimber{
    using ul = unsigned long long;
    using Nimber_table = std::array<std::array<uint8_t,256>,256>;
    using Sqrt_table = std::array<uint8_t,256>;
    using Inv_table = Sqrt_table;
    ul n;
    Nimber():n(0){}
    Nimber(ul _n):n(_n){}
    static inline Nimber_table table;
    static inline Sqrt_table sq_table; 
    static inline Inv_table inv_table;
    const static inline uint32_t U32_MAX = ~((uint32_t)0);
    const static inline uint16_t U16_MAX = ~((uint16_t)0);
    const static inline uint8_t U8_MAX = ~((uint8_t)0);
    
    constexpr static int init(){
        const int L = 8;
        table[1][1] = 1;
        for(int i = 1;i<L;i<<=1){
            int mask = (1<<i) - 1;
            for(int j = 1<<i;j<1<<(2*i);j++){
                for(int k = 1;k<=j;k++){
                    int a = j & mask;
                    int b = k & mask;
                    int c = j >> i;
                    int d = k >> i;
                    int e = table[a][b];
                    table[j][k] = table[k][j] = (table[a^c][b^d]^e) << i | (table[table[c][d]][1<<(i-1)] ^ e);
                }
            }
        }
        for(int i = 0;i<256;i++) sq_table[table[i][i]] = i;
        for(int i = 1;i<256;i++){
            for(int j = 1;j<256;j++){
                if(table[i][j]==1){
                    inv_table[i] = j;
                    break;
                }
            }
        }
        return 0;
    }

    static uint16_t p16(uint16_t x,uint16_t y){
        uint8_t a = x & U8_MAX;
        uint8_t b = y & U8_MAX;
        uint8_t c = x >> 8;
        uint8_t d = y >> 8;
        uint8_t e = table[a][b];
        return (uint16_t)(table[a^c][b^d]^e) << 8 | (table[table[c][d]][1<<7] ^ e);
    }
    static uint16_t h16(uint16_t x,uint16_t y){
        uint8_t a = x & U8_MAX;
        uint8_t c = x >> 8;
        uint8_t d = y >> 8;
        return (uint16_t)(table[a^c][d]) << 8 | (table[table[c][d]][1<<7]);
    }
    static uint32_t p32(uint32_t x,uint32_t y){
        uint16_t a = x & U16_MAX;
        uint16_t b = y & U16_MAX;
        uint16_t c = x >> 16;
        uint16_t d = y >> 16;
        uint16_t e = p16(a,b);
        return (uint32_t)(p16(a^c,b^d)^e) << 16 | (h16(p16(c,d),1<<15) ^ e);
    }
    static uint32_t h32(uint32_t x,uint32_t y){
        uint16_t a = x & U16_MAX;
        uint16_t c = x >> 16;
        uint16_t d = y >> 16;
        return (uint32_t)(p16(a^c,d)) << 16 | h16(p16(c,d),1<<15);
    }
    static uint64_t p64(uint64_t x,uint64_t y){
        uint32_t a = x & U32_MAX;
        uint32_t b = y & U32_MAX;
        uint32_t c = x >> 32;
        uint32_t d = y >> 32;
        uint32_t e = p32(a,b);
        return (uint64_t)(p32(a^c,b^d)^e) << 32 | (h32(p32(c,d),1<<31) ^ e);
    }
    ul val(){return this->n;}
    Nimber operator-() const{
        return Nimber(*this);
    }
    Nimber& operator+=(const Nimber a){
        n ^= a.n;
        return *this;
    }
    Nimber& operator-=(const Nimber a){
        return (*this) += a;
    }
    Nimber& operator*=(const Nimber a){
        n = p64(n,a.n);
        return (*this);
    }
    Nimber operator+(const Nimber&a) const{
        Nimber res(*this);
        return res+=a;
    }
    Nimber operator-(const Nimber&a) const{
        Nimber res(*this);
        return res-=a;
    }
    Nimber operator*(const Nimber&a) const{
        Nimber res(*this);
        return res*=a;
    }
    bool operator==(const Nimber&a){
        return n == a.n;
    }
    friend std::ostream& operator<<(std::ostream&os,const Nimber&a){
        os << a.n;
        return os;
    }
    Nimber square(){
        return (*this)*(*this);
    }
    static uint64_t sq64(uint64_t x,int bit){
        if(bit<=8) return sq_table[x];
        bit >>= 1;
        uint64_t a = x & (((uint64_t)1<<bit) - 1);
        uint64_t c = x >> bit; 
        uint64_t b = sq64(p32(c,(uint64_t)1<<(bit-1))^a,bit);
        uint64_t d = sq64(c,bit);
        return (d<<bit)|b;
    }

    Nimber sqrt(){
        return Nimber(sq64(n,64));
    }

    static uint64_t inv64(uint64_t x,int bit){
        if(bit<=8) return inv_table[x];
        bit >>= 1;
        uint64_t a = x & (((uint64_t)1<<bit) - 1);
        uint64_t c = x >> bit;
        uint64_t tmp = p32(a^c,a) ^ p32(p32(c,c),(uint64_t)1<<(bit-1));
        tmp = inv64(tmp,bit); 
        uint64_t b = p32(tmp,a^c);
        uint64_t d = p32(tmp,c);
        return (d<<bit)|b;
    }

    Nimber inv(){
        return Nimber(inv64(n,64));
    }
    Nimber operator/=(const Nimber a){
        n = p64(n,inv64(a.n,64));
        return (*this);
    }
    Nimber operator/(const Nimber&a) const{
        Nimber res(*this);
        return res/=a;
    }
    static uint64_t solve64(uint64_t x,int bit){
        if(x==0) return 0;
        bit >>= 1;
        uint64_t a = x & (((uint64_t)1<<bit)-1);
        uint64_t c = x >> bit;
        uint64_t d = solve64(c,bit);

        uint64_t tmp = p32(p32(d,d),(uint64_t)1<<(bit-1)) ^ a;
        if(tmp>=((uint64_t)1<<(bit-1))){
            d ^= 1;
            tmp = p32(p32(d,d),(uint64_t)1<<(bit-1)) ^ a;
        }
        uint64_t b = solve64(tmp,bit);
        return (d<<bit)|b;
    }

    static std::vector<Nimber> solve(Nimber b,Nimber c){
        std::vector<Nimber> res;
        if(b.val()==0){
            res.push_back(c.sqrt());
            return res;
        }
        c = c / (b*b);
        Nimber tmp = solve64(c.val(),64);
        res.push_back(b*tmp);
        res.push_back(res[0]+Nimber(b));
        return res;
    }

};

using nimber = Nimber;
static int Nimber_init = Nimber::init();

