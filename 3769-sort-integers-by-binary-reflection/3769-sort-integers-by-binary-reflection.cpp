class Solution {
public:
    int tobin(int x)
    {
        string s = bitset<32>(x).to_string();
        int pos = s.find('1');
        s = s.substr(pos);

        reverse(s.begin(), s.end());

        return stoi(s, nullptr, 2);   
    }
    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int,int>>vec;
        for(auto i : nums)
        {
            int  no = tobin(i);
           // int no = stoi(str,nullptr,2);
            vec.push_back({i,no});
        }
        sort(vec.begin(),vec.end(),[&](auto &a , auto &b)
        {
            if(a.second==b.second)
            {
                return a.first<b.first;
            }
            else
            {
                return a.second<b.second;
            }
        });
        for(auto i : vec)
        {
            cout<<i.first<<" "<<i.second;
        }
        vector<int>res;
        for(auto i : vec)
        {
            res.push_back(i.first);
        }
        return res;
    }
};