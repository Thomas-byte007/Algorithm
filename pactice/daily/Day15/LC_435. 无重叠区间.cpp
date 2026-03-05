/* 
    url:https://leetcode.cn/problems/non-overlapping-intervals/description/
    tags:greedy
    diffilculty:medium
*/

class Solution {
private:
    bool static cmp(vector<int>& a,vector<int>& b){
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);  //右边小的排前面
        int count = 1;  //记录的是非重叠的区间
        int end = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(end<=intervals[i][0]){
                count++;
                end = intervals[i][1];
            }
        }
        return intervals.size()-count;
    }
};