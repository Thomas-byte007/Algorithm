/* 
    url:https://leetcode.cn/problems/assign-cookies/description/
    tags:greedy,two point
    difficulty:easy

    approach&thought:
    我这里想的是小饼干分给小胃口的
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());  //要先排序
        sort(s.begin(),s.end());
        int count = 0;
        for(int i=0; i<s.size(); i++){
            int sele = s[i];
            if(count==g.size()) break;
            if(g[count]<=sele){
                count++;
            }
        }
        return count;
    }
};

/* 
    题解想的是大饼干先喂给大胃口的，符合贪心思想   局部最优（大饼干）-> 全局最优（喂饱人数最多）
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1; // 饼干数组的下标
        int result = 0;
        for (int i = g.size() - 1; i >= 0; i--) { // 遍历胃口
            if (index >= 0 && s[index] >= g[i]) { // 遍历饼干
                result++;
                index--;
            }
        }
        return result;
    }
};