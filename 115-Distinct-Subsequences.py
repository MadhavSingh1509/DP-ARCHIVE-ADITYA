class Solution {
public:
string a,b;
int m,n;
int dp[1001][1001];
int f(int i,int j){
    if(j==n)return 1;
    if(i==m)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ways=0;
    if(a[i]==b[j])ways+=(f(i+1,j+1)+f(i+1,j));
    else ways+=f(i+1,j);
    return dp[i][j]=ways;
}
    int numDistinct(string s, string t) {
       memset(dp,-1,sizeof(dp));
       m=s.size();
       n=t.size(); 
       a=s,b=t;
       return f(0,0);
    }
};