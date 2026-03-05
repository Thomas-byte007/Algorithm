/* 
    虽然老是搞错变量名，虽然老是弄混逻辑，虽然用时排名倒数，但也好歹是没看题解靠自己写出来了，还是很开心

    url:https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
    tags:binaryTree,hash table ,分治
    difficulty:medium

    approach&thought:
    如果在纸上写的话这题不难，但是要用代码实现的话就有点难度了。
    首先后序遍历数组的最后一个肯定是根节点，那么我们可以通过这个根节点来将中序数组切割为左中序数组和右中序数组（这里我用了两个vector);
    同时还要注意，当记录了后序数组的最后一个元素后，应当将这个元素弹出；还有一点就是元素左边相邻的元素是其右子树的根节点，所以递归时要采用中右左的顺序

    这里由于要将每个节点连起来，所以返回值采用了TreeNode*

    时间复杂度：O(n*n)

    空间复杂度：O(n*n)
*/

class Solution {
public:

    TreeNode* Traversal(vector<int> inorder,vector<int>& postorder){
        if(postorder.empty()) return nullptr;

        TreeNode* cur = new TreeNode();  //记录后序数组的最后一个值
        cur->val = postorder[postorder.size()-1];
        postorder.pop_back();  // 弹出后序数组的最后一个值

        vector<int> left_inorder,right_inorder;  //创建左中序数组和右中序数组
        for(int i=0; i<inorder.size(); i++){
            if(inorder[i]==cur->val){
                for(int j=i+1; j<inorder.size(); j++){
                    right_inorder.push_back(inorder[j]);
                }
                break;
            }else{
                left_inorder.push_back(inorder[i]);
            }
        }

        
        if(!right_inorder.empty()){  //先递归右子树
            cur->right = Traversal(right_inorder,postorder);
        }
        if(!left_inorder.empty()){
            cur->left = Traversal(left_inorder,postorder);
        }

        return cur;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return Traversal(inorder,postorder);
    }
};


/* 
    以下为题解方法，思路差不多，只不过题解还对后续数组做切割了
*/

class Solution {
private:
    TreeNode* traversal (vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) return NULL;

        // 后序遍历数组最后一个元素，就是当前的中间节点
        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);

        // 叶子节点
        if (postorder.size() == 1) return root;

        // 找到中序遍历的切割点
        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue) break;
        }

        // 切割中序数组
        // 左闭右开区间：[0, delimiterIndex)
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        // [delimiterIndex + 1, end)
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end() );

        // postorder 舍弃末尾元素
        postorder.resize(postorder.size() - 1);

        // 切割后序数组
        // 依然左闭右开，注意这里使用了左中序数组大小作为切割点
        // [0, leftInorder.size)
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        // [leftInorder.size(), end)
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return NULL;
        return traversal(inorder, postorder);
    }
};

//第二中方法：用索引而不是vector
class Solution {
private:
    // 中序区间：[inorderBegin, inorderEnd)，后序区间[postorderBegin, postorderEnd)
    TreeNode* traversal (vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& postorder, int postorderBegin, int postorderEnd) {
        if (postorderBegin == postorderEnd) return NULL;

        int rootValue = postorder[postorderEnd - 1];
        TreeNode* root = new TreeNode(rootValue);

        if (postorderEnd - postorderBegin == 1) return root;

        int delimiterIndex;
        for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue) break;
        }
        // 切割中序数组
        // 左中序区间，左闭右开[leftInorderBegin, leftInorderEnd)
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;
        // 右中序区间，左闭右开[rightInorderBegin, rightInorderEnd)
        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd = inorderEnd;

        // 切割后序数组
        // 左后序区间，左闭右开[leftPostorderBegin, leftPostorderEnd)
        int leftPostorderBegin =  postorderBegin;
        int leftPostorderEnd = postorderBegin + delimiterIndex - inorderBegin; // 终止位置是 需要加上 中序区间的大小size
        // 右后序区间，左闭右开[rightPostorderBegin, rightPostorderEnd)
        int rightPostorderBegin = postorderBegin + (delimiterIndex - inorderBegin);
        int rightPostorderEnd = postorderEnd - 1; // 排除最后一个元素，已经作为节点了

        root->left = traversal(inorder, leftInorderBegin, leftInorderEnd,  postorder, leftPostorderBegin, leftPostorderEnd);
        root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, postorder, rightPostorderBegin, rightPostorderEnd);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return NULL;
        // 左闭右开的原则
        return traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};