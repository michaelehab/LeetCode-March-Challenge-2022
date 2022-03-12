/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map <Node*,Node*> m;
        Node* tmp = head;
        while(tmp){
            Node* temp = new Node(tmp->val);
            m[tmp] = temp;
            tmp = tmp->next;
        }
        
        tmp = head;
        while(tmp){
            m[tmp]->next = m[tmp->next];
            m[tmp]->random = m[tmp->random];
            tmp = tmp->next;
        }
    
        return m[head];
    }
};