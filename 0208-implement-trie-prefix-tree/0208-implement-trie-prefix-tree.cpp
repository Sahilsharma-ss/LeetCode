class Trie {
    struct Node{
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
        void putchar(char ch,Node *node)
        {
            links[ch-'a'] = node;
        }
        Node * get(char ch)
        {
            return links[ch-'a'];
        }
        void setend()
        {
            flag = true;
        }
        bool isend()
        {
            return flag==true;
        }

    };
    Node *root;
public:
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(char ch : word)
        {
            if(!node->containskey(ch))
            {
                node->putchar(ch,new Node());
            }
            node = node->get(ch);
        }
        node->setend();
    }
    
    bool search(string word) {
        Node *node = root;
        for(char ch : word)
        {
            if(!node->containskey(ch))
            {
                return false;
            }
           node  =  node->get(ch);
        }
        return node->isend();
    }
    
    bool startsWith(string prefix) {
         Node *node = root;
        for(char ch : prefix)
        {
            if(!node->containskey(ch))
            {
                return false;
            }
           node =  node->get(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */