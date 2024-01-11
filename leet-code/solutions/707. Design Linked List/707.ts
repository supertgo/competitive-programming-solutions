class Node {
  val: number
  next: Node
  
  constructor(val: number, next = null) {
    this.val = val;
    this.next = next
  }
}
class MyLinkedList {
    private head: Node
    private tail: Node
    private size: number
    
    constructor() {
      this.head = this.tail = null;
      this.size = 0;
    }

    getNode(idx: number): Node {
      if (idx < 0 || idx >= this.size) return null;
      let cur = this.head;
      let curIdx = 0;
      while (curIdx !== idx) {
        cur = cur.next;
        curIdx++;
      }
      return cur;
    }

    get(index: number): number {
      let node = this.getNode(index);
      return node ? node.val : -1;
    }

    addAtHead(val: number): void {
      const newNode = new Node(val);
      
      if(this.size === 0) this.tail = newNode;

      newNode.next = this.head;
      this.head = newNode;
      
      this.size++;
    }

    addAtTail(val: number): void {
      const node = new Node(val);
      if (!this.size) this.head = node;
      else this.tail.next = node;
      this.tail = node;

      this.size++;
    }

    addAtIndex(index: number, val: number): void {
      if(index > this.size) return;
      
      if(index === 0) return this.addAtHead(val)
      if(index === this.size) return this.addAtTail(val)
      const newNode = new Node(val);
      const pre = this.getNode(index - 1);
      newNode.next = pre.next;
      pre.next = newNode;

      this.size++;
    }

    deleteAtIndex(index: number): void {
      if (index < 0 || index >= this.size) return;
      if(index === 0) {
        this.head = this.head.next
      } else {
        const pre = this.getNode(index - 1);
        pre.next = pre.next.next;
        if (!pre.next) this.tail = pre;
      }
    
      this.size--;
    }
}
