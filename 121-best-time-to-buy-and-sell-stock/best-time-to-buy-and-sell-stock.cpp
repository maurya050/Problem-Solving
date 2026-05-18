class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxOut = 0;
        int minimal = 1e4;

        for(int x : prices){
            maxOut = max(maxOut, (x-minimal));
            if(x < minimal)
                minimal = x;
        }
        return maxOut;
    }
};