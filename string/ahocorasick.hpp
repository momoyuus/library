#pragma once

#include"string/trie.hpp"

#include<vector>
#include<cstring>
using namespace std;

template<int char_size,int margin,typename T,T (*e)()>
struct aho_corasick:trie<char_size,margin,T,e> {
    vector<int> fail;
    vector<vector<int>> match;
    aho_corasick(){}

    void build(){
        fail = vector<int>(this->size(),this->root);
        match = vector<vector<int>>(this->size(),vector<int>(char_size,-1));
        vector<pair<int,int>> que;
        vector<int> vis(this->size(),0);
        que.push_back(make_pair(this->root,this->root));
        vis[0] = 1;
        for(int i = 0;i<(int)que.size();i++){
            int ni = que[i].first;
            int last = que[i].second;
            int nj = this->getpar(ni);
            if(ni!=this->root){
                fail[ni] = match[fail[nj]][last];
                if(fail[ni]==ni) fail[ni] = this->root;
                for(int j = 0;j<char_size;j++){
                    if(this->nodes[ni].nxt[j]!=-1) match[ni][j] = this->nodes[ni].nxt[j];
                    else match[ni][j] = match[fail[ni]][j];
                }
            }else{
                for(int j = 0;j<char_size;j++){
                    if(this->nodes[ni].nxt[j]!=-1) match[ni][j] = this->nodes[ni].nxt[j];
                    else match[ni][j] = ni;
                }
            }
            for(int j = 0;j<char_size;j++){
                if(this->nodes[ni].nxt[j]!=-1) que.push_back(make_pair(this->nodes[ni].nxt[j],j));
            }
        }
    }
    int move(int ni,int i,const string&s){
        if(i==(int)s.size()) return ni;
        return move(match[ni][s[i]-margin],i+1,s);
    }
    int move(int ni,const string&s){
        return move(ni,0,s);
    }
    int move(int ni,const char&c){
        string s(1,c);
        return move(ni,0,s);
    }
};

/**
 * @brief Aho-Corasick
 * @docs docs/string/aho-corasick.md
*/