/* 
    url:https://leetcode.cn/problems/gas-station/description/
    tags:greedy
    difficulty:medium

    approach&thought:
    从头开始遍历，每到一个加油站都记录当前加油站能加的油和去下一个加油站需要的油的差值，当这个差值小于0时，说明从0到当前加油站都不能作为起始加油站，直接从当前加油站的下一个加油站
    开始算（局部最优，前面的为负直接舍去）
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;  //记录总的（gas值-cost值）
        int start = 0;  //记录起始加油站
        for(int i=0; i<gas.size(); i++){
            curSum = gas[i] - cost[i];
            totalSum += gas[i] - cost[i];

            if(curSum<0){  //一旦小于0，说明前面的节点都不符合，值=直接从下一个加油站重新开始
                start = i+1;
                curSum = 0;
            }
        }
        if(totalSum<0) return -1;  //小于0说明总的油还没花费的油多，一定跑不完一圈

        return start;
    }
};