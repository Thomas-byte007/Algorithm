//damn shit,我居然一次过了一道中等题，太爽了

/* 
    url:https://leetcode.cn/problems/path-sum-ii/description/
    tags:binaryTree,dfs,bfs
    difficulty:medium

    approach&thought:
    和112一样的思路，只不过这里要用vector记录所有的路径

    同时由于它要遍历整棵树，且不需要对递归值进行处理，所以不需要返回值

*/

class Solution {
public:
    vector<vector<int>> result;
    void Traversal(TreeNode* cur,int sum,vector<int>& path){  //path传的是引用
        path.push_back(cur->val);  //中

        if(cur->left==nullptr && cur->right==nullptr && sum-cur->val==0)  //是叶子节点且接收值减当前值为0，说明找到一条路径
            result.push_back(path);

        if(cur->left){//sum暗藏回溯
            Traversal(cur->left,sum-cur->val,path);
            path.pop_back();  //path回溯
        }

        if(cur->right){
            Traversal(cur->right,sum-cur->val,path);
            path.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        if(root==nullptr) return result;
        Traversal(root,targetSum,path);
        return result;
    }
};