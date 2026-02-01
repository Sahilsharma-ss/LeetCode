class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<pair<int,int>>arrival;
        for(int i=0;i<tasks.size();i++){
            arrival.push_back({tasks[i][0],i});
        }
        sort(arrival.begin(),arrival.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        long long time = 0;
        vector<int>donee(tasks.size(),0);
        vector<int>ans;
        int i=0;
        while(i<tasks.size() || !pq.empty())
        {
            if(pq.empty()) time = max(time,(long long)arrival[i].first);
            while(i<tasks.size() && arrival[i].first <= time)
            {
                int idx = arrival[i].second;
                pq.push({tasks[idx][1],idx});
                i++;
            }
            auto [proc,idx] = pq.top();
            pq.pop();
            time+=proc;
            ans.push_back(idx);
        }
        return ans;
    }
};