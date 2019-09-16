class TrieNode {
public:
    char label;
    vector<TrieNode*> sons;
    TrieNode* fail;
    int cnt;
    TrieNode(char label):label(label), sons({}), fail(nullptr), cnt(0) {}
};
class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        buildTrieTree(words);
        buildACAutomaton();
        now = root;
    }
    
    bool query(char letter) {
        while (now != root && (now->sons.empty() || !now->sons[letter - 'a'])) {
            now = now->fail;
        }
        if (!now->sons.empty() && now->sons[letter - 'a']) {
            now = now->sons[letter - 'a'];
        }
        return now->cnt > 0;
    }
private:
    TrieNode* root, * now;
    
    void buildTrieTree(vector<string>& words) {
        root = new TrieNode('#');
        for (auto& word : words) {
            auto node = root;
            for (int i = 0; i < word.size(); ++i) {
                int label = word[i] - 'a';
                if (node->sons.empty()) {
                    node->sons = vector<TrieNode*>(26, nullptr);
                }
                if (!node->sons[label]) {
                    node->sons[label] = new TrieNode('a' + label);
                }
                node = node->sons[label];
                if (i == word.size() - 1) {
                    ++node->cnt;
                }
            }
        }
    }
    void buildACAutomaton() {
        root->fail = root;
        deque<TrieNode*> q;
        for (int i = 0; i < 26; ++i) {
            if (root->sons[i]) {
                root->sons[i]->fail = root;
                q.push_back(root->sons[i]);
            }
        }
        while (!q.empty()) {
            auto node = q.front();
            q.pop_front();
            for (int i = 0; i < node->sons.size(); ++i) {
                if (node->sons[i]) {
                    auto son = node->sons[i];
                    auto prev = node->fail;
                    while (prev != root && (prev->sons.empty() || !prev->sons[i])) {
                        prev = prev->fail;
                    }
                    if (prev->sons.empty() || !prev->sons[i]) {
                        son->fail = root;
                    } else {
                        son->fail = prev->sons[i];
                        son->cnt += prev->sons[i]->cnt;
                    }
                    q.push_back(son);
                }
            }
        }
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */