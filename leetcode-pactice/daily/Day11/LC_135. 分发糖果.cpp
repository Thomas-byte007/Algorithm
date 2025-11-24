/* 
    url:https://leetcode.cn/problems/candy/description/
    tags:greedy
    difficulty:hard

    approach&thought:
    这里要严格保证相邻节点中rating大的要比rating小的要多
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candyVec(ratings.size(),1);
        for(int i=1; i<ratings.size(); i++){  //第一次遍历，先将当前孩子与左边的孩子进行比较，比左边的孩子评分高就令这个孩子的糖果比他多一个。这里也是第一个局部最优，
            if(ratings[i]>ratings[i-1]){                                                                                                   //严格保证比左边评分低的孩子的糖多
                candyVec[i] = candyVec[i-1] + 1;
            }
        }

        for(int i=ratings.size()-2; i>=0; i--){  //第二次遍历，将当前孩子与右边孩子进行比较
            if(ratings[i]>ratings[i+1]){
                candyVec[i] = max(candyVec[i],candyVec[i+1] + 1);  //这里要将第一次遍历的糖果和第二次遍历的糖果进行比较，不然会出错。第二个局部最优
            }
        }

        int result = 0;
        for(int a : candyVec){
            result += a;
        }

        return result;
    }
};