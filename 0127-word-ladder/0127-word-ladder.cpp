class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>mp;
        for(auto i : wordList)
        {
            mp[i] = 1;
        }
        if(mp.find(endWord)==mp.end())
        {
            return 0;
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty())
        {
            string s = q.front().first;
            int val = q.front().second;
            q.pop();
            if(s==endWord)
            {
                return val;
            }
            for(int i=0;i<s.size();i++)
            {
                int ch = s[i];
                for(int j='a';j<='z';j++)
                {
                    if(j==ch) continue;
                    s[i] = j;
                    if(mp.find(s)!=mp.end())
                    {
                        q.push({s,val+1});
                        mp.erase(s);
                    }                   
                }
                s[i] = ch;
            }
        }
        return 0;
    }
};