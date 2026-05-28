class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& scores) {
        unordered_map<int, string> mp;
        priority_queue<int> pq;
        vector<string> ans;

        for(int val : scores){
            pq.push(val);
        }
        string str[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        
        for(int i=0; i<scores.size(); i++){
            int score = pq.top();
            mp[score] = i < 3 ? str[i] : to_string(i+1);
            pq.pop();
        }
        for(int score : scores){
            ans.push_back(mp[score]);
        }
        return ans;
        
    }   
};