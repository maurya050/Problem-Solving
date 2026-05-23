class Solution {
public:
    int maximumArea(vector<int> &arr){
        int n = arr.size();
        vector<int> left(n, -1);
        vector<int> right(n, -1);
        int ans = INT_MIN;
        stack<pair<int, int>> st1;
        for(int i = 0; i<n; i++){
            if(st1.empty())
                left[i] = -1;
            else{
                if(st1.top().first < arr[i])
                    left[i] = st1.top().second;
                else{
                    while(st1.size() > 0 && st1.top().first >= arr[i])
                        st1.pop();
                    if(st1.empty())
                        left[i] = -1;
                    else
                        left[i] = st1.top().second;
                }
            }
            st1.push({arr[i], i});
        }
        stack<pair<int, int>> st2;
        for(int i = n-1; i>=0; i--){
            if(st2.empty())
                right[i] = n;
            else{
                if(st2.top().first < right[i])
                    right[i] = st2.top().second;
                else{
                    while(st2.size() > 0 && st2.top().first >= arr[i])
                        st2.pop();
                    if(st2.empty())
                        right[i] = n;
                    else
                        right[i] = st2.top().second;
                }
            }
            // cout<<arr[i]<<" ";
            st2.push({arr[i], i});
        }

        for(int j =0; j<n; j++){
            // cout<<right[j]<<" ";
            left[j] = right[j]-left[j]-1;
            
        }
        for(int i=0; i<n; i++)
            ans = max(ans, left[i]*arr[i]);

        // cout<<ans<<",  ";
        return ans;

    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int ans = INT_MIN;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> sumArray(m, 0);

        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(matrix[i][j] == '0')
                    sumArray[j] = 0;
                else
                    sumArray[j] += matrix[i][j]-'0';
            }
            ans = max(ans, maximumArea(sumArray));
        }
        return ans;
    }
};