struct node {
    bool eow;
    node *arr[10];
    node() {
        eow = false;
        for(int i = 0; i < 10; i++) arr[i] = nullptr;
    }
};
class trie {
    node *root;
    public:
    trie() {
        root = new node();
    }
    node *getRoot() {
        return root;
    }
    void insert(string str) {
        node *temp = root;
        for(auto s: str) {
            if(!temp->arr[s-'0']) temp->arr[s-'0'] = new node();
            temp = temp->arr[s-'0'];
        }
        temp->eow = true;
    }
};

    void dfs(node *curr, vector<int>&res, string temp) {
        if(curr->eow) {
            res.push_back(stoi(temp));
        };
        for(int i = 0; i < 10; i++) {
            if(curr->arr[i]) {
                dfs(curr->arr[i], res, temp+char('0'+i));
            }
        }
    }

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>temp;
        trie t;
        for(int i = 1; i <= n; i++) {
            t.insert(to_string(i));
        }
        dfs(t.getRoot(), temp, "");
        return temp;
    }
};