/**
 * url:https://leetcode.cn/problems/ones-and-zeroes/description/
 * tags:dp
 */

 class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(const string& s : strs){
            int zeroNum=0,oneNum=0;
            for(char c : s){
                if(c=='0') zeroNum++;
                else oneNum++;
            }
            for(int x=m; x>=zeroNum; x--){
                for(int y=n; y>=oneNum; y--){
                    dp[x][y] = max(dp[x][y],dp[x-zeroNum][y-oneNum]+1);
                }
            }
        }
        return dp[m][n];
    }
};