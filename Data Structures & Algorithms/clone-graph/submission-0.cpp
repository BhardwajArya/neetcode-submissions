/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;
        unordered_map<Node*, Node*>visited;
        visited[node]= new Node(node->val);
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            for(auto c : cur->neighbors){
                if(!visited.count(c)){
                    visited[c]= new Node(c->val);
                    q.push(c);
                }
                visited[cur]->neighbors.push_back(visited[c]);
                
            }

        }
        return visited[node];
        
    }
};
