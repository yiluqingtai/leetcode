/**
 *
 * File:    leetcode146.cpp
 *          LRU缓存机制
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/27
 *          
 **/


class LRUCache {
public:
    list<pair<int, int>> lrulist;
    unordered_map<int, list<pair<int, int>>::iterator> lruhash;
    int k;
    LRUCache(int capacity) {
        k = capacity;
    }
    
    int get(int key) {
        auto iter = lruhash.find(key);
        if (iter != lruhash.end()) {
            int val = iter->second->second;
            lrulist.erase(iter->second);
            lrulist.push_front({key, val});
            lruhash[key] = lrulist.begin();
            return val;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto iter = lruhash.find(key);
        if (iter != lruhash.end()) {
            lrulist.erase(iter->second);
        } else {
            if (lrulist.size() == k) {
                int back_key = lrulist.back().first;
                lruhash.erase(back_key);
                lrulist.pop_back();
            }
        }
        lrulist.push_front({key, value});
        lruhash[key] = lrulist.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */