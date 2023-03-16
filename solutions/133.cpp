
#include <vector>
#include <unordered_map>
using namespace std;
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


class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> map;
        Node* dummy(0);
        dfs(node, dummy, map);
        return dummy->neighbors[0];
    }
private:
    
    void dfs(Node* node, Node* root, unordered_map<Node*, Node*>& map ){
        if(node == NULL || map.find(node) != map.end()){
            root->neighbors.push_back(map[node]);
            return;
        }
        Node* newNode = new Node(node->val);
        map[node] = newNode;

        root->neighbors.push_back(newNode);
        
        
        for(Node* neighbor: node->neighbors){
            dfs(neighbor, newNode, map);
        }
    }
};