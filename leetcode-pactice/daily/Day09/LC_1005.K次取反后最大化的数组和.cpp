/* 
    url:https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/description/
    tags:greedy
    difficulty:easy

    approach&thought:
    局部最优：让绝对值大的负数变为正数，当前数值达到最大

    局部最优：找最小的正数取反
*/

class Solution {
public:
    static bool cmp(int a,int b){
        return abs(a) > abs(b);
    }  //指定排序规则
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),cmp);  //先让数组从大到小进行排序
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0 && k>0){
                nums[i] *= -1;
                k--;
            }
        }  //先把绝对值大的负数全部转换为整数
        if(k%2==1) nums[nums.size()-1]*=-1;  //如果k还有剩的话，判断它的奇偶性，如果为偶：对一个正数取反两次值不变，如果为奇：那么就对最小的正数取反，使得对结果的影响最小
        int result = 0;
        for(int a : nums){
            result+=a;
        }
        return result;
    }
};