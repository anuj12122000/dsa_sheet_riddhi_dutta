 ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * h1= list1;
        ListNode *h2 = list2;
        ListNode *head = new ListNode();
        ListNode * tail = head;
        
        while(h1 && h2){
            
            if(h1->val<h2->val){
                tail->next=h1;
                tail= tail->next;
                h1=h1->next;
            }else{
                tail->next=h2;
                tail=tail->next;
                h2=h2->next;
            }
        }
        
        if(h1){
            tail->next=h1;
        }else{
            tail->next=h2;
            }
        
        
        return head->next;
    }