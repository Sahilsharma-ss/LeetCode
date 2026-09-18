class Solution {
public:

    vector<int> ch(int f, int l, vector<vector<int>>& vec)
    {
        if(f == 0)
            return vec[l];

        vector<int> ans(26);

        for(int i = 0; i < 26; i++)
            ans[i] = vec[l][i] - vec[f - 1][i];

        return ans;
    }

    vector<string> maxNumOfSubstrings(string s)
    {
        int n = s.size();

        vector<int> temp(26, 0);
        vector<vector<int>> cnt;

        for(int i = 0; i < n; i++)
        {
            temp[s[i] - 'a']++;
            cnt.push_back(temp);
        }

        unordered_map<int, pair<int,int>> mp;

        for(int i = 0; i < n; i++)
        {
            int c = s[i] - 'a';

            if(mp.find(c) == mp.end())
                mp[c] = {i, i};
            else
                mp[c].second = i;
        }

        vector<pair<int,pair<int,int>>> res;

        for(auto i : mp)
        {
            int first = i.second.first;
            int last = i.second.second;

            bool valid = true;

            while(true)
            {
                int oldFirst = first;
                int oldLast = last;

                vector<int> check = ch(first, last, cnt);

                for(int j = 0; j < 26; j++)
                {
                    if(check[j] > 0)
                    {
                        if(mp[j].first < first)
                        {
                            valid = false;
                            break;
                        }

                        last = max(last, mp[j].second);
                    }
                }

                if(!valid)
                    break;

                if(first == oldFirst && last == oldLast)
                    break;
            }

            if(valid)
            {
                res.push_back({
                    last - first + 1,
                    {first, last}
                });
            }
        }

        sort(res.begin(), res.end());

        vector<string> ans;
        vector<int> marked(n, 0);

        for(auto i : res)
        {
            int first = i.second.first;
            int last = i.second.second;

            bool ok = true;

            for(int j = first; j <= last; j++)
            {
                if(marked[j])
                {
                    ok = false;
                    break;
                }
            }

            if(ok)
            {
                ans.push_back(s.substr(first, last - first + 1));

                for(int j = first; j <= last; j++)
                    marked[j] = 1;
            }
        }

        return ans;
    }
};