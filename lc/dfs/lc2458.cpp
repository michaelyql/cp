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
const int N = 1e5 + 5;
class Solution {
    int ans[N];
    int mxh = 0;
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        ltr(root, 0);
        mxh = 0;
        rtl(root, 0);
        vector<int> ret(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            ret[i] = ans[queries[i]];
        }
        return ret;
    }
    void ltr(TreeNode* root, int h) {
        if (root == nullptr) return;
        ans[root->val] = mxh;
        mxh = max(mxh, h);
        ltr(root->left, h + 1);
        ltr(root->right, h + 1);
    }
    void rtl(TreeNode* root, int h) {
        if (root == nullptr) return;
        ans[root->val] = max(ans[root->val], mxh);
        mxh = max(mxh, h);
        rtl(root->right, h + 1);
        rtl(root->left, h + 1);
    }
};
