class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> mp;
        int odd = 0;
        char extra;
        for(char c : s){
            mp[c]++;
        }
        string ans = "";
        for(auto it : mp){
            char ch = it.first;
            int freq = it.second;
            if(freq % 2){
                extra = ch;
                odd = 1;
            }
            
            freq = freq /2;
            ans = ans.append(freq, ch);
        }
        string out  = ans;
        if(odd)
            out += extra;
        reverse(ans.begin(), ans.end());
        return out+ans;
    }
};