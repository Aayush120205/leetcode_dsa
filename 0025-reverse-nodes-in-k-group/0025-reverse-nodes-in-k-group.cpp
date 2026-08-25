/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* findKthNode(ListNode* temp, int k) {
        k -= 1;

        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }

        return temp;
    }

    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while (temp != NULL) {

            // Find kth node
            ListNode* kThNode = findKthNode(temp, k);

            // If less than k nodes are left
            if (kThNode == NULL) {
                if (prevLast != NULL) {
                    prevLast->next = temp;
                }
                break;
            }

            // Store the next node
            ListNode* nextNode = kThNode->next;

            // Disconnect the k-group
            kThNode->next = NULL;

            // Reverse the k-group
            reverseLinkedList(temp);

            // First group
            if (temp == head) {
                head = kThNode;
            }
            else {
                prevLast->next = kThNode;
            }

            // temp is now the last node of reversed group
            prevLast = temp;

            // Move to next group
            temp = nextNode;
        }

        return head;
    }
};