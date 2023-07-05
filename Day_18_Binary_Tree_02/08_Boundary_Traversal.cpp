#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int> *root) { return !root->left and !root->right; }



void goLeft(TreeNode<int> *root, vector<int> &ans) {
  TreeNode<int> *node = root->left;

  while (node) {
    // puting into vector
    if (!isLeaf(node)) {
      ans.push_back(node->data);
    }

    // then move left or right
    if (node->left) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
}

void goLeaf(TreeNode<int> *root, vector<int> &ans) {
  // inorder travesal

  if(root->left){
      goLeaf(root->left, ans);
  }

  if (isLeaf(root)) {
    ans.push_back(root->data);
    // return;
  }

  if(root->right){
      goLeaf(root->right, ans);
  }
  
}

void goRight(TreeNode<int> *root, vector<int> &ans) {
  vector<int> temp;
  TreeNode<int> *node = root->right;

  // putting into temp vector
  while (node) {

    if (!isLeaf(node)) {
      temp.push_back(node->data);
    }

    // then move right or left
    if (node->right) {
      node = node->right;
    } else {
      node = node->left;
    }
  }

  for(int i = temp.size()-1; i >= 0; i-- ){
      ans.push_back(temp[i]);
  }
}

vector<int> traverseBoundary(TreeNode<int> *root) {
  // Write your code here.
  vector<int> ans;

  if (!root) {
    return ans;
  }

  if (!isLeaf(root)) {
    ans.push_back(root->data);
    // return ans;
  }

  // otherwise
  goLeft(root, ans);
  goLeaf(root, ans);
  goRight(root, ans);

  return ans;
}