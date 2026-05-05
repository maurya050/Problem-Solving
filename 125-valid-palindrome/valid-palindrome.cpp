class Solution {
public:
    bool isPalindrome(string s) {
        string fil;
        
        for(char c : s){
            if(isalnum(c)){
                fil += tolower(c);
            }
        }
        int n = fil.size();
        int left = 0;
        int right = n-1;

        while(left < right){
            if(fil[left] != fil[right])
                return false;
            left++, right--;
        }
        return true;
    }
};