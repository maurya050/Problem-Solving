class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));
        int totalOne = 0;
        queue<pair<pair<int, int>, int>> q;
        for(int i =0; i< n; i++){
            for(int j =0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                }
                if(mat[i][j] == 1)
                    totalOne++;
            }
        }
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while(!q.empty() and totalOne != 0){
            int sz = q.size();
            for(int it= 0; it < sz; it++){
                int pi = q.front().first.first;
                int pj = q.front().first.second;
                int distance = q.front().second;
                q.pop();
                for(auto delta : dir){
                    int ni = pi + delta[0];
                    int nj = pj + delta[1];
                    if(ni>=0 and ni<n and nj >=0 and nj<m and 
                    vis[ni][nj] != 1 and mat[ni][nj] == 1){
                        vis[ni][nj] = 1;
                        ans[ni][nj] = distance + 1;
                        totalOne--;
                        q.push({{ni, nj}, distance + 1});
                    }
                }
            }

        }
        return ans;
    }
};