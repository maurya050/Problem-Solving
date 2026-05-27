class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int num : nums){
            pq.push(num);
            mp[num]++;
            if(pq.size() > k){
                int x = pq.top();
                mp[x]--;
                pq.pop();
                if(mp[x] == 0)
                    mp.erase(x);
            }
        }

        for(int x : nums){
            if(mp.count(x) > 0){
                ans.push_back(x);
                mp[x]--;
                if(mp[x] == 0)
                    mp.erase(x);
            }
        }
        return ans;
    }
};