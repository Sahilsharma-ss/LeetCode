class Trie
{
    struct Node 
    {
        Node *links[26];
        int value = 0;
        bool flag  = false;
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
        Node *getlink(char ch)
        {
            return links[ch-'a'];
        }
        int getval(){
            return value;
        }
        void incval(int v)
        {
            value+=v;
        }
    };
        Node *root;
    public : 
    Trie()
    {
        root = new Node();
    }
    void insert(string word,int val)
    {
        Node *node = root;
        for(char ch : word)
        {
            if(!node->containskey(ch))
            {
                node->putchar(ch,new Node());
            }
            node =  node->getlink(ch);
            node->incval(val);
        }
        //node->setend();
    }
    int prefix(string w)
    {
        Node *node = root;
        for(char ch : w)
        {
            if(!node->containskey(ch))
            {
                return 0;
            }
            node = node->getlink(ch);
        }
        return node->getval();
    }
};
class MapSum {
public:
    Trie *t;
    MapSum() {
        t  = new Trie();
    }
    unordered_map<string,int> mp;
    void insert(string key, int val) {
        int delta = val;
        if(mp.count(key))
        {
            delta = val - mp[key];
        }
        mp[key] = val;
        t->insert(key,delta);
    }
    
    int sum(string prefix) {
     //   return node->getval();
        return t->prefix(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */