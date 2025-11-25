/* 
    url:https://leetcode.cn/problems/lemonade-change/description/
    tags:greedy
    difficulty:easy;

*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> money(2,0);  //    用vector来记录当前5块和10块的零钱数量，20不用记，因为没必要
        for(int i=0; i<bills.size(); i++){
            if(bills[i]==5){  //当支付5元时，不用找零，5元零钱加一
                money[0]++;
            }else if(bills[i]==10){  //当支付10元时，需要找一张5元的
                money[1]++;
                money[0]--;
            }else if(bills[i]==20){  //当支付为20时，这里有两种找零方式
                if(money[1]>0){  //如果有10元的就优先找10元的，然后再找一张5元的
                    money[1]--;
                    money[0]--;
                }else{
                    money[0] -= 3;  //没有10元的就找三张5元的
                }
            }
            if(money[0]<0 || money[1]<0) return false;  //每次找完零都判断当前剩余零钱是否为负数，如果为负就说明这次找零已经不成功了
        }
        return true;
    }
};