int maxi;
class Trie {
    struct Node {
        Node* links[26];
        bool flag = false;

        int bestind = -1;
        int size = 1e9;

        Node() {
            for(int i = 0; i < 26; i++) {
                links[i] = NULL;
            }
        }

        bool containskey(char ch) {
            return links[ch - 'a'] != NULL;
        }

        void putchar(char ch, Node* node) {
            links[ch - 'a'] = node;
        }

        Node* get(char ch) {
            return links[ch - 'a'];
        }

        void setend() {
            flag = true;
        }

        void update(int ind, int sz) {
            if(bestind == -1 || sz < size) {
                size = sz;
                bestind = ind;
            }
        }

        int bestindans() {
            return bestind;
        }
    };

public:
    Node* root;
    int ind = -1;

    Trie() {
        root = new Node();
    }

    void insert(string word) {

        Node* node = root;

        ind++;

        root->update(ind, word.size());
        int c = 0;
        for(auto ch : word) {
            if(c==maxi) break;
            if(!node->containskey(ch)) {
                node->putchar(ch, new Node());
            }

            node = node->get(ch);

            node->update(ind, word.size());
            c++;
        }

        node->setend();
    }

    int find(string str) {

        Node* node = root;

        for(auto ch : str) {

            if(!node->containskey(ch)) {
                return node->bestindans();
            }

            node = node->get(ch);
        }

        return node->bestindans();
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        Trie* trie = new Trie();
        maxi = -1e9;
        for(auto i : wordsQuery)
        {
            maxi = max(maxi,(int)i.size());
        }
        for(auto i : wordsContainer) {

            string str = i;
            reverse(str.begin(), str.end());
            // if(str.size()>maxi)
            // {
            //     str = str.substr(0,maxi);
            // }
            trie->insert(str);
        }

        vector<int> res;
        for(auto i : wordsQuery) {

            string str = i;

            reverse(str.begin(), str.end());

            res.push_back(trie->find(str));
        }

        return res;
    }
};