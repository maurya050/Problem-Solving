class Solution {
public:
    int product(int n){
        int val = 1;
        while(n){
            int r = n%10;
            val *= r;
            n = n/10;
        }
        return val;
    }
    int smallestNumber(int n, int t) {
        for(int i=0; i<=t; i++){
            int val = product(n+i);
            if(val % t == 0)
                return n+i;
        }
        return 0;
        
    }
};