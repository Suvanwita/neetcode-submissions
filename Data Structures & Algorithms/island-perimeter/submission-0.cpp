class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j){
        int n=grid.size();
        int m=grid[0].size();

        int dr[]={0,0,1,-1};
        int dc[]={1,-1,0,0};

        if(i<0 || j<0 || i>=n || j>=m){
                return 1;
        }
        if(grid[i][j]==0)
            return 1;
        if(vis[i][j])
            return 0;

        int peri=0;
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            peri+=dfs(grid,vis,nr,nc);
        }
        return peri;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j])
                    return dfs(grid,vis,i,j);
            }
        }

        return 0;
    }
};