class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
      if(!head || !head->next){
          if(!head){
              return head;
          }
          delete head;
          return NULL;
      }
        
        ListNode* slow = head;
        ListNode * fast  = head;
        ListNode * prev = head;
        
        while(fast && fast->next){
            if(slow!=head){
                prev = prev->next;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
    
        prev->next = slow->next;
        delete slow;
        return head ;
    }
};