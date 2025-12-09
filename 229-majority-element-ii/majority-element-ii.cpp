class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int val : nums){
            mp[val]++;
        }
        int target = nums.size()/3;
        for(auto it : mp){
            if(it.second > target){
                ans.push_back(it.first);
            }
        }
        return ans;
    }

};