class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        set<string>s(wordList.begin(),wordList.end());
        int sz=wordList[0].size();
         if (s.find(endWord) == s.end()) return 0;
         int ans;
        while(!q.empty())
        {
            string st=q.front().first;
            int n= q.front().second;
            if(st==endWord)
            {
                return n;
            }
            q.pop();
            for(int i=0;i<sz;i++)
            {
                for(char ch ='a';ch<='z';ch++)
                {
                    string temp=st;
                    temp[i]=ch;
                    if(s.find(temp)!=s.end() && temp!=st)
                    {
                        q.push({temp,n+1});
                        s.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};