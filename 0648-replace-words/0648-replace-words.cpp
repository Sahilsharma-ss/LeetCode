// class Trie{
//     struct Node{
//         Node *links;
//         bool flag = true;
        
//     }
// }
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string>st;
        for(auto i : dictionary)
        {
            st.insert(i);
        }
        vector<string>vec;
        int n = sentence.size();
        int i=0;
        while(i<n)
        {
            string tmp = "";
            while(i<n && sentence[i]!=' ')
            {
                tmp+=sentence[i];
                i++;
            }
            vec.push_back(tmp);
            i++;
        }
        for(auto i : vec)
        {
            cout<<i<<" ";
        }
        string ans = "";
        for(auto i : vec)
        {
            string tmp = "";
            bool ok = false;
            for(int j=0;j<i.size();j++){
                tmp+=i[j];
                if(st.find(tmp)!=st.end())
                {
                    ans+=tmp;
                    ans+=" ";
                    ok = true;
                    break;
                }
            }
            if(!ok)
            {
                ans+=i;
                ans+=" ";
            }
        }
        ans.resize(ans.size()-1);
        return ans;
    }
};