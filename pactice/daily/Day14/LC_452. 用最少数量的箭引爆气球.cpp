/* 
    url:https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/description/
    tags:greedy
    diffilculty:medium
*/

class Solution {
private:
    bool static cmp(vector<int>& a,vector<int>& b){
        return a[0] < b[0];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        sort(points.begin(),points.end());

        int result = 1;
        for(int i=1; i<points.size(); i++){
            if(points[i][0]>points[i-1][1]){
                result++;
            }else{
                points[i][1] = min(points[i][1],points[i-1][1]);
            }
        }

        return result;
    }
};