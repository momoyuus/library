#include<vector>
#include<cassert>
std::vector<long long> min_plus_convolution(std::vector<long long>&a,std::vector<long long>&b){
    int n = a.size();
    int m = b.size();
    assert(n>0&&m>0);
    std::vector<long long> res(n+m-1);
    int ni = 0;
    int nj = 0;
    res[0] = a[0] + b[0];
    while(ni+1<n||nj+1<m){
        long long use = 9e18;
        if(ni+1<n) use = a[ni+1] - a[ni];
        if(nj+1<m) use = std::min(use,b[nj+1]-b[nj]);
        if(ni+1<n&&a[ni+1]-a[ni]==use) ni++;
        else nj++;
        res[ni+nj] = res[ni+nj-1] + use; 
    }
    return res;
}
