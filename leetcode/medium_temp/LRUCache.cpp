#include "../common.h"
/**
 * @brief Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
 * 
 */
class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        if (cache_.find(key) != cache_.end()) {
            least_used_list_.remove(key);
            least_used_list_.push_front(key);

            return cache_[key];
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if (cache_.find(key) != cache_.end()) {
            // cache_[key] = value;
            least_used_list_.remove(key);

            least_used_list_.push_front(key);
        } else {
            // cout << "capacity:" << capacity_ << "size:" << cache_.size() << endl;
            
            if (capacity_ == cache_.size()) {
                // cout << "capacity_:" << capacity_ << endl;
                int old_key = least_used_list_.back();
                least_used_list_.pop_back();
                cache_.erase(old_key);
            }
            least_used_list_.push_front(key);

        }
        cache_[key] = value;

        // print_map(cache_);
        // print_1d_container(least_used_list_);
    }
private:
    int capacity_;
    list<int>   least_used_list_;
    map<int, int> cache_;
};

class LRUCache_ {
public:
    LRUCache_(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) return -1;
        l.splice(l.begin(), l, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()) l.erase(it->second);
        l.push_front(make_pair(key, value));
        m[key] = l.begin();
        if (m.size() > cap) {
            int k = l.rbegin()->first;
            l.pop_back();
            m.erase(k);
        }
    }
    
private:
    int cap;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
};

/**
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]
 */
int main()
{
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    cout << lru.get(1) << endl;
    lru.put(3, 3);
    cout << lru.get(2) << endl;
    lru.put(4, 4);
    cout << lru.get(1) << endl;

    list<int> a1{1,2,3},a2{4,5,6};
    a1.splice(a1.begin(), a2,++a2.begin());
    list<int>::iterator it;
    cout << "a1.merge(a2):";
    for(it = a1.begin();it!=a1.end();it++){
        cout << *it << " ";
    }
    cout << endl;
    return 0;



}
