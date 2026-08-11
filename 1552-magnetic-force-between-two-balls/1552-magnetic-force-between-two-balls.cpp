class Solution {
public:
    bool isok(int mid, int m, vector<int>& position)
    {
        int cnt = 1;            
        int last = position[0];

        for(int i = 1; i < position.size(); i++)
        {
            if(position[i] - last >= mid)
            {
                cnt++;
                last = position[i];
            }
        }
        return cnt >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int l = 1;
        int r = position.back() - position[0];
        int ans = 0;

        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(isok(mid, m, position))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};
