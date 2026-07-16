class Solution {
public:
vector<vector<char>>v;
int m,n;
int dp[101][101][202];
bool f(int i,int j,int c){
if(i>=m ||j>=n||i<0||j<0)return false;
int add=v[i][j]==')'?-1:1;
int nc=c+add;
if(nc<0)return false;//early pruning
if(i==m-1&& j==n-1)return nc==0;
if(dp[i][j][c]!=-1)return dp[i][j][c];
bool x=f(i+1,j,nc);
bool y=f(i,j+1,nc);
return dp[i][j][c]=x||y;



    
}
    bool hasValidPath(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        v=grid;
        memset(dp,-1,sizeof(dp));

        return f(0,0,0);
    }
};