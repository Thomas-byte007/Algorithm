/* 
    url:https://leetcode.cn/problems/jump-game-ii/description/
    tags:greedy
    difficulty:medium
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        int curDistance = 0; //当前能达到的最远位置
        int ans = 0; //步数
        int nextDistance = 0; //下一步能达到的最远位置
        for(int i=0; i<nums.size(); i++){
            nextDistance = max(nums[i]+i,nextDistance); //如果当前位置比之前的位置能达到的最远距离大，就把它记下，方便后面调到这个位置后进行下一步操作
            if(i==curDistance){  //如果达到当前能达到的最远位置，就考虑要跳一步了，并且要调到上面遍历到的能跳的远的位置
                ans++;  // 跳一步
                curDistance = nextDistance;  //更新当前能达到的最远位置
                if(curDistance>=nums.size()-1){  //如果当前能达到的最远位置已经超过了nums.size()-1(下标)，就不用再跳了
                break;
            }
            
            }
        }
        return ans;
    }
};  