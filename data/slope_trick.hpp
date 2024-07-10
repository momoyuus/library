
#include<queue>
template<typename T>
struct slope_trick{
    priority_queue<T> l;
    priority_queue<T,vector<T>,greater<T>> r;
    T m,add_l,add_r;
    slope_trick(){
        m = 0;
    }

    T get_min(){
        return m;
    }

    pair<T,T> get_min_interval(){
        // not yet
    }

    void add_all(T a){
        m += a;
    }

    // max(0,x-a)
    void add_plus(T a){
        if(!l.empty()) m += max<T>(0,(l.top()+add_l)-a);
        if(!l.empty()&&(l.top()+add_l)<=a) r.push(a-add_r);
        else{
            l.push(a-add_l);
            r.push(l.top()+add_l-add_r);
            l.pop();
        }
    }

    // max(0,a-x)
    void add_minus(T a){
        if(!r.empty()) m += max<T>(0,a-(r.top()+add_r));
        if(!r.empty()&&a<=(r.top()+add_r)) l.push(a-add_l);
        else{
            r.push(a-add_r);
            l.push(r.top()+add_r-add_l);
            r.pop();
        }
    }

    void add_abs(T a){
        add_plus(a);
        add_minus(a);
    }

    void min_left(){
        r.clear();
        add_r = 0;
    }

    void min_right(){
        l.clear();
        add_l = 0;
    }

    void move(T a){
        add_l += a;
        add_r += a;
    }

    // g(x) = min_{y \in [x-le,x+ri]} f(y)
    void sliding_min(T le,T ri){
        add_r += le;
        add_l -= ri;
    }

    //O(n)
    T get(T x){
        T now = m;
        if(!r.empty()&&r.top()+add_r<=x){
            vector<T> use;
            while(!r.empty()){
                if(x<=r.top()+add_r) break;
                use.push_back(r.top()+add_r);
                r.pop();
            }
            for(int i = 0;i<use.size();i++) now += x - use[i];
            for(int i = 0;i<use.size();i++) r.push(use[i]-add_r);
        }else if(!l.empty()&&x<=l.top()+add_l){
            vector<T> use;
            while(!l.empty()){
                if(l.top()+add_l<=x) break;
                use.push_back(l.top()+add_l);
                l.pop();
            }
            for(int i = 0;i<use.size();i++) now += use[i] - x;
            for(int i = 0;i<use.size();i++) l.push(use[i]-add_l);
        }
        return now;
    }
};
/**
 * @brief slope_trick
 * @docs docs/data/slope_trick.md
*/
