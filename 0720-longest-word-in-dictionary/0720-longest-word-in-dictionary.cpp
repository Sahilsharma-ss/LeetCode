class Trie{
    struct Node
    {
        Node *links[26];
        bool flag = false;
        Node()
        {
            for(int i=0;i<26;i++)
            {
                links[i] = NULL;
            }
        }

        bool containskey(char ch)
        {
            return links[ch-'a'] != NULL;
        }

        void putchar(char ch , Node *node)
        {
            links[ch-'a'] = node;
        }

        Node *getlink(char ch)
        {
            return links[ch-'a'];
        }
        void setend()
        {
            flag = true;
        }
        bool isend()
        {
            return flag == true;
        }
    };
    public : 
        Node *root;
        Trie()
        {
            root = new Node();
        }
        void insert(string &word)
        {
            Node *node = root;
            for(char ch : word)
            {
                if(!node->containskey(ch))
                {
                    node->putchar(ch,new Node());
                }
                node = node->getlink(ch);
            }
            node->setend();
        }
    int longestInDict(string &word)
    {
        Node *node = root;
        for(char ch : word)
        {
            if(!node->containskey(ch))
            {
                return 0;
            }
            node = node->getlink(ch);
            if(!node->isend()) return 0;
        }
        if(node->isend())
        {
            return word.size();
        }
        return 0;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie *t = new Trie();
        for(auto i : words)
        {
            t->insert(i);
        }
        int maxi = 0;
        string ans;
        sort(words.begin(),words.end());
        for(auto i : words)
        {
            int len = t->longestInDict(i);
            if(len>maxi)
            {
                ans = i;
                maxi = i.size();
            }
        }
        return ans;
    }
};