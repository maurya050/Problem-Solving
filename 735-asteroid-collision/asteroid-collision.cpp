class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;

        for(int x : asteroids){
            if(!st.empty()){
                if(x > 0){
                    st.push(x);
                }
                else{
                    while(!st.empty() && st.top() > 0 && st.top() < -x)
                        st.pop();
                    if(st.empty() || st.top() < 0)
                        st.push(x);
                    
                    if(!st.empty() && st.top() == -x)
                        st.pop();                }
            }
            else{
                st.push(x);
            }

        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;

    }
};