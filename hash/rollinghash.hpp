#include "hash/hashint.hpp"

#include<cassert>
template<typename H,typename T>
struct rolling_hash{
    using ull = unsigned long long;
    struct hash{
        H x,b;
        hash():x(0),b(1){}
        hash(ull _x,ull _b):x(_x),b(_b){}
        hash(H _x,H _b):x(_x),b(_b){}

        ull val(){
            return x.val();
        }

        hash operator+=(const hash a){
            x = x * a.b + a.x;
            b *= a.b;
            return (*this);
        }

        hash operator+(const hash a){
            hash res(*this);
            return res += a;
        }

        bool operator==(const hash a){
            return x == a.x;
        }

        bool operator<(const hash a){
            return x < a.x;
        }
    };

    int n;
    static H base;
    vector<H> sum,powb;
    rolling_hash(T x){
        n = x.size();
        sum = vector<H>(n+1,0);
        powb = vector<H>(n+1,1);
        for(int i = 0;i<n;i++){
            sum[i+1] = sum[i] * base + x[i];
            powb[i+1] = powb[i] * base;
        }
    }

    hash get(int l,int r){
        assert(0<=l&&l<r&&r<=n);
        return hash(sum[r]-sum[l]*powb[r-l],powb[r-l]);
    }

};

using rhash = rolling_hash<hashint,string>;
using hint = rhash::hash;
template<>
hashint rhash::base = hashint::get_base();

/**
 * @brief Rolling Hash
 * @docs docs/hash/rollinghash.hpp
*/