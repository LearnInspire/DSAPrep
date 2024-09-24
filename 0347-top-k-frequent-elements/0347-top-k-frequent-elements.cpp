//Approach-1 (Using min-heap) - TC : O(nlog(n-k))
class Solution {
public:
    typedef pair<int, int> p;
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //min-heap
        priority_queue<p, vector<p>, greater<p>> pq;
        
        //count frequency of each element
        // Worst Case - n distinct elements are stored, so, space O(n)
        unordered_map<int, int> mp;
        for(int i : nums)
            mp[i]++;
        
        //Push in min-heap and maintain size k
        for(auto it:mp) {
            pq.push({it.second, it.first});
            
            if(pq.size() > k)
                pq.pop();
        }
        
        
        //Pick all top K elements
        vector<int> result;
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
/*class Solution {
public:
    //Approach-2 (Using Bucket Sort) - TC : O(n) - We visit all elements of nums only once
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //store all the freq in map
        unordered_map<int, int> mp;
        for(auto &num: nums){
            mp[num]++;
        }

        //define one bucket array where freq is arr[i] & index is element, index is freq, value = elements
        //bucket[i] = elements having i frequency
        int n = nums.size();
        vector<vector<int>> bucket(n+1); //n+1 bcz of size of array
        for(auto &it: mp){
            int element = it.first;
            int freq = it.second;
            bucket[freq].push_back(element);
        }

        //traverse the bucket array from left to right, bcz max freq will be from n to 0 & pop the top k elements
        vector<int> result;
        for(int i = n; i>=0; i--){
            if(bucket[i].size() == 0) continue; //bucket khali hai, uss freq ka koi element nhi avail hai
            while(bucket[i].size() > 0 && k > 0){
                result.push_back(bucket[i].back()); //back operation takes less time
                bucket[i].pop_back();
                k--;
            }
        }
        return result;
    }
};
*/