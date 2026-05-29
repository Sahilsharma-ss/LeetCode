class WordDictionary {
    struct Node {
        Node *links[26];
        bool flag = false;

        Node() {
            for(int i = 0; i < 26; i++) {
                links[i] = NULL;
            }
        }

        bool containskey(char ch) {
            return links[ch - 'a'] != NULL;
        }

        void put(char ch, Node *node) {
            links[ch - 'a'] = node;
        }

        Node* getchar(char ch) {
            return links[ch - 'a'];
        }

        void setend() {
            flag = true;
        }

        bool isend() {
            return flag;
        }

        bool dfs(int ind, string &word, Node *node) {

            if(ind == word.size()) {
                return node->isend();
            }

            if(word[ind] == '.') {

                for(int i = 0; i < 26; i++) {

                    if(node->links[i] &&
                       dfs(ind + 1, word, node->links[i])) {
                        return true;
                    }
                }

                return false;
            }

            if(!node->containskey(word[ind])) {
                return false;
            }

            return dfs(ind + 1, word,
                       node->getchar(word[ind]));
        }
    };

public:

    Node *root;

    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {

        Node *node = root;

        for(char ch : word) {

            if(!node->containskey(ch)) {
                node->put(ch, new Node());
            }

            node = node->getchar(ch);
        }

        node->setend();
    }

    bool search(string word) {
        return root->dfs(0, word, root);
    }
};