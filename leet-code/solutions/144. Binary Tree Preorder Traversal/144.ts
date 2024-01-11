function preorderTraversal(root: TreeNode | null): number[] {
  let result = [];
  if(root) {
    pack(root, result)
  }
  
  return result
};

function pack(root: TreeNode, result: number[]) {
  result.push(root.val);
  
  if(root.left) pack(root.left, result)
  if(root.right) pack(root.right, result)
    
  return result;
}