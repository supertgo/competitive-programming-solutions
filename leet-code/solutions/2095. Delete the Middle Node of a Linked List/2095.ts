function deleteMiddle(head: ListNode | null): ListNode | null {
  if(!head) return head;
  
  const size = getSize(head);
  if(size === 1) return null;
  const middle = Math.floor(size / 2)
  
  let result = head;
  let cur = head;
  
  
  
  for(let i = 0; i < middle - 1; i++) {
    cur = cur.next;
  }
  
  cur.next = cur.next.next;
  
  return result;
};

function getSize(head: ListNode): number {
  let size = 0;
  
  while(head) {
    size++
    head = head.next;
  }
  
  return size
}