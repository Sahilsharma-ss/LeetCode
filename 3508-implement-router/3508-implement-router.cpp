
struct TupleHash {
    size_t operator()(const tuple<int,int,int>& t) const {
        auto h1 = hash<int>()(get<0>(t));
        auto h2 = hash<int>()(get<1>(t));
        auto h3 = hash<int>()(get<2>(t));
        return h1 ^ (h2 << 1) ^ (h3 << 2);
    }
};

class Router {
public:
    int limit;
    queue<tuple<int,int,int>> q;   
    unordered_map<tuple<int,int,int>, int, TupleHash> mp; 
    unordered_map<int, multiset<int>> dstMap;

    Router(int memoryLimit) {
        limit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        tuple<int,int,int> t = {source, destination, timestamp};
        if (mp.count(t)) return false;

        if ((int)q.size() == limit) {
            auto old = q.front(); 
            q.pop();
            mp.erase(old);

            int os, od, ot;
            tie(os, od, ot) = old;
            dstMap[od].erase(dstMap[od].find(ot));
            if (dstMap[od].empty()) dstMap.erase(od);
        }

        q.push(t);
        mp[t] = 1;
        dstMap[destination].insert(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) return {};

        auto t = q.front();
        q.pop();
        mp.erase(t);

        int src, dest, ts;
        tie(src, dest, ts) = t;
        dstMap[dest].erase(dstMap[dest].find(ts));
        if (dstMap[dest].empty()) dstMap.erase(dest);

        return {src, dest, ts};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if (!dstMap.count(destination)) return 0;
        auto &ms = dstMap[destination];
        auto lo = ms.lower_bound(startTime);
        auto hi = ms.upper_bound(endTime);
        return distance(lo, hi);
    }
};
