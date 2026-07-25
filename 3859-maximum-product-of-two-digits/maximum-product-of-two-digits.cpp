class Solution {
public:
    int maxProduct(int n) {
        vector<int> arr(10, 0);

        while(n){
            int r = n%10;
            arr[r] += 1;
            n = n/10;
            cout<< arr[r];
        }
        int ans = 1;
        int ind = 9;
        int count =0;
        while(ind >=0 && count <2){
            // count<< arr[ind];
            if(arr[ind] != 0){
                ans *= ind;
                arr[ind] -= 1;
                count++;
            }
            if(arr[ind] == 0)
                ind--;
        }
        return ans;
    }
};