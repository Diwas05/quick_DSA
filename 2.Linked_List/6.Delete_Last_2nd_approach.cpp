void deleteNode(int value){
    //Empty List
    if(length==0){
        return;
    }
    Node* temp = head;
    Node* pre = head;
    //List with single node
    if(length==1){
        head = NULL;
        tail = NULL;
    }else{
        while(temp->next){
            pre = temp;
            temp=temp->next;
        }
        tail = pre;
        tail->next = NULL;
    }
    delete temp;
    length--;
}