#include "common.h"
//not checked yet, can not passed

class LRUCache{
    struct node{
        int i;
    };
    int capacity;
    map<int, shared_ptr<node>> m;
    list<pair<int, shared_ptr<node>>> l;
public:
    LRUCache(int cap): capacity(cap){}
    void set(int key, int value){
        auto& p = m.find(key);
        if(p == m.end()){
            insert(key, value);
        }
        else{
            auto lit = l.find(*p);
            l.remove(lit);
            *(p->second) = value;
            l.emplace_back(*p);
        }
    }
    int get(int key){
        auto p = m.find(key);
        if(p == m.end() ){
            return -1;
        }
        else{
            auto lit = l.find(*p);
            l.remove(lit);
            l.emplace_back(*p);
            return *(p->second);
        }
    }
    void insert(int key, int value){
        if(m.size() >= capacity){
            auto p = make_shared<node>(value);
            auto lnode = l.front();
            m.remove(lnode.first);
            l.pop_front();
        }
        auto p = make_shared<node>(value);
        m[key] = p;
        l.push_back(make_pair(key, p));
    }



};

int main() {

    return 1;
}