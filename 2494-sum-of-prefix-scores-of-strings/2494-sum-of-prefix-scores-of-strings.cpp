class Solution {
    class Trie {
    public:
        int count;
        Trie* children[26];

        Trie() {
            count = 0;
            for(int i=0; i<26; i++)
                children[i] = nullptr;
        }
    };

public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans(words.size(), 0);
        Trie* root = new Trie();

        for(auto& word : words) {
            int wordSize = word.size();
            Trie* node = root;
            for (char& c : word) {
                int index = c - 'a';
                if (!node->children[index]) {
                    node->children[index] = new Trie();
                }
                node = node->children[index];
                node->count++;
            }
        }

        int i = 0;
        for(auto& word : words) {
            int wordSize = word.size();
            Trie* node = root;
            for (char& c : word) {
                int index = c - 'a';
                node = node->children[index];
                ans[i] += node->count;
            }
            i++;
        }

        return ans;
    }
};