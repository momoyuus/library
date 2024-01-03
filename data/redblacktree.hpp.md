---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Red-Black Tree
    links: []
  bundledCode: "#line 1 \"data/redblacktree.hpp\"\n#include<vector>\n#include<cassert>\n\
    \nusing namespace std;\nusing ll = long long;\n\nconst int MAX_N = (int)1e7 +\
    \ 5e6;\n\nstruct node{\n    node *l,*r;\n    bool color; // 0:black 1:red\n  \
    \  ll rank,size;\n    int val;\n    static int node_count;\n\n    void *operator\
    \ new(size_t){\n        static node pool[MAX_N];\n        return pool + node_count++;\n\
    \    }\n\n    static void delete_all(){\n        node::node_count = 0;\n    }\n\
    \n    static int getcount(){\n        return node::node_count;\n    }\n\n};\n\
    int node::node_count = 0;\n\ntemplate<typename T,T (*op)(T,T),T (*e)(),int MAX_N\
    \ = 10000000,typename size_int = int>\nstruct red_black_tree{\n\n    using node_ptr\
    \ = node*;\n    const bool BLACK = false;\n    const bool RED = true;\n\n    static\
    \ int getcount(){\n        return node::getcount();\n    }\n\n    static void\
    \ clear(){\n        node::delete_all();\n    }\n\n    node_ptr make_tree(size_int\
    \ n){\n        if(n==0) return nullptr;\n        if(n==1) return make_leaf(e());\n\
    \        return merge(make_tree(n>>1),make_tree((n+1)>>1));\n    }\n\n    node_ptr\
    \ make_tree(vector<T>&x,size_int L,size_int R){\n        if(R-L==1) return make_leaf(x[L]);\n\
    \        size_int mid = (R+L) / 2;\n        return merge(make_tree(x,L,mid),make_tree(x,mid,R));\n\
    \    }\n\n    node_ptr make_tree(vector<T>&x){\n        size_int n = x.size();\n\
    \        if(n==0) return nullptr;\n        return make_tree(x,0,n);\n    }\n\n\
    \    node_ptr make_node(const node_ptr l,const node_ptr r,const bool color) const\
    \ {\n        node_ptr res = new node;\n        res->l = l;\n        res-> r =\
    \ r;\n        res->size = l->size + r->size;\n        res->rank = l->rank + 1\
    \ - l->color;\n        res->color = color;\n        res->val = op(l->val,r->val);\n\
    \        return res;\n    }\n\n    node_ptr make_leaf(const T x){\n        node_ptr\
    \ res = new node;\n        res->l = res->r = nullptr;\n        res->size = 1;\n\
    \        res->rank = 0;\n        res->val = x;\n        res->color = BLACK;\n\
    \        return res;\n    }\n\n    node_ptr mergesub(const node_ptr l,const node_ptr\
    \ r){\n        if(l->rank==r->rank) return make_node(l,r,1);\n        if(l->rank<r->rank){\n\
    \            node_ptr res = mergesub(l,r->l);\n            if(r->color==BLACK&&res->color==RED&&res->l->color==RED){\n\
    \                if(r->r->color==BLACK) return make_node(res->l,make_node(res->r,r->r,RED),BLACK);\n\
    \                else return make_node(make_node(res->l,res->r,BLACK),make_node(r->r->l,r->r->r,BLACK),RED);\n\
    \            }else{\n                return make_node(res,r->r,r->color);\n  \
    \          }\n        }else{\n            node_ptr res = mergesub(l->r,r);\n \
    \           if(l->color==BLACK&&res->color==RED&&res->l->color==RED){\n      \
    \          if(l->l->color==BLACK) return make_node(make_node(l->l,res->l,RED),res->r,BLACK);\n\
    \                else return make_node(make_node(l->l->l,l->l->r,BLACK),make_node(res->l,res->r,BLACK),RED);\n\
    \            }else{\n                return make_node(l->l,res,l->color);\n  \
    \          }\n        }\n    }\n\n    node_ptr merge(const node_ptr l,const node_ptr\
    \ r){\n        if(!l) return r;\n        if(!r) return l;\n        node_ptr res\
    \ = mergesub(l,r);\n        if(res->color==RED) return make_node(res->l,res->r,BLACK);\n\
    \        return res;\n    }\n\n    node_ptr toroot(const node_ptr p){\n      \
    \  if(!p) return nullptr;\n        if(p->color==BLACK) return p;\n        return\
    \ make_node(p->l,p->r,BLACK);\n    }\n\n    pair<node_ptr,node_ptr> split(const\
    \ node_ptr p,int k){\n        if(!p) return make_pair(nullptr,nullptr);\n    \
    \    if(k==0) return make_pair(nullptr,toroot(p));\n        if(k==p->size) return\
    \ make_pair(toroot(p),nullptr);\n        if(k<p->l->size) {\n            auto\
    \ now = split(p->l,k);\n            return make_pair(now.first,merge(now.second,toroot(p->r)));\n\
    \        }else if(p->l->size<k){\n            auto now = split(p->r,k-p->l->size);\n\
    \            return make_pair(merge(toroot(p->l),now.first),now.second);\n   \
    \     }else return make_pair(toroot(p->l),toroot(p->r));\n    }\n\n    inline\
    \ size_int size(const node_ptr p) const {\n        if(!p) return 0;\n        return\
    \ p->size;\n    }\n\n    T get(const node_ptr&p,size_int i){\n        assert(i<p->size);\n\
    \        if(p->rank==0) return p->val;\n        if(i<p->l->size) return this->get(p->l,i);\n\
    \        else return this->get(p->r,i-p->l->size);\n    }\n\n    node_ptr set(const\
    \ node_ptr&p,size_int i,T x){\n        assert(i<p->size);\n        if(p->size==1){\n\
    \            return make_leaf(x);\n        }else{\n            if(i<p->l->size)\
    \ return make_node(this->set(p->l,i,x),p->r,p->color);\n            else return\
    \ make_node(p->l,this->set(p->r,i-p->l->size,x),p->color);\n        }\n    }\n\
    \n    T prod(const node_ptr p,size_int L,size_int R){\n        assert(0<=L&&L<R&&R<=p->size);\n\
    \        if(L==0&&p->size==R) return p->val;\n        if(R<=p->l->size) return\
    \ this->prod(p->l,L,R);\n        else if(p->l->size<=L) return this->prod(p->r,L-p->l->size,R-p->l->size);\n\
    \        else return op(this->prod(p->l,L,p->l->size),this->prod(p->r,0,R-p->l->size));\n\
    \    }\n};\n\n/**\n * @brief Red-Black Tree\n * \n*/\n"
  code: "#include<vector>\n#include<cassert>\n\nusing namespace std;\nusing ll = long\
    \ long;\n\nconst int MAX_N = (int)1e7 + 5e6;\n\nstruct node{\n    node *l,*r;\n\
    \    bool color; // 0:black 1:red\n    ll rank,size;\n    int val;\n    static\
    \ int node_count;\n\n    void *operator new(size_t){\n        static node pool[MAX_N];\n\
    \        return pool + node_count++;\n    }\n\n    static void delete_all(){\n\
    \        node::node_count = 0;\n    }\n\n    static int getcount(){\n        return\
    \ node::node_count;\n    }\n\n};\nint node::node_count = 0;\n\ntemplate<typename\
    \ T,T (*op)(T,T),T (*e)(),int MAX_N = 10000000,typename size_int = int>\nstruct\
    \ red_black_tree{\n\n    using node_ptr = node*;\n    const bool BLACK = false;\n\
    \    const bool RED = true;\n\n    static int getcount(){\n        return node::getcount();\n\
    \    }\n\n    static void clear(){\n        node::delete_all();\n    }\n\n   \
    \ node_ptr make_tree(size_int n){\n        if(n==0) return nullptr;\n        if(n==1)\
    \ return make_leaf(e());\n        return merge(make_tree(n>>1),make_tree((n+1)>>1));\n\
    \    }\n\n    node_ptr make_tree(vector<T>&x,size_int L,size_int R){\n       \
    \ if(R-L==1) return make_leaf(x[L]);\n        size_int mid = (R+L) / 2;\n    \
    \    return merge(make_tree(x,L,mid),make_tree(x,mid,R));\n    }\n\n    node_ptr\
    \ make_tree(vector<T>&x){\n        size_int n = x.size();\n        if(n==0) return\
    \ nullptr;\n        return make_tree(x,0,n);\n    }\n\n    node_ptr make_node(const\
    \ node_ptr l,const node_ptr r,const bool color) const {\n        node_ptr res\
    \ = new node;\n        res->l = l;\n        res-> r = r;\n        res->size =\
    \ l->size + r->size;\n        res->rank = l->rank + 1 - l->color;\n        res->color\
    \ = color;\n        res->val = op(l->val,r->val);\n        return res;\n    }\n\
    \n    node_ptr make_leaf(const T x){\n        node_ptr res = new node;\n     \
    \   res->l = res->r = nullptr;\n        res->size = 1;\n        res->rank = 0;\n\
    \        res->val = x;\n        res->color = BLACK;\n        return res;\n   \
    \ }\n\n    node_ptr mergesub(const node_ptr l,const node_ptr r){\n        if(l->rank==r->rank)\
    \ return make_node(l,r,1);\n        if(l->rank<r->rank){\n            node_ptr\
    \ res = mergesub(l,r->l);\n            if(r->color==BLACK&&res->color==RED&&res->l->color==RED){\n\
    \                if(r->r->color==BLACK) return make_node(res->l,make_node(res->r,r->r,RED),BLACK);\n\
    \                else return make_node(make_node(res->l,res->r,BLACK),make_node(r->r->l,r->r->r,BLACK),RED);\n\
    \            }else{\n                return make_node(res,r->r,r->color);\n  \
    \          }\n        }else{\n            node_ptr res = mergesub(l->r,r);\n \
    \           if(l->color==BLACK&&res->color==RED&&res->l->color==RED){\n      \
    \          if(l->l->color==BLACK) return make_node(make_node(l->l,res->l,RED),res->r,BLACK);\n\
    \                else return make_node(make_node(l->l->l,l->l->r,BLACK),make_node(res->l,res->r,BLACK),RED);\n\
    \            }else{\n                return make_node(l->l,res,l->color);\n  \
    \          }\n        }\n    }\n\n    node_ptr merge(const node_ptr l,const node_ptr\
    \ r){\n        if(!l) return r;\n        if(!r) return l;\n        node_ptr res\
    \ = mergesub(l,r);\n        if(res->color==RED) return make_node(res->l,res->r,BLACK);\n\
    \        return res;\n    }\n\n    node_ptr toroot(const node_ptr p){\n      \
    \  if(!p) return nullptr;\n        if(p->color==BLACK) return p;\n        return\
    \ make_node(p->l,p->r,BLACK);\n    }\n\n    pair<node_ptr,node_ptr> split(const\
    \ node_ptr p,int k){\n        if(!p) return make_pair(nullptr,nullptr);\n    \
    \    if(k==0) return make_pair(nullptr,toroot(p));\n        if(k==p->size) return\
    \ make_pair(toroot(p),nullptr);\n        if(k<p->l->size) {\n            auto\
    \ now = split(p->l,k);\n            return make_pair(now.first,merge(now.second,toroot(p->r)));\n\
    \        }else if(p->l->size<k){\n            auto now = split(p->r,k-p->l->size);\n\
    \            return make_pair(merge(toroot(p->l),now.first),now.second);\n   \
    \     }else return make_pair(toroot(p->l),toroot(p->r));\n    }\n\n    inline\
    \ size_int size(const node_ptr p) const {\n        if(!p) return 0;\n        return\
    \ p->size;\n    }\n\n    T get(const node_ptr&p,size_int i){\n        assert(i<p->size);\n\
    \        if(p->rank==0) return p->val;\n        if(i<p->l->size) return this->get(p->l,i);\n\
    \        else return this->get(p->r,i-p->l->size);\n    }\n\n    node_ptr set(const\
    \ node_ptr&p,size_int i,T x){\n        assert(i<p->size);\n        if(p->size==1){\n\
    \            return make_leaf(x);\n        }else{\n            if(i<p->l->size)\
    \ return make_node(this->set(p->l,i,x),p->r,p->color);\n            else return\
    \ make_node(p->l,this->set(p->r,i-p->l->size,x),p->color);\n        }\n    }\n\
    \n    T prod(const node_ptr p,size_int L,size_int R){\n        assert(0<=L&&L<R&&R<=p->size);\n\
    \        if(L==0&&p->size==R) return p->val;\n        if(R<=p->l->size) return\
    \ this->prod(p->l,L,R);\n        else if(p->l->size<=L) return this->prod(p->r,L-p->l->size,R-p->l->size);\n\
    \        else return op(this->prod(p->l,L,p->l->size),this->prod(p->r,0,R-p->l->size));\n\
    \    }\n};\n\n/**\n * @brief Red-Black Tree\n * \n*/"
  dependsOn: []
  isVerificationFile: false
  path: data/redblacktree.hpp
  requiredBy: []
  timestamp: '2024-01-04 04:21:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data/redblacktree.hpp
layout: document
redirect_from:
- /library/data/redblacktree.hpp
- /library/data/redblacktree.hpp.html
title: Red-Black Tree
---
