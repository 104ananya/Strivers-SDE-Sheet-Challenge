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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool flag = true;   //for left to right

        while(!q.empty()){
            int size = q.size();

            vector<int> row(size);

            for(int i = 0; i < size; i++){
                
                // take out the first node
                TreeNode* top = q.front();
                q.pop();

                // work of flag
                
                if(flag){
                    // int index = i;
                    row[i] = top->val;
                }
                else{
                    row[size-1-i] = top->val;
                }       

                // if left right exist push into queue
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }

            if(flag){
                flag = false;
            }
            else{
                flag = true;
            }

            ans.push_back(row);
            
        }

        return ans;
    }
};