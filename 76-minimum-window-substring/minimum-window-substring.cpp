class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        int n = s.size();
        int m = t.size();   

        if(m > n) return "";

        for(int i = 0; i<t.size(); i++){
            mp[t[i]]++;
        }

        int count = mp.size();
        int j =0, i = 0, sz = INT_MAX, startInd = 0;
        string ans;
        while(j < n){
            if(mp.count(s[j])){
                mp[s[j]]--;
                if(mp[s[j]] == 0)
                    count--;
            }
            if(count == 0){
                
                while(count == 0){
                    if(sz > j-i+1){
                        sz = j-i+1;
                        startInd = i;
                    }
                    if(mp.count(s[i]))
                    {
                        mp[s[i]]++;
                        if(mp[s[i]] == 1)
                            count++;
                    }
                    i++;
                }
            }
            j++;
        }   
        return sz == INT_MAX ? "" : s.substr(startInd, sz);
    }
};