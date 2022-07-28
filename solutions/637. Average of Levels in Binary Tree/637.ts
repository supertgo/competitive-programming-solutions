function averageOfLevels(root: TreeNode | null): number[] {
  let result = []
  if(!root) return result;
  let queue = [root];
  
  while(queue.length) {
    let sum = 0;
    let size = queue.length;
    
    for (let i = 0; i < size; i++) {
      const node = queue.shift();
      
      sum += node.val;
      
      if(node.left) queue.push(node.left)
      if(node.right) queue.push(node.right)
    }
    
    result.push((sum)/size);
  }
  
  return result;
};