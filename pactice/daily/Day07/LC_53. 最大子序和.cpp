/* 
    url:https://leetcode.cn/problems/maximum-subarray/description/
    tags:greedy
    difficulty:medium

    approch&thought:
    贪心思想   如果当前子数组和为负或者小于当前子数组和＋当前元素之和，那么就从当前元素开始更新子数组（局部最优，如果前面子数组对当前元素产生为负效果，就把它贪掉）-> 子数组和最大（全局最优）

*/
//方法一
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        int cur_sum = 0;
        for(int i=0; i<nums.size(); i++){
            cur_sum += nums[i];
            result = max(result,cur_sum);
            if(cur_sum<0){
                cur_sum = 0;
            }
        }
        return result;
    }
};
//方法二
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
          int current_sum = nums[0];
          int result = nums[0];
          for(int i=1; i<nums.size(); i++){
            current_sum = max(current_sum+nums[i],nums[i]);
            result = max(current_sum,result);
          }
          return result;
    }
};