class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0;
        priority_queue<int>pq;
        for(auto i : gifts)
        {
            pq.push(i);
        }
        while(k>0)
        {
            int ele = pq.top();
            pq.pop();
            pq.push(sqrt(ele));
            k--;
        }
        while(!pq.empty())
        {
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};