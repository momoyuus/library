template<typename T>
struct dynamic_li_chao_tree{
    struct Node;
    using node_ptr = Node*;

    struct Line{
        T a,b;
        Line(T _a,T _b):a(_a),b(_b){}
        inline T get(const T&x) const {
            return a * x + b;
        }
    };
    
    struct Node{
        Line x;
        node_ptr l = nullptr,r = nullptr;
        Node(const Line&_x):x(_x){}
    };
    
    T mn,mx,id;
    node_ptr root;
    dynamic_li_chao_tree(T _mn,T _mx, T _id):mn(_mn),mx(_mx),id(_id),root(nullptr){}
    
    void add_line(node_ptr& t,Line&x,const T&l,const T&r){
        if(!t){
            t = new Node(x);
            return;
        }
        T x_l = x.get(l);
        T x_r = x.get(r);
        T t_l = t->x.get(l);
        T t_r = t->x.get(r);
        if(t_l<=x_l&&t_r<=x_r) return;
        if(x_l<=t_l&&x_r<=t_r) {
            t->x = x;
            return;
        }
        T mid = ((r-l)>>1) + l;
        if(mid==r) mid--;
        T x_m = x.get(mid);
        T t_m = t->x.get(mid);
        if(t_m>x_m){
            swap(t->x,x);
            if(x_l>=t_l) add_line(t->l,x,l,mid);
            else add_line(t->r,x,mid+1,r);
        }else{
            if(t_l>=x_l) add_line(t->l,x,l,mid);
            else add_line(t->r,x,mid+1,r);
        }
        return;
    }

    void add_line(const T&a,const T&b){
        Line x(a,b);
        add_line(root,x,mn,mx);
    }

    T query(const node_ptr&t,const T&x,const T&l,const T&r) const {
        if(!t) return id;
        if(r-l==1) return t->x.get(x);
        T mid = ((r-l)>>1) + l;
        if(mid==r) mid--;
        if(x<mid) return min(t->x.get(x),query(t->l,x,l,mid));
        else return min(t->x.get(x),query(t->r,x,mid+1,r));
    }

    T query(const T&x) const {
        return query(root,x,mn,mx);
    }
};
