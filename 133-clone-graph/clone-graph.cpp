
class Solution {
public:
    unordered_map<Node*,Node*>mp;
    void dfs(Node* node,Node* rootNode){
        for(auto n : node->neighbors){
            if(!mp.count(n)){
                Node* clone = new Node(n->val);
                mp[n]=clone;
                rootNode->neighbors.push_back(clone);
                dfs(n,clone);
            }
            else {
                rootNode->neighbors.push_back(mp[n]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr; 
        Node* rootNode = new Node(node->val);
        mp[node]=rootNode;
        dfs(node,rootNode);
        return rootNode;
    }
};