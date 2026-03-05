/* 
    url:https://leetcode.cn/problems/wiggle-subsequence/description/
    tags:greedy
    difficulty:medium

    approach&thought:
    我们可以把摆动转换为折线图，只要节点前后的折现方向不一样，就说明它摆动了一次。
    这里要求的是能使某数组成为摆动序列的最大子序列长度，节点前后折线方向一样是不会摆动的，所以求最大子序列就是把多余节点都去掉，只留波峰或波谷节点。
    此时我们就可以用prediff和curdiff来分别记录该节点的前后差值正负，如果prediff>0 && curdiff<0或者prediff<0 && curdiff>0,就说明该节点为摆动节点，长度应该加1。

    但要注意了，这里有三种特殊情况：
    1.折线图有平坡，说明有多个相同节点，此时的diff=0，可能会出现prediff=0或curdiff=0的情况，如果不考虑的话长度就少了1。那么我们这里可以认为规定一种情况让length+1，
      我们这里就规定当prediff=0&&curdiff>(<0)时，也算摆动了一下
    2.数组首尾两端，题目说了nums里只有一个或者两个不等元素时，也算摆动序列，那么这里我们可以不单独处理把它写死，可以假设前面有一个平坡，然后让result初始值为1（默认最右面有一个摆动）
    3.单调坡度有平坡，这种情况会导致结果多1，这里规定出现峰值才让prediff=curdiff就好了
*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int curDiff = 0; // 当前一对差值
        int preDiff = 0; // 前一对差值
        int result = 1;  // 记录峰值个数，序列默认序列最右边有一个峰值
        for (int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];
            // 出现峰值
            if ((preDiff <= 0 && curDiff > 0) || (preDiff >= 0 && curDiff < 0)) {
                result++;
                preDiff = curDiff; // 注意这里，只在摆动变化的时候更新prediff
            }
        }
        return result;
    }
};