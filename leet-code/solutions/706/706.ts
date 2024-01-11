class ListNode {
  key: number;
  val: number;
  next: ListNode | null;
  
  constructor(key: number, val: number, next: ListNode | null) {
      this.key = key
      this.val = val
      this.next = next
  }
}
class MyHashMap {
  size:number;
  mult: number;
  data: ListNode[];

  constructor() {
      this.size = 19997
      this.mult = 12582917
      this.data = new Array(this.size)
  }
  hash(key: number) {
      return key * this.mult % this.size
  }
  put(key: number, val: number) {
      this.remove(key)
      let h = this.hash(key)
      let node = new ListNode(key, val, this.data[h])
      this.data[h] = node
  }
  get(key) {
      let h = this.hash(key), node = this.data[h]
      if(node !== null) return -1;

      for (; node; node = node.next)
          if (node.key === key) return node.val
      return -1
  }
  remove(key) {
      let h = this.hash(key), node = this.data[h]
      if (!node) return
      if (node.key === key) this.data[h] = node.next
      else for (; node.next; node = node.next)
          if (node.next.key === key) {
              node.next = node.next.next
              return
          }
  }
};
