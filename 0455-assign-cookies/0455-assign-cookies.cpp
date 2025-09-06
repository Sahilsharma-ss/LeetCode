class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>()); 
        sort(s.begin(), s.end(), greater<int>()); 

        int cnt = 0;
        int i = 0; // child index
        int j = 0; // cookie index

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) { 
                cnt++;         
                i++;            
            }
            j++; // move to next cookie anyway
        }

        return cnt;
    }
};
