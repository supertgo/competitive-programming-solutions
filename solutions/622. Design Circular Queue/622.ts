class QueueNode {
  val: number;
  next: QueueNode
  
  constructor(val, next = null) {
    this.val = val
    this.next = next
  }
}

class MyCircularQueue {
    size: number;
    maxSize: number;
    head: QueueNode;
    tail: QueueNode;
    
    constructor(k: number) {
      this.size = 0;
      this.maxSize = k;
      this.head = null;
      this.tail = null;
    }

    enQueue(value: number): boolean {
      if(this.isFull()) return false;
      const newNode = new QueueNode(value)
      
      if(this.isEmpty()) {
         this.head = newNode;
         this.tail = newNode;
      }
      else {
        this.tail.next = newNode;
      }
      this.tail = newNode;
      this.size++
      
      return true
    }

    deQueue(): boolean {
      if(this.isEmpty()) return false;
      
      this.head = this.head.next;
      this.size--;
      
      return true;
    }

    Front(): number {
      if(this.isEmpty()) return -1;
      
      return this.head.val;
    }

    Rear(): number {
      if(this.isEmpty()) return -1;
      
      return this.tail.val;
    }

    isEmpty(): boolean {
      return this.size === 0
    }

    isFull(): boolean {
      return this.size === this.maxSize;
    }
}