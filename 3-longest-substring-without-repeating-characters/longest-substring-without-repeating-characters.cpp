class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> track(256, 0);
        int i =0, j=0;
        int n = s.length();
        int ans = 0;
        while(j < n){
            track[s[j]]++;
            while(track[s[j]] > 1){
                track[s[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};