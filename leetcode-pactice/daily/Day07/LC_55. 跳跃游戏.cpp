/* 
    url:https://leetcode.cn/problems/jump-game/description/
    tags:greedy
    difficulty:medium

    approach&thought:
    只要当前节点的值能覆盖到最后一个节点就行，局部最优：每次都取能跳的最大值
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if(nums.size()==1) return true;
        for(int i=0; i<=cover; i++){
            cover = max(cover,i+nums[i]);
            if(cover>=nums.size()-1) return true;
        }
        return false;
    }
};