class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        if(k >= num.size())
            return "0";
        for(char c : num){
            if(st.empty()){
                st.push(c);
            }
            else{
                if(k > 0 && st.top()-'0' > c-'0'){
                    while(k > 0 && st.size() > 0 && st.top()-'0' > c-'0'){
                        st.pop();
                        k--;
                    }
                }
                st.push(c);
            }
        }
        string str = "";
        while(!st.empty()){
            if(k){
                st.pop();
                k--;
            }
            else{
                str += st.top();
                st.pop();
            }
        }
        reverse(str.begin(), str.end());
        
        int i = 0;
        for(char c : str){
            if(c == '0')
                i++;
            else
                break;
        }
        str = str.substr(i);
        return str == "" ? "0" : str;

    }
};