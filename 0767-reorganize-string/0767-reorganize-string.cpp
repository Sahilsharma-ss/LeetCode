class Solution {
public:
    string reorganizeString(string s) {

        vector<int> freq(26,0);

        for(char c : s)
            freq[c-'a']++;

        priority_queue<pair<int,char>> pq;

        for(int i=0;i<26;i++){
            if(freq[i] > 0)
                pq.push({freq[i], char(i+'a')});
        }

        string res = "";

        pair<int,char> prev = {0,'#'};

        while(!pq.empty()){

            auto [f,c] = pq.top();
            pq.pop();

            res += c;
            f--;
            if(prev.first > 0)
                pq.push(prev);

            prev = {f,c};
        }
        if(res.size() != s.size()) return "";
        return res;
    }
};
