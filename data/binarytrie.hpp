#include<vector>
template<typename T,int LOG = 60>
struct binary_trie{
    using ull = unsigned long long;
    struct node{
        int l,r;
        T dat;
        int cnt;
        node():l(-1),r(-1){
            cnt = 0;
        }
    };

    vector<node> nodes;
    ull lazy;
    int root;

    binary_trie(){
        root = 0;
        lazy = 0;
        nodes.push_back(node());
    }

    void push(int&i){
        i = nodes.size();
        nodes.push_back(node());
    }

    int insert(ull x){
        int ni = root;
        int k = LOG;
        for(int k = LOG;k>=0;k--){
            nodes[ni].cnt++;
            if(x>>k&1){
                if(nodes[ni].r==-1) push(nodes[ni].r);
                ni = nodes[ni].r;
            }else{
                if(nodes[ni].l==-1) push(nodes[ni].l);
                ni = nodes[ni].l;
            }
        }
        nodes[ni].cnt++;
        return ni;
    }

    void erase(ull x){
        int ni = 0;
        int k = LOG;
        for(int k = LOG;k>=0;k--){
            nodes[ni].cnt--;
            if(x>>k&1) ni = nodes[ni].r;
            else ni = nodes[ni].l;
        }
        nodes[ni].cnt--;
    }

    void xor_all(ull x){
        lazy ^= x;
    }

    ull min_element(){
        int ni = 0;
        int k = LOG;
        ull res = 0;
        for(int k = LOG;k>=0;k--){
            if(lazy>>k&1){
                if(nodes[ni].r!=-1&&nodes[nodes[ni].r].cnt>0){
                    res += 1ull << k;
                    ni = nodes[ni].r;
                }else{
                    ni = nodes[ni].l;
                }
            }else{
                if(nodes[ni].l!=-1&&nodes[nodes[ni].l].cnt>0){
                    ni = nodes[ni].l;
                }else{
                    res += 1ull << k;
                    ni = nodes[ni].r;
                }
            }
        }
        return res^lazy;
    }
};
/**
 * @brief BinaryTrie
*/