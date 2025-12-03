/* 
    url:https://leetcode.cn/problems/merge-intervals/description/
    tags:greedy
    difficulty:medium
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),
            [](const vector<int>& a,const vector<int>& b){return a[0]<b[0];});

        vector<vector<int>> Result;
        Result.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            if(Result.back()[1] >= intervals[i][0]){
                Result.back()[1] = max(intervals[i][1],Result.back()[1]);
            }else{
                Result.push_back(intervals[i]);
            }
        }
        return Result;
    }
};