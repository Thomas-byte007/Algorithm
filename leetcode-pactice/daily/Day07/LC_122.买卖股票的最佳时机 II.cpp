/* 
    url:https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/
    tags:greedy
    diffficulty:medium

    approach&thought:
    局部最优：只有在明天价格比今天价格高时，才进行一次买卖操作
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); i++) {
            result += max(prices[i] - prices[i - 1], 0);
        }
        return result;
    }
};