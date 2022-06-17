ListNode* Solution::swapPairs(ListNode* head) {
    if(!head || !head->next){
        return head;
    }
    
    ListNode * curr = head;
    while(curr && curr->next){
        int temp = curr->val;
        curr->val = curr->next->val;
        curr->next->val = temp;
        curr=curr->next->next;
    }
    
    return head;
}