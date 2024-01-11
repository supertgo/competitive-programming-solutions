function hasCycle(head: ListNode | null): boolean {
  let fast = head
  let slow = head
  
  while(slow && fast) {
    if(slow.next == null)
      return false
    if(fast.next == null)
      return false
    
    fast = fast.next.next;

    if(slow === fast)
      return true
    
    slow = slow.next;
  }

return false
};