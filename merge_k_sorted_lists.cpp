ListNode *mergesorted(ListNode*h1, ListNode *h2){
    
    ListNode * dummy = new ListNode(-1);
    ListNode *tail = dummy;
    if(!h1){
        return h2;
    }

    if(!h2){
        return h1;
    }

    while(h1 && h2){

        if(h1->val<h2->val){
            tail->next = h1;
            tail = tail->next;
            h1=h1->next;
        }else{
            tail->next = h2;
            tail = tail->next;
            h2= h2->next;
        }

            if(h1){
                tail->next=h1;
            }else{
                tail->next = h2;
            }


    }
    return dummy->next;
}

ListNode* mergeK(vector<ListNode*>&lists,int k){

    while(k!=0){
        int i=0,j=k;
        while(i<j){

            lists[i]=mergesorted(lists[i],lists[j]);
            i++;
            j--;
            if(i>=j){
                k=j;
            }
        }
    }

    return lists[0];
}

 ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==1)
            return lists[0];
        if(lists.size()==0) 
            return NULL;
        ListNode*newhead = mergeK(lists,lists.size()-1);
        return newhead;
    }