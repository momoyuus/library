using namespace std;

#include<vector>
#include<chrono>
#include<random>
struct hashint{
    using ull = unsigned long long;

    ull x;
    const static ull mod = (1ll<<61) - 1;
    hashint():x(0){}

    hashint(ull _x):x(_x){}

    hashint& operator+=(const hashint a) {
        x += a.x;
        if(x>=mod) x -= mod;
        return (*this);
    }

    hashint& operator-=(const hashint a) {
        x += mod - a.x;
        if(x>=mod) x -= mod;
        return (*this);
    }

    hashint& operator*=(const hashint a) {
        x = mul(x,a.x);
        return (*this);
    }

    hashint operator+(const hashint a) const {
        hashint res(*this);
        return res += a;
    }

    hashint operator-(const hashint a) const {
        hashint res(*this);
        return res -= a;
    }

    hashint operator*(const hashint a) const {
        hashint res(*this);
        return res *= a;
    }

    ull val(){
        return x;
    }

    bool operator==(const hashint a) const {
        return x == a.x;
    }
    
    bool operator<(const hashint a) const {
        return a < a.x;
    }

    static ull mul(const ull a,const ull b) {\
        ull au = a >> 31;
        ull ad = a & ((1ull<<31)-1);
        ull bu = b >> 31;
        ull bd = b & ((1ull<<31)-1);
        ull res = au * bu * 2;
        ull mid = au * bd + ad * bu;
        ull midu = mid >> 30;
        ull midd = mid & ((1ull<<30)-1);
        res += midu + midd * (1ull<<31);
        res += ad * bd;
        res = (res>>61) + (res&((1ull<<61)-1));
        if(res>=mod) res -= mod;
        return res;
    }

    static ull modpow(ull x,ull k){
        ull res = 1;
        while(k){
            if(k&1) res = mul(res,x);
            x = mul(x,x);
            k >>= 1;
        }
        return x;
    }

    static bool isPrimitive(ull x) {
        for (auto &now:vector<ull>{2, 3, 5, 7, 11, 13, 31, 41, 61, 151, 331, 1321})
            if (modpow(x,(mod-1)/now)<=1) return false;
        return true;
    }
    
    static hashint get_base(){
        long long seed = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
        mt19937_64 rnd(seed);
        uniform_int_distribution<ull> now(1,mod-1);
        ull base{};
        while (true){
            base = now(rnd);
            if(isPrimitive(base)) break;
        }
        return base;
    }
};
/**
 * @brief Hashint
 * @docs docs/hash/hashint.md
*/