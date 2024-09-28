class RandomizedSet {
public:
    vector<int> vec;
    unordered_map<int, int> mp;

    RandomizedSet() {
        
    }
    /*Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val) != mp.end()){
            return false;
        }

        vec.push_back(val);
        mp[val] = vec.size()-1;
        return true;
    }
    /* Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.find(val) == mp.end()){
            return false;
        }

        int idx = mp[val]; //get the index of the element to be removed
        int lastElement = vec.back();
        vec.back() = val; //jis ele ko remove krna hai usko back mein daal denge

        vec[idx] = lastElement;
        mp[lastElement] = idx;

        vec.pop_back();
        mp.erase(val);
        return true;
    }
    /*Get a random element from the set. */
    int getRandom() {
        int n = vec.size();
        int randomIndex = rand() % n;
        return vec[randomIndex];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */