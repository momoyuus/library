#include<vector>
#include<cassert>
template <typename T>
T Lagrange_arithmetic_point(std::vector<T>a,std::vector<T>b,long long k){
    int n = a.size();
    assert(a.size()==b.size());
    assert(n>0);

    T ans = 0;
    T inv = 1;
    for(int i = 1;i<n;i++){
        inv *= (a[0]-a[i]).inv();
    }

    std::vector<T> use(n,1);
    T now = 1;
    for(int i = 0;i<n;i++){
        use[i] *= now;
        now *= T(k) - a[i];
    }
    now = 1;
    for(int i = n-1;i>=0;i--){
        use[i] *= now;
        now *= T(k) - a[i];
    }

    for(int i = 0;i<n;i++){
        if(i>0) inv *= (a[i]-a[0]).inv();
        ans += b[i] * use[i] * inv;
        if(i+1<n) inv *= a[i] - a[n-1];
    }

    return ans;
}
/**
 * @brief Lagrange_arithmetic_point
 * @docs docs/polynomial/Lagrange_arithmetic_point.md
*/
