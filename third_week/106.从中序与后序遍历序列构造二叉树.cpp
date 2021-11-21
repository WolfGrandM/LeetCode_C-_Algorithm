/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*完全仿照官方和其他题解仿写的答案*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);

TreeNode *
myBuildTree(vector<int> preorder, vector<int> inorder, int preorder_left, int preorder_right, int inorder_left,
            int inorder_right);

void print1(TreeNode *root) {
    if (root != nullptr) {
        cout << root->val << " ";
        print1(root->left);
        print1(root->right);
    }
}

void print2(TreeNode *root) {
    if (root != nullptr) {
        print2(root->left);
        cout << root->val << " ";
        print2(root->right);
    }
}

void print3(TreeNode *root) {
    if (root != nullptr) {
        print3(root->left);
        print3(root->right);
        cout << root->val << " ";
    }
}

map<int, int> m;

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *root = buildTree(preorder, inorder);
    print1(root);
    cout << endl;
    print2(root);
    cout << endl;
    print3(root);
    return 0;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = preorder.size();
    for (int i = 0; i < n; ++i) {
        m[inorder[i]] = i;
    }
    return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
}

TreeNode *myBuildTree(vector<int> preorder, vector<int> inorder, int preorder_left, int preorder_right, int inorder_left,
            int inorder_right) {
    if (inorder_left > inorder_right) {
        return nullptr;
    }
    int preorder_root = preorder_left;
    int inorder_root = m[preorder[preorder_root]];
    TreeNode *root = new TreeNode(preorder[preorder_root]);
    int left_subtree = inorder_root - inorder_left;
    root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + left_subtree, inorder_left,
                             inorder_root - 1);
    root->right = myBuildTree(preorder, inorder, preorder_left + 1 + left_subtree, preorder_right, inorder_root + 1,
                              inorder_right);
    return root;
}


作者：gu-cheng-shen-qiang
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/solution/wan-quan-fang-zhao-di-105ti-de-guan-fang-fc6j/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
// @lc code=end

