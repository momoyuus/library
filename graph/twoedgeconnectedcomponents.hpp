using namespace std;

#include<vector>
#include<cassert>
struct two_edge_connected_components_graph{
    struct edge{
        int to,id;
        edge(){}
        edge(int _to,int _id):to(_to),id(_id){

        }
    };

    int n,cnt,now;
    vector<vector<edge>> g;
    vector<int> cmp;
    vector<vector<int>> G;
    two_edge_connected_components_graph(int _n):n(_n){
        cnt = 0;
        now = 0;
        g.resize(n);
        cmp.resize(n);
    }
    
    void add_edge(int u,int v){
        assert(0<=u&&u<n);
        assert(0<=v&&v<n);
        g[u].push_back({v,cnt});
        g[v].push_back({u,cnt});
        cnt++;
    }

    void build(){
        vector<int> vis(n,0),use(cnt,0),ord(n,-1),low(n,1e9);
        auto dfs = [&](auto dfs,int ni) -> void {
            vis[ni] = 1;
            for(auto&e:g[ni]){
                if(use[e.id]) continue;
                if(vis[e.to]) {
                    use[e.id] = 2;
                    low[ni] = min(low[ni],ord[e.to]);
                }else{
                    use[e.id] = 1;
                    ord[e.to] = low[e.to] = ord[ni] + 1;
                    dfs(dfs,e.to);
                    low[ni] = min(low[ni],low[e.to]);
                }
            }
        };

        auto compress = [&](auto compress,int ni,int t) -> void {
            if(G.size()>=t) G.push_back(vector<int>(0));
            G[t].push_back(ni);
            cmp[ni] = t;
            for(auto&e:g[ni]) if(use[e.id]==1&&ord[e.to]>ord[ni]){
                if(ord[ni]<low[e.to]) compress(compress,e.to,now++);
                else compress(compress,e.to,cmp[ni]);
            }
        };
        
        for(int i = 0;i<n;i++) if(vis[i]==0){
            ord[i] = low[i] = 0;
            dfs(dfs,i);
            compress(compress,i,now++);
        }
    }

    int operator[] (int u){
        assert(0<=u&&u<n);
        return cmp[u];
    }

    vector<vector<int>> graph(){
        return G;
    }

    vector<vector<int>> groups(){
        vector<vector<int>> res(now);
        for(int i = 0;i<n;i++) res[cmp[i]].push_back(i);
        return res;
    }
};
/**
 * @brief Two-Edge-Connected Components
*/
