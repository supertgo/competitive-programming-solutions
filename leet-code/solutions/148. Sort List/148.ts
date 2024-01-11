function sortList(head: ListNode | null): ListNode | null {
  let result = []
  if(head === null) return head;
  while(head) {
    result.push(head.val);
    head = head.next;
  }
  
  result.sort((a,b)=>a-b);
  
  let node = null;
  let res = null;
  for(let i = 0; i < result.length; i++) {
    if(!node) {
      node = new ListNode(result[i]);
      res = node;
      continue;
    }
    node.next = new ListNode(result[i]);
    node = node.next;
  }
  
  return res;
};