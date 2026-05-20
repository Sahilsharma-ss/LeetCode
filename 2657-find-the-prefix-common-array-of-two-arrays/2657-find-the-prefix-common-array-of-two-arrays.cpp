class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>arr;
        unordered_map<int,int>mp;
        for(int i=0;i<A.size();i++)
        {
            mp[A[i]]++;
            mp[B[i]]++;
            int cnt = 0;
            for(auto i : mp)
            {
                if(i.second>=2) cnt++;
            }
            arr.push_back(cnt);
        }
        return arr;
    }
};