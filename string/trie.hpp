#include<vector>
#include<string>
using namespace std;

template<int char_size,char margin,typename T,T (*e)()>
struct trie{
    struct node{
        int nxt[char_size];
        int par;
        T dat;
        node(int p):par(p){
            memset(nxt,-1,sizeof(nxt));
            dat = e();
        }
    };

    vector<node> nodes;
    int root;
    trie(){
        root = 0;
        nodes.push_back(node(-1));
    }

    int add(int ni,int i,const string&s){
        if(i==(int)s.size()) return ni;
        int now = s[i] - margin;
        if(nodes[ni].nxt[now]==-1){
            nodes[ni].nxt[now] = nodes.size();
            nodes.push_back(node(ni));
        }
        return add(nodes[ni].nxt[now],i+1,s);
    }

    int add(const string&s){
        return add(root,0,s);
    }

    int move(int ni,int i,const string&s){
        if(i==(int)s.size()) return ni;
        if(ni==-1) return ni;
        int now = s[i] - margin;
        return move(nodes[ni].nxt[now],i+1,s);
    }

    int move(int ni,const string&s){
        return move(ni,0,s);
    }

    int move(int ni,const char&c){
        string s(1,c);
        return move(ni,0,s);
    }

    int getpar(int ni){
        return nodes[ni].par;
    }

    inline T& operator[](int i) {
        return nodes[i].dat;
    }

    inline int size(){
        return nodes.size();
    }
};

/**
 * @brief Trie
 * @docs docs/string/trie.hpp
*/
