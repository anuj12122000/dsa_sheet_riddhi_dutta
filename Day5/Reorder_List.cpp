

private :

    ListNode * prev;

    void helper(ListNode * node){
        if(!node){
            return;
        }

        helper(node->next);

        ListNode * next = prev->next;
        prev->next = node;
        node->next=next;
        prev=next;

    }

public:
    void reorderList(ListNode* head) {
        if(!head){
            return ;
        }
        prev = head;
        helper(head);
    }