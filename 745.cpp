struct Node {
    int w;
    Node* next[27];
    
    Node(): w(-1) {
        fill(next, next + 27, nullptr);
    }
    
    Node(int w): w(w) {
        fill(next, next + 27, nullptr);
    }
};

class WordFilter {
public:
    WordFilter(vector<string> words) {
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            int len = words[i].length();
            for (int j = 0; j <= len; ++j) {
                string str = words[i].substr(len - j) + "{" + words[i];
                insertTrie(&root, str, i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string str = suffix + "{" + prefix;
        return searchTrie(&root, str);
    }
private:
    Node root;
    
    void insertTrie(Node *root, string &word, int weight) {
        Node *cur = root;
        for (auto ch : word) {
            int pos = ch - 'a';
            if (cur->next[pos] == nullptr) {
                cur->next[pos] = new Node(weight);
            }
            cur = cur->next[pos];
            cur->w = weight;
        }
    }
    
    int searchTrie(Node *root, string &str) {
        Node *cur = root;
        for (auto ch : str) {
            int pos = ch - 'a';
            if (cur->next[pos] == nullptr) {
                return -1;
            }
            cur = cur->next[pos];
        }
        return cur->w;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */