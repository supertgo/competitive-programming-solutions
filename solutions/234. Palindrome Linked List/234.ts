class ListNode {
  val: number;
  next: ListNode | null;
  key: any;
}

function isPalindrome(head: ListNode | null): boolean {
  let fast = head, slow = head;
  
  while(slow && fast && fast.next) {
    slow = slow.next;
    fast = fast.next.next;
  }
  
  if(fast) {
    slow = slow.next;
  }
  
  slow = reverse(slow);
  fast = head;
  
  while (fast && slow) {
    if(fast.val !== slow.val) {
      return false;
    }
    
    slow = slow.next;
    fast = fast.next;
  }
  
  return true;
};

function reverse(head: ListNode): ListNode {
  let prev = null;
  
  while(head) {
    let temp = head.next;
    head.next = prev;
    prev = head;
    head = temp;
  }
  return prev;
}