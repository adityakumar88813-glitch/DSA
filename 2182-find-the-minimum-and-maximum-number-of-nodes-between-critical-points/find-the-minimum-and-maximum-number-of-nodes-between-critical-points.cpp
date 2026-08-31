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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
      
         vector<int> v;
        ListNode* curr = head;
        ListNode* forward = curr->next;
        int index = 1;

        //maxima
        while(forward->next != NULL){
            if(
    (forward->val > curr->val &&
     forward->val > forward->next->val)
    ||
    (forward->val < curr->val &&
     forward->val < forward->next->val)
){
                 v.push_back(index);
        }

        curr = forward;
        forward = forward->next;
        index++;
       
        }
        if(v.size() < 2)
         return {-1, -1};

         int mini = INT_MAX;
         for(int i = 1 ; i <v.size() ; i++){
            mini = min(mini,v[i]-v[i-1]);
         }
         int maxi = v.back() - v.front();
         return{mini,maxi};
    }
};