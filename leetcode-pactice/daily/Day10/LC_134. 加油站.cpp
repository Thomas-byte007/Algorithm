/* 
    url:https://leetcode.cn/problems/gas-station/description/
    tags:greedy
    difficulty:medium

    approah&thought:
    这里用的是暴力解答，把每个加油站绕行一圈，力扣时间超限了

    时间复杂度：O(n*n)
*/


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0; i<cost.size(); i++){
            int rest = gas[i] - cost[i];
            int index = (i+1)%cost.size();
            while(rest>0 && index!=i){
                rest += gas[index] - cost[index];
                index = (index+1) % cost.size();
            }
            if(rest>=0 && index==i) return i;
        }
        return -1;
    }
};