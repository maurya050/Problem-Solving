class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        set<int> hashSet(nums.begin(), nums.end());
        int maximum= 0;

        for(auto x : hashSet)
        {
            if(!hashSet.count(x-1))
            {
                int curr_num = x;
                int curr_len = 1;

                while(hashSet.count(curr_num+1))
                {
                    curr_num += 1;
                    curr_len += 1;
                }
                maximum = max(maximum, curr_len);
            }
        }
        return maximum;
        
    }
};