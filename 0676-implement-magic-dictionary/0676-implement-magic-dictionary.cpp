class MagicDictionary {
public:

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
    };

    Node *t;

    MagicDictionary() {
        t = new Node();
    }

    void buildDict(vector<string> dictionary) {

        for(auto word : dictionary)
        {
            Node *node = t;

            for(char ch : word)
            {
                if(node->links[ch-'a'] == NULL)
                {
                    node->links[ch-'a'] = new Node();
                }

                node = node->links[ch-'a'];
            }

            node->flag = true;
        }
    }

    bool dfs(Node *node,string &word,int ind,int cnt)
    {
        if(node == NULL) return false;

        if(ind == word.size())
        {
            return node->flag && cnt == 1;
        }

        for(int i=0;i<26;i++)
        {
            if(node->links[i] == NULL) continue;

            if(i == word[ind]-'a')
            {
                if(dfs(node->links[i],word,ind+1,cnt))
                {
                    return true;
                }
            }
            else
            {
                if(cnt == 0 && dfs(node->links[i],word,ind+1,1))
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool search(string searchWord) {

        return dfs(t,searchWord,0,0);
    }
};