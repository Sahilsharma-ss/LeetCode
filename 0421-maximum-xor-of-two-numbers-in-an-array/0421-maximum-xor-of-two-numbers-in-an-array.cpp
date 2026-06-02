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
    int findMaximumXOR(vector<int>& nums) {
       Trie *t = new Trie();
       for(int i : nums)
       {
            t->insert(i);
       }
       int maxi = 0;
       for(int i : nums)
       {
         maxi = max(maxi,t->max_xor(i));
       }
       return maxi;
    }
};