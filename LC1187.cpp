/*
LeetCode 828 - Count Unique Characters of All Substrings
https://leetcode.com/problems/count-unique-characters-of-all-substrings/

Idea:
Contribution technique using previous and next occurrence.

Time: O(n)
Space: O(n)
*/
class Solution {
public:
    vector<int> v;
    map<pair<int,int>, int> dp;  // (index, prevValue) -> answer
    int m;

    int f(vector<int>& arr, int i, int prev){
        if(i == m) return 0;

        if(dp.count({i, prev})) 
            return dp[{i, prev}];

        int x= 1e9,y=1e9;

        // Option 1: keep arr[i]
        if(arr[i] > prev){
            x = f(arr, i+1, arr[i]);
        }

        // Option 2: replace with smallest > prev
        auto it = lower_bound(v.begin(), v.end(), prev+1);
        if(it != v.end()){
        y= 1 + f(arr, i+1, *it);
        }

        return dp[{i, prev}] = min(x,y);
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        v = arr2;
        sort(v.begin(), v.end());
       // v.erase(unique(v.begin(), v.end()), v.end()); // remove duplicates

        m = arr1.size();
        int res = f(arr1, 0, -1);

        return res >= 1e9 ? -1 : res;
    }
};

