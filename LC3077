//lc 3077:maximum strength of k disjoint subarrays
class Solution {
public:
typedef long long ll;
int n;
vector<vector<vector<ll>>>t;
ll f(int i,int k,int start,vector<int>&nums){
    if(k==0)return 0;
    if(i==n)return -(ll)4e18;
    if(t[i][k][start]!=(ll)1e16)return t[i][k][start];
    ll ans=-4e18;
    if(start)ans=f(i+1,k,1,nums);
    int wt=(k%2==1)?k:-k;
    ans=max(ans,f(i+1,k,0,nums)+1LL*wt*nums[i]);
    ans=max(ans,f(i+1,k-1,1,nums)+1LL*wt*nums[i]);
    return t[i][k][start]=ans;

}
    long long maximumStrength(vector<int>& nums, int k) {
        n=nums.size();
        t.resize(n+1,vector<vector<ll>>(k+1,vector<ll>(2,(ll)1e16)));
        return f(0,k,1,nums);
    }
};
