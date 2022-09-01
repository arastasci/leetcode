
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
#include <unordered_map>
using namespace std;

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> map = {{nullptr,nullptr}};
       Node *node = head; 
       while(node){
            Node* newPointer = new Node(node->val);
            map[node] = newPointer;
            node = node->next;
       }
       node = head;
       while(node){
            map[node]->next = map[node->next];
            map[node]->random = map[node->random];
            node = node->next;
       }
       return map[head];
    }
};