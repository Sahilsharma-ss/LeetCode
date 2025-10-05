class LRUCache {
public:
    list<int>dll;
    unordered_map<int,pair<list<int>::iterator,int>>mp;
    int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
        {
            return -1;
        }
        auto it = mp[key].first;
        dll.erase(it);
        dll.push_front(key);
        mp[key].first = dll.begin();
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            mp[key].second=value;
            auto it = mp[key].first;
            dll.erase(it);
            dll.push_front(key);
            mp[key].first = dll.begin();
        }
        else
        {
            dll.push_front(key);
            mp[key]={dll.begin(),value};
        }
        if(mp.size()>n)
        {
            mp.erase(dll.back());
            dll.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */