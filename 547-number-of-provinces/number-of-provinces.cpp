class Solution {
public:
    void bfs(int node, vector<int> adj[], vector<int> &vis){
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int ver = q.front();
            vis[ver] = 1;
            q.pop();
            for(auto nei : adj[ver]){
                if(!vis[nei]){
                    q.push(nei);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        vector<int> adj[n];

        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }
        int count = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                bfs(i, adj, vis);
                count++;
            }
        }
        return count;
    }
};