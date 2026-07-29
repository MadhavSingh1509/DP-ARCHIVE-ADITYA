class Solution {
public:
const int mod=1e9+7;
    int distinctSubseqII(string s) {
        vector<int>ends(26,0);

        for(auto ch:s){
            long long count=0;
         for(auto cnt:ends)count=(count+cnt)%mod;
ends[ch-'a']=(count+1)%mod;
        }
        long long ans=0;
        for(auto cnt:ends)ans=(ans+cnt)%mod;
        return ans;

    }
};