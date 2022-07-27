function deleteDuplicates(head: ListNode | null): ListNode | null {
  if(!head) return null;
  
  const temp = head;
  while(head && head.next) {
    if(head.val === head.next.val) {
      while(head.next && head.next.val === head.val){
        head.next = head.next.next;
      }
    }
    head = head.next;
  } 
  
  return temp;
};