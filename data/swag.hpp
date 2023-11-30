#include<stack>
#include<cassert>
using namespace std;

template<typename T,T (*op)(T,T),T (*e)()>
struct swag{
    stack<T> front,back;
    stack<T> front_prod,back_prod;
    swag(){}

    void move_back(int use){
        stack<T> tmp;
        back_prod = stack<T>();
        while((int)back.size()>use){
            tmp.push(back.top());
            back.pop();
        }
        while(!back.empty()){
            this->push_front(back.top());
            back.pop();
        }
        while(!tmp.empty()){
            this->push_back(tmp.top());
            tmp.pop();
        }
    }
    
    void move_front(int use){
        stack<T> tmp;
        front_prod = stack<T>();
        while((int)front.size()>use){
            tmp.push(front.top());
            front.pop();
        }
        while(!front.empty()){
            this->push_back(front.top());
            front.pop();
        }
        while(!tmp.empty()){
            this->push_front(tmp.top());
            tmp.pop();
        }
    }

    void push_front(T x){
        front.push(x);
        if(front_prod.empty()) front_prod.push(x);
        else front_prod.push(op(x,front_prod.top()));
    }

    void push_back(T x){
        back.push(x);
        if(back_prod.empty()) back_prod.push(x);
        else back_prod.push(op(back_prod.top(),x));
    }

    void pop_front(){
        assert(this->size()>0);
        if(front.empty()) move_back(((int)back.size()+1)>>1);
        front.pop();
        front_prod.pop();
    }

    void pop_back(){
        assert(this->size()>0);
        if(back.empty()) move_front(((int)front.size()+1)>>1);
        back.pop();
        back_prod.pop();
    }

    T all_prod(){
        if(front.empty()&&back.empty()) return e();
        if(front.empty()) return back_prod.top();
        if(back.empty()) return front_prod.top();
        return op(front_prod.top(),back_prod.top());
    }

    int size(){
        return (int)front.size() + (int)back.size();
    }
};
/**
 * @brief SWAG
*/