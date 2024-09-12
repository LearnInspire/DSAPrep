class MyHashSet {
public:
    //using Linear Chaining Hashing; storing list of integers in the buckets
    int M; // no of buckets
    vector<list<int>> buckets;

    //for getting index
    int getIndex(int key){
        return key%M;
    }
    MyHashSet() {
        M = 15000;//10^4 calls, so we're assuming 10000 entries for add, so keeping a big size like 15k
        buckets = vector<list<int>> (M, list<int>{});
    }
    
    void add(int key) {
        int index = getIndex(key);
        auto itr = find(buckets[index].begin(), buckets[index].end(), key);

        if(itr == buckets[index].end())
            buckets[index].push_back(key);
        
    }
    
    void remove(int key) {
        int index = getIndex(key);
        auto itr = find(buckets[index].begin(), buckets[index].end(), key);

        if(itr != buckets[index].end())
            buckets[index].erase(itr);
        
    }
    
    bool contains(int key) {
        int index = getIndex(key);
        auto itr = find(buckets[index].begin(), buckets[index].end(), key);

        return itr != buckets[index].end(); //means end tkk nhi gya hai, mtlb value hai present  
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */