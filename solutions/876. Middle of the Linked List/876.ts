function middleNode(head: ListNode | null): ListNode | null {
  if(!head.next) return head;
    let current = head;
    let length = 0;
    while(current){
        length++;
        current = current.next;
    }
    
    current = head;
    for(let i = 0 ; i < Math.floor(length/2) ; i++){
        current = current.next; 
    }
    
    return current
};