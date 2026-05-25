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
                    if(st.top() < 0){
                        st.push(x);
                    }
                    else{
                        if(st.top() > abs(x))
                            continue;
                        else if(st.top() == abs(x))
                            st.pop();
                        else{
                            while(st.size() > 0 && st.top() > 0 && st.top()  < abs(x))
                                st.pop();
                            if(st.empty() || st.top() < 0)
                                st.push(x);
                            else if(st.top() > 0 && st.top() == abs(x))
                                st.pop();
                            else
                                continue;
                        }
                    }
                }
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