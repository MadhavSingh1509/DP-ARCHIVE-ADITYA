class Solution {
public:
const int mod=1e9+7;
    int numberOfUniqueGoodSubsequences(string binary) {
        int zero=0;//no. of unique substrings starting with one and ending with zero
        int one=0;//no of unique substrings starting with 1 and ending with one
        int haszero=0;
        for(auto c:binary){
if(c=='0')zero=(zero+one)%mod;
else one=(one+zero+1)%mod;
if(c=='0')haszero=1;
        }
        return (haszero+one+zero)%mod;
        ////001101:-8
    
    }
};