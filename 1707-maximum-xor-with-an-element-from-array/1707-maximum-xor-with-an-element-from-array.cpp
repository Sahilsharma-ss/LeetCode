class Trie{
    struct Node{
        Node *links[2] = {NULL};
        bool containkey(int bit)
        {
            return (links[bit]!=NULL);
        }
        void putbit(int bit,Node *node)
        {
            links[bit] = node;
        }
        Node *getlink(int bit)
        {
            return links[bit];
        }
    };
public :
    Node *root;
    Trie()
    {
        root = new Node();
    }
    void insert(int num)
    {
        Node *node = root;
        for(int i=31;i>=0;i--)
        {
            int bit = (num>>i)&1;
            if(!node->containkey(bit))
            {
                node->putbit(bit,new Node());
            }
            node = node->getlink(bit);
        }
    }
    int max_xor(int num)
    {
        Node *node = root;
        int maxnum = 0;
        for(int i=31;i>=0;i--)
        {
            int bit = (num>>i)&1;
            if(node->containkey(1-bit))
            {
                maxnum = maxnum | (1<<i);  // when  we got opposite bit | to inc increase xor
                node = node->getlink(1-bit);
            }
            else
            {
                node = node->getlink(bit);
            }
        }
        return maxnum;
    }

};


class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie *t = new Trie();
        for(int i=0;i<queries.size();i++)
        {
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),[&](auto &a, auto &b)
        {
            return a[1] < b[1];
        });
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans(queries.size());
        int ind = 0;
        for(auto i : queries)
        {
            while(ind<n && nums[ind] <= i[1])
            {
                t->insert(nums[ind]);
                ind++;
            }
            if(ind==0)
            {
                ans[i[2]] = -1;
            }
            else
            {
                ans[i[2]] = t->max_xor(i[0]);
            }
        }
        return ans;
    }
};