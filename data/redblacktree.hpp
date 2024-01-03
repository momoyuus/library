#include<vector>
#include<cassert>

using namespace std;
using ll = long long;

const int MAX_N = (int)1e7 + 5e6;

struct node{
    node *l,*r;
    bool color; // 0:black 1:red
    ll rank,size;
    char val;
    static int node_count;

    void *operator new(size_t){
        static node pool[MAX_N];
        return pool + node_count++;
    }

    static void delete_all(){
        node::node_count = 0;
    }

    static int getcount(){
        return node::node_count;
    }

};
int node::node_count = 0;

template<typename T,T (*op)(T,T),T (*e)(),int MAX_N = 10000000,typename size_int = int>
struct red_black_tree{

    using node_ptr = node*;
    const bool BLACK = false;
    const bool RED = true;

    static int getcount(){
        return node::getcount();
    }

    static void clear(){
        node::delete_all();
    }

    node_ptr make_tree(size_int n){
        if(n==1) return make_leaf(e());
        return merge(make_tree(n>>1),make_tree((n+1)>>1));
    }

    node_ptr make_tree(vector<T>&x,size_int L,size_int R){
        if(R-L==1) return make_leaf(x[L]);
        size_int mid = (R+L) / 2;
        return merge(make_tree(x,L,mid),make_tree(x,mid,R));
    }

    node_ptr make_tree(vector<T>&x){
        size_int n = x.size();
        return make_tree(x,0,n);
    }

    node_ptr make_node(const node_ptr l,const node_ptr r,const bool color) const {
        node_ptr res = new node;
        res->l = l;
        res-> r = r;
        res->size = l->size + r->size;
        res->rank = l->rank + 1 - l->color;
        res->color = color;
        res->val = op(l->val,r->val);
        return res;
    }

    node_ptr make_leaf(const T x){
        node_ptr res = new node;
        res->l = res->r = nullptr;
        res->size = 1;
        res->rank = 0;
        res->val = x;
        res->color = BLACK;
        return res;
    }

    node_ptr mergesub(const node_ptr l,const node_ptr r){
        if(l->rank==r->rank) return make_node(l,r,1);
        if(l->rank<r->rank){
            node_ptr res = mergesub(l,r->l);
            if(r->color==BLACK&&res->color==RED&&res->l->color==RED){
                if(r->r->color==BLACK) return make_node(res->l,make_node(res->r,r->r,RED),BLACK);
                else return make_node(make_node(res->l,res->r,BLACK),make_node(r->r->l,r->r->r,BLACK),RED);
            }else{
                return make_node(res,r->r,r->color);
            }
        }else{
            node_ptr res = mergesub(l->r,r);
            if(l->color==BLACK&&res->color==RED&&res->l->color==RED){
                if(l->l->color==BLACK) return make_node(make_node(l->l,res->l,RED),res->r,BLACK);
                else return make_node(make_node(l->l->l,l->l->r,BLACK),make_node(res->l,res->r,BLACK),RED);
            }else{
                return make_node(l->l,res,l->color);
            }
        }
    }

    node_ptr merge(const node_ptr l,const node_ptr r){
        if(!l) return r;
        if(!r) return l;
        node_ptr res = mergesub(l,r);
        if(res->color==RED) return make_node(res->l,res->r,BLACK);
        return res;
    }

    node_ptr toroot(const node_ptr p){
        if(!p) return nullptr;
        if(p->color==BLACK) return p;
        return make_node(p->l,p->r,BLACK);
    }

    pair<node_ptr,node_ptr> split(const node_ptr p,int k){
        if(!p) return make_pair(nullptr,nullptr);
        if(k==0) return make_pair(nullptr,toroot(p));
        if(k==p->size) return make_pair(toroot(p),nullptr);
        if(k<p->l->size) {
            auto now = split(p->l,k);
            return make_pair(now.first,merge(now.second,toroot(p->r)));
        }else if(p->l->size<k){
            auto now = split(p->r,k-p->l->size);
            return make_pair(merge(toroot(p->l),now.first),now.second);
        }else return make_pair(toroot(p->l),toroot(p->r));
    }

    inline size_int size(const node_ptr p) const {
        if(!p) return 0;
        return p->size;
    }

    T get(const node_ptr&p,size_int i){
        assert(i<p->size);
        if(p->rank==0) return p->val;
        if(i<p->l->size) return this->get(p->l,i);
        else return this->get(p->r,i-p->l->size);
    }

    node_ptr set(const node_ptr&p,size_int i,T x){
        assert(i<p->size);
        if(p->size==1){
            return make_leaf(x);
        }else{
            if(i<p->l->size) return make_node(this->set(p->l,i,x),p->r,p->color);
            else return make_node(p->l,this->set(p->r,i-p->l->size,x),p->color);
        }
    }

    T prod(const node_ptr p,size_int L,size_int R){
        assert(0<=L&&L<R&&R<=p->size);
        if(L==0&&p->size==R) return p->val;
        if(R<=p->l->size) return this->prod(p->l,L,R);
        else if(p->l->size<=L) return this->prod(p->r,L-p->l->size,R-p->l->size);
        else return op(this->prod(p->l,L,p->l->size),this->prod(p->r,0,R-p->l->size));
    }
};

/**
 * @brief Red-Black Tree
 * 
*/