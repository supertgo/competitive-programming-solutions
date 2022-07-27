function pairSum(head: ListNode | null): number {
  let slow = head, fast = head;

  while(slow && fast && fast.next) {
    fast = fast.next.next;
    slow = slow.next;
  }
  
  slow = reversed(slow)
  let max = 0;
  
  
  while(slow) {
    max = Math.max(max, slow.val + head.val);
    slow = slow.next;
    head = head.next
  }
  
  return max;
};

function reversed(head: ListNode): ListNode {
  let prev = null;
  
  while(head) {
    let temp = head.next;
    head.next = prev;
    prev = head;
    head = temp;
  }
  
  return prev;
}
