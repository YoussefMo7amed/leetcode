// Definition for a Node.
class Node {
   public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
   public:
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(Node *root) {
        if (root) {
            ans.push_back({root->val});  // adding first level of nodes
            traverse(root, 1);
        }
        return ans;
    }
    void traverse(Node *root, int level) {
        vector<int> children;  //  children of previous node.
        if(root->children.empty()) return;
        // the answer size should equal number of levels.
        if (ans.size() <= level) {
            ans.push_back({});  // just adding an empty vector. Remember vector is 0-based.
        }
        // adding the children together
        for (auto node : root->children) {
            if(!node) continue;
            children.push_back(node->val);
            traverse(node, level + 1);
        }
        // may be there are nodes added before these, so i just concatenate
        // them.
        ans[level].insert(ans[level].end(), children.begin(), children.end());
    }
};
