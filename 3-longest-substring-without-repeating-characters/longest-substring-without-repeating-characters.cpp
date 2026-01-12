class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int hashmap[256];
        fill(hashmap, hashmap + 256, -1);
        int n = s.length(), l = 0, r = 0, maxlen = 0;
        while(r < n){
            if(hashmap[s[r]] != -1){
                if(hashmap[s[r]] >= l){
                    l = hashmap[s[r]] + 1;
                }
            }
            maxlen = max(maxlen, (r-l+1));
            hashmap[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};