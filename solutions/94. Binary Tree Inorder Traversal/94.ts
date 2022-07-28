function inorderTraversal(root: TreeNode | null): number[] {
  let result = []
  if(!root) return result;
  
  pack(root, result)

  return result
};

function pack(node: TreeNode, result: number[]) {
  if(node.left) pack(node.left, result)
  result.push(node.val)
  if(node.right) pack(node.right, result)

}
