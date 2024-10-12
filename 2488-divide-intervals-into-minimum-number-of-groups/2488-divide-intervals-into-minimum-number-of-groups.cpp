class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>>pq;
        // seedhi si baat hai, ek pq maintain kro, jisme bs end times rkho, lets say 1-3, 4-8, 5-7 
        // pele 3 daldo, ab jb 4-5 aya iske liye nya interval toh chahiye ni , but future me 5 ayega uske liye pehle se hi longest time i.e 8 dalkr rkhlo. aur agar jo sbse chota end hai usse bda aane wala inetrval hai toh obviously uska end bhi kisi kaam ka ni, since sorted hai tooh aane wale interval ka start bda hi hoga. 
        sort(intervals.begin(), intervals.end());
        for(auto it: intervals) {
            int start = it[0], end = it[1];
            if(pq.size() && start > pq.top()) pq.pop();
            pq.push(end);
        }
        return pq.size();
    }
};