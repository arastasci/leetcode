
#include <iostream>
#include <queue>
using namespace std;

//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        queue<ListNode*> nodes;
        ListNode dummy(0,head);
        ListNode *node = & dummy;
        while(node){
            nodes.push(node);
            node = node->next;
            if(nodes.size()>n+1){
                nodes.pop();
            }
        }
        nodes.front()->next = nodes.front()->next->next;
        return dummy.next;
    }
};