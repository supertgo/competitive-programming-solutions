function getDecimalValue(head: ListNode | null): number {
  let values: String[] = []
  let current = head; 
  
  while(current !== null) {
    values.push(`${current.val}`)
    current = current.next;
  }
  
  
  return parseInt(values.join(''),2)
};