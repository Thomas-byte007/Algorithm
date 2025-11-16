/* 
    110. 平衡二叉树
    URL:https://leetcode.cn/problems/balanced-binary-tree/description/
    tags:Depth-First-Search,Tree,BinaryTree
    difficulty:easy

    approach&思路：
    平衡二叉树就是求每个节点的左右子树的高度差是否小于1，而求高度是采用后序遍历，方便把每个节点的高度一层一层的传上去。

    由于只要有一个节点的左右子树高度差超过1，那么这个节点就不是平衡二叉树。所以当出现左右子树高度差超过1的节点时，我们可以直接返回-1，减少递归次数,也就是剪枝。

    最后就是在ifBalanced函数中拿到getHeight的返回结果，只要不为-1说明它就是一颗平衡二叉树。

    时间复杂度：O(n)     最坏情况是，n个节点都会被访一次

    空间复杂度：O(h)  h为树的高度
*/

class Solution {
public:
    int getHeight(TreeNode* cur){
        if(cur==nullptr) return 0;

        int leftheight = getHeight(cur->left);
        if(leftheight==-1) return -1;  //剪枝
        int rightheight = getHeight(cur->right);
        if(rightheight==-1) return -1;
        
        return abs(leftheight-rightheight)>1 ? -1 : 1+max(leftheight,rightheight);  //大于1说明不是平衡二叉树，直接返回-1；小于等于1说明该节点符合平衡二叉树，返回该节点的高度
    }
    bool isBalanced(TreeNode* root) {
        return getHeight(root)==-1 ? false : true;
    }
};




/* 
    257. 二叉树的所有路径
    url: https://leetcode.cn/problems/binary-tree-paths/description/
    tags:binaryTree,recall,vector
    difficulty:easy

    approach&思路：
    看到这题很容易想到找一个容器记录单条路径，碰到叶子结点就把当前路径加入到结果容器中。而且既然是从根节点向下遍历，很显然是深度优先遍历，采用前序遍历。

    这个容器可以采用vector或者string。

    那么又会想到找到一条路径后又该怎么做呢，总不能每次都从头遍历吧。此时应该想到回溯，找到一条路径（叶子节点）后，返回上一节点，再去寻找这个节点的另一边有没有孩子。

    注意：递归和回溯永远在一起

    时间复杂度：O(n*h)

    空间复杂度：O(L*h)
*/

class Solution {
public:
    void Traversal(TreeNode* cur,vector<int>& path,vector<string>& result){
        path.push_back(cur->val);  //前序遍历，此为中的逻辑

        //由于题目规范了提交形式，所以在找到一条路径后还有对其进行处理，由于这里用的是vector<int>,所以要将其转换为string。
        if(cur->left==nullptr && cur->right==nullptr){
            string s;
            for(int i=0; i<path.size()-1; i++){
                s += to_string(path[i]);  //注意int类型转换为string类型要用to_string
                s += "->";
            }
            s += to_string(path[path.size()-1]);
            result.push_back(s);
        }

        //递归完了紧跟回溯，主打一个不离不弃
        if(cur->left){
            Traversal(cur->left,path,result);
            path.pop_back();
        }

        if(cur->right){
            Traversal(cur->right,path,result);
            path.pop_back();
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> result;
        //由于Traversal的判空逻辑换成了判叶子结点的逻辑，所以这里要对root进行判空
        if(root==nullptr) return result;
        Traversal(root,path,result);
        return result;
    }
};



/* 
    404.左叶子之和
    url:https://leetcode.cn/problems/sum-of-left-leaves/description/
    tags:binaryTree,dfs
    difficulty:easy

    appaorch&思路：
    求所有左叶子之和可以拆分为求左子树的左叶子之和和求右子树的左叶子之和，那么就和求高度一样，每个节点的数据要一层一层的往上传，所以采用后序遍历。

    时间复杂度：O(n)

    空间复杂度：O(h)
*/

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==nullptr) return 0;
        if(root->left==nullptr && root->right==nullptr) return 0;  //让递归少一层

        int leftValue = sumOfLeftLeaves(root->left);
        if(root->left && root->left->left==nullptr && root->left->right==nullptr){
            leftValue = root->left->val;
        }  //这里要进行数据覆盖，不然最后的结果都为0
        int rightValue = sumOfLeftLeaves(root->right);

        return leftValue + rightValue;
    }
};




/* 
    222.完全二叉树的节点个数
    url:https://leetcode.cn/problems/count-complete-tree-nodes/description/
    tags:binary search,tree,bit manipulation

    approach&思路：
    没啥方法，和求普通树的节点个数一样

    时间复杂度：O(n)

    空间复杂度：O(h)
*/

//递归遍历
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int leftNode = countNodes(root->left);
        int rightNode = countNodes(root->right);
        return 1 + leftNode + rightNode;
    }
};


//层序遍历
class Solution {
public:
    int countNodes(TreeNode* root) {
        queue<TreeNode*> q;
        if(root!=nullptr) q.push(root);
        int result = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            result += size;
        }
        return result;
    }
};


/* 
    513.找树左下角的值
    url:https://leetcode.cn/problems/find-bottom-left-tree-value/description/
    tags:binaryTree,trace back
    difficulty:medium

    approach&thought:
    找树左下角的值就是找该树最后一层的第一个节点的值，那么很容易想到前序遍历，只要对每一层的第一个节点记录一下就行了。

    这里采用递归的方法，采用中序遍历，再定义一个maxDepth，只要当前层的depth第一次超过了maxDepth，那么就找到了目标节点，记录下来即可

    在这里depth暗藏了回溯的思想，因为它只是把当前值传了过去。传参可以改为depth+1

    时间复杂度：O(n)

    空间复杂度：O(h)
*/

class Solution {
public:
    int maxDepth = 0;
    void getValue(TreeNode* cur,int depth,int& result){ //depth没传引用，暗藏了回溯的思想
        if(cur==nullptr) return;
        depth++;
        if(depth>maxDepth){
            maxDepth = depth;
            result = cur->val;
        }

        getValue(cur->left,depth,result);
        getValue(cur->right,depth,result);

    }
    int findBottomLeftValue(TreeNode* root) {
        int result = 0;
        int depth = 0;
        getValue(root,depth,result);
        return result;
    }
};