class MyHashMap {
public:
    int size = 10000;
    vector<list<pair<int, int>>> buckets;

    MyHashMap() {
        buckets.resize(size);
    }
    
    void put(int key, int value) {
        int bucket_no = key % size;
        auto &chain = buckets[bucket_no];

        for(auto &it: chain){
            if(it.first == key){
                it.second = value;
                return;
            }
        }
        chain.emplace_back(key, value);
    }
    
    int get(int key) {
        int bucket_no = key % size;
        auto &chain = buckets[bucket_no];

        if(chain.empty()) return -1; //chain hi khaali hai,mtlb key present hi nhi hai chain or list mein
        
        for(auto &it: chain){
            if(it.first == key)
                return it.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int bucket_no = key % size;
        auto &chain = buckets[bucket_no];
        /*it = {a, b}, it is a pair not a ptr, it ek value hai so isliye for loop change hogi

        for(auto &it : chain){
            if(it.first == key){
                chain.erase(it);//kisi bhi container ka erase() hmesha ptr leta hai & it ek value hai
                return;
            }
        }*/

        //chain.begin() ptr hai chain ke starting ka, ab it ptr hai isliye -> use hoga
        for(auto it = chain.begin(); it != chain.end(); it++){
            if(it->first == key){
                chain.erase(it);
                return;
            }
        }
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */