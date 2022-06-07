 Node* copyRandomList(Node* head) {
        Node * new_head = new Node(-1);
        Node * tail = new_head;
        unordered_map<Node*,Node*>mp;
        Node* temp = head;

        while(temp){
            Node* next = new Node(temp->val);
            mp[temp]=next;
            tail->next = next;
            tail = tail->next;
            temp = temp->next;
        }
    
        temp = head;
        Node * thead = new_head->next;
     
        while(temp){
            if(temp->random == NULL){
                thead->random=NULL;
            }else{
                thead->random = mp[temp->random];
            }
            temp = temp->next;
            thead=thead->next;
        }

    return new_head->next;
    }