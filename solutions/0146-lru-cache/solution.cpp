#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        used_ = 0;
    }
    
    int get(int key) {
        if(dir_.count(key) == 0)return -1;
        int value =  dir_[key]->second;
        list_.erase(dir_[key]);
        list_.push_front({key, value});
        dir_[key] = list_.begin();
        return value;
        
    }
    
    void put(int key, int value) {
        if(dir_.count(key)){
            list_.erase(dir_[key]);
            list_.push_front({key, value});
            dir_[key] = list_.begin();
        }
        else{
            if(used_ == capacity_){
                dir_.erase(list_.back().first);
                list_.pop_back();
                used_--;
            }
            list_.push_front({key, value});
            dir_[key] = list_.begin();
            used_++;
        }
    }
private:
    list<pair<int,int>> list_;
    unordered_map<int, list<pair<int,int>>::iterator> dir_;
    int capacity_;
    int used_;
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
