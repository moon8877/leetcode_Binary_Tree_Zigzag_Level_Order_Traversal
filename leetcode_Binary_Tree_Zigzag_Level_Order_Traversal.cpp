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
        vector<vector<int>> answer;
        if(!root){
            return answer;
        }
        bfs(root,answer);
        return answer;
    }
private:
    vector<TreeNode*> reverse(vector<TreeNode*>& data){
        vector<TreeNode*> reverseData;
        for(int i=0;i<data.size();++i){
            reverseData.insert(reverseData.begin(),data[i]);
        }
        return reverseData;
    }
    
    void bfs(TreeNode* root,vector<vector<int>>& answer){
        vector<TreeNode*> curr;
        vector<TreeNode*> reverseCurr;
        vector<TreeNode*> next;
        int count=0;
        curr.push_back(root);
        while(curr.size()!=0){
            if(count%2!=0){
                reverseCurr = reverse(curr);
            }
            else{
                reverseCurr = curr;
            }
            answer.push_back({});
            for(int i=0;i<curr.size();++i){
                answer.back().push_back(reverseCurr[i]->val);
                if(curr[i]->left){next.push_back(curr[i]->left);}
                if(curr[i]->right){next.push_back(curr[i]->right);}
            }
            curr.swap(next);
            next.clear();
            count = count+1;
        }
        return;
    } 
};
