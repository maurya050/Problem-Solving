class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> right(n, 0);
        int rig = 0;
        for(int i=n-1; i>=0; i--){
            right[i] = rig;
            rig = max(rig, height[i]);
        }
        int lt=0, ans=0;
        for(int i =0; i< n; i++){
            int diff = min(lt, right[i]);
            if(diff > 0 && height[i] < diff)
                ans = ans + (diff - height[i]);
            lt = max(lt, height[i]);
        }
        return ans;
    }
};