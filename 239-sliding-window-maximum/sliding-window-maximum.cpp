class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i =0, j =0, n = nums.size();
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        while(j < n){
            pq.push({nums[j], j});

            while(j-i+1 == k){
                
                while(i > pq.top().second)
                    pq.pop();
                ans.push_back(pq.top().first);
                i++;
            }

            j++;
        }
        return ans;
    }
};