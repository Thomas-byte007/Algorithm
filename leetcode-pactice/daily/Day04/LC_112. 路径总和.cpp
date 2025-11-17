//damn,一次过的感觉太爽了

/* 
    url：https://leetcode.cn/problems/path-sum/description/
    tags：binaryTree，dfs,bfs
    difficulty:easy

    approach&thought:
    这个只要找一条路径，找到了就可以返回，所以需要返回值

    时间复杂度：O(n)

    空间复杂度：O(h)
*/


class Solution {
public:
    bool Traversal(TreeNode* cur,int targetSum){  
        if(cur==nullptr) return false;

        if(targetSum-cur->val==0 && cur->left==nullptr && cur->right==nullptr)  //如果是叶子节点，并且传过来的值减去当前值正好为0的话，说明是一条路径
            return true;
        bool left = Traversal(cur->left,targetSum-cur->val);  //这里传的是接收值减去当前值，是隐藏的回溯
        bool right = Traversal(cur->right,targetSum-cur->val);

        return left || right;  //有一个为true就可以
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return Traversal(root,targetSum);
    }
};

//这道题还可以用bfs，也就是层序写