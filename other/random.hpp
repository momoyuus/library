#include <random>
#include <chrono>
int64_t seed = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
mt19937_64 rnd(seed);
int random(int l,int r){
    uniform_int_distribution<int> now(l,r);
    return now(rnd);
}