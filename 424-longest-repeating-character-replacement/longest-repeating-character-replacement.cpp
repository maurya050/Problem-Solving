class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int maxfreq = 0, ans = 0, i=0, j=0;

        while(j < s.size())
        {
            mp[s[j]]++;
            maxfreq = max(maxfreq, mp[s[j]]);
            if(j-i+1-maxfreq > k){
                while((j-i+1 -maxfreq > k))
                {
                    mp[s[i]]--;
                    i++;
                }
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};