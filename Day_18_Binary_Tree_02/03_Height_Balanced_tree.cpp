#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int dfs(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }

    int left = dfs(root->left);
    if(left == -1){
        return -1;
    }
    int right = dfs(root->right);
    if(right == -1){
        return -1;
    }


    if(abs(left - right) > 1){
        return -1;
    }

    return 1 + max(left, right);
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.

    if(dfs(root) == -1){
        return false;
    }
    else{
        return true;
    }   
}