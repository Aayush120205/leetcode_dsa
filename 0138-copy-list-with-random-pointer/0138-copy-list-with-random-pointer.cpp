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
        if (head == NULL) return NULL;

        // Step 1: Insert copied nodes in between original nodes
        Node* temp = head;

        while (temp != NULL) {
            Node* copyNode = new Node(temp->val);

            copyNode->next = temp->next;
            temp->next = copyNode;

            temp = temp->next->next;
        }

        // Step 2: Connect random pointers
        temp = head;

        while (temp != NULL) {
            Node* copyNode = temp->next;

            if (temp->random != NULL) {
                copyNode->random = temp->random->next;
            }

            temp = temp->next->next;
        }

        // Step 3: Separate original and copied lists
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;

        temp = head;

        while (temp != NULL) {
            res->next = temp->next;
            res = res->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }

        return dummyNode->next;
    }
};