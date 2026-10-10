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
int length(ListNode* head){
    ListNode* temp = head;
    int cnt = 0;
    while(temp != NULL){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      int len = length(head);
      int pos = len-n;

      if(pos == 0){
        ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
      }
          
           ListNode* temp = head;
           while(pos > 1){
            temp  = temp->next;
            pos--;
           }

     ListNode* delNode = temp->next;
    temp->next = delNode->next;
    delete(delNode);
    return head;
    }
};