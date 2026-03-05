/* 
    url:https://leetcode.cn/problems/merge-two-binary-trees/description/
    tags:binaryTree,dfs
    difficulty:easy

    approach&thought:
    让两颗树的指针同步遍历，并且选取tree1为主
*/

class Solution {
public:
    TreeNode* Traversal(TreeNode* cur1,TreeNode* cur2){
        if(cur1==nullptr) return cur2;  //tree1节点为空，tree2节点不为空，返回tree2的节点
        if(cur2==nullptr) return cur1;  //与上面相反

        cur1->val += cur2->val;  //两颗树都有节点，此时将tree2节点的值加到tree1上
        cur1->left = Traversal(cur1->left,cur2->left);
        cur1->right = Traversal(cur1->right,cur2->right);

        return cur1;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return Traversal(root1,root2);
    }
};