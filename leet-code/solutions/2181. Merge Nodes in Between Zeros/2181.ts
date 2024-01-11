function mergeNodes(head: ListNode | null): ListNode | null {
  if (head === null) {return null}
  let result = head;
  
  while(result?.next) {
    result.val += result.next.val;
    result.next = result.next.next;
    
    if(!result?.next?.next) {
      result.next = null;
    }
    
    if(!result?.next?.val){
      result = result.next;
    }
  }
  
  return head;
};