class Solution {
public:
    int dr[4]={0,0,-1,1};
    int dc[4]={-1,1,0,0};
    
    void bfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>> q;
        q.push({r,c});
        vis[r][c]=1;

        while(!q.empty()){
            auto [row,col]=q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nr=row+dr[k];
                int nc=col+dc[k];

                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            if(grid[i][0]==1)
                bfs(i,0,grid,vis);
            if(grid[i][m-1]==1)
                bfs(i,m-1,grid,vis);
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==1)
                bfs(0,j,grid,vis);
            if(grid[n-1][j]==1)
                bfs(n-1,j,grid,vis);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j])
                    ans++;
            }
        }
        return ans;
    }
};