class Solution {
public:

vector<string> maxNumOfSubstrings(string s)
{
    int n = s.size();

    vector<int> first(26, n);
    vector<int> last(26, -1);

    for(int i = 0; i < n; i++)
    {
        int c = s[i] - 'a';
        first[c] = min(first[c], i);
        last[c] = i;
    }

    vector<pair<int, pair<int,int>>> res;

    for(int c = 0; c < 26; c++)
    {
        if(last[c] == -1)
            continue;

        int l = first[c];
        int r = last[c];

        bool valid = true;

        for(int j = l; j <= r; j++)
        {
            int x = s[j] - 'a';

            if(first[x] < l)
            {
                valid = false;
                break;
            }

            r = max(r, last[x]);
        }

        if(valid)
        {
            res.push_back({
                r - l + 1,
                {l, r}
            });
        }
    }

    sort(res.begin(), res.end());

    vector<string> ans;
    vector<int> marked(n, 0);

    for(auto i : res)
    {
        int l = i.second.first;
        int r = i.second.second;

        bool ok = true;

        for(int j = l; j <= r; j++)
        {
            if(marked[j])
            {
                ok = false;
                break;
            }
        }

        if(ok)
        {
            ans.push_back(s.substr(l, r - l + 1));

            for(int j = l; j <= r; j++)
                marked[j] = 1;
        }
    }

    return ans;
}


};
