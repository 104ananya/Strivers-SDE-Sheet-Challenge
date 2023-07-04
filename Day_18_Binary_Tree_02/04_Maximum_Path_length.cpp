#include <bits/stdc++.h>
/************************************************************

    Following is the Tree node structure

        template <typename T>
    class TreeNode
    {
        public :
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int solve(TreeNode<int> *root, int &path) {
  if (root == NULL) {
    return 0;
  }

  int left = (solve(root->left, path));
  int right = (solve(root->right, path));

  int val = root->val;

  path = max(path, left + right + val);

  return val + max(left, right);
}

long long int findMaxSumPath(TreeNode<int> *root) {
  // Write your code here.
  int path = -1;

  if (! root || root->left == NULL || root->right == NULL) {
    return -1;
  }

  solve(root, path);
  return path;
}