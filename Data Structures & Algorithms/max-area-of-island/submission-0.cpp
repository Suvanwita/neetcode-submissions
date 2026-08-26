class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int n=grid.size();
        int m=grid[0].size();

        vis[r][c]=1;

        int dr[]={0,0,-1,1};
        int dc[]={1,-1,0,0};

        int ans=1;

        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                ans+=dfs(nr,nc,grid,vis);
            }
        }

        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    ans=max(ans,dfs(i,j,grid,vis));
                }
            }
        }

        return ans;
    }
};
