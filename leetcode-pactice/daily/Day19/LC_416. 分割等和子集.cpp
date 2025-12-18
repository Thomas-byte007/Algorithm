/* 
    url:https://leetcode.cn/problems/partition-equal-subset-sum/description/
    difficulty:medium
    tags:01背包
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        vector<int> dp(10001,0);
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1) return false;
        int bagweight = sum/2;

        for(int i=0; i<nums.size(); i++){
            for(int j=bagweight; j>=nums[i]; j--){
                dp[j] = max(dp[j],dp[j-nums[i]]+nums[i]);
            }
        }

        if(bagweight == dp[bagweight]) return true;
        return false;
    }
};