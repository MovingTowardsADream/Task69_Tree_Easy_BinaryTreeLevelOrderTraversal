#include <iostream>
#include <vector>
#include <queue>

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
class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
            return std::vector<std::vector<int>>({});
        std::vector<std::vector<int>> result;
        std::queue<TreeNode*> que;
        que.push(root);
        int count_last = 1, count_new = 0;
        bool new_vec = 1;
        while (!que.empty()) {
            if (new_vec) {
                result.push_back({ que.front()->val });
                new_vec = 0;
            }
            else {
                result[result.size() - 1].push_back(que.front()->val);
            }
            count_last--;
            if (que.front()->left != NULL) {
                que.push(que.front()->left);
                count_new++;
            }
            if (que.front()->right != NULL) {
                que.push(que.front()->right);
                count_new++;
            }
            que.pop();
            if (count_last == 0) {
                std::swap(count_last, count_new);
                new_vec = 1;
            }
        }
        return result;
    }
};
