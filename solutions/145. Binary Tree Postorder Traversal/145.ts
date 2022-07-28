function postorderTraversal(root: TreeNode | null): number[] {
  let result = []
  if(!root) return result;
  
  postorder(root, result)
  
  return result;
};

function postorder(node: TreeNode, result: number[]) {
  if(node.left) postorder(node.left, result);
  if(node.right) postorder(node.right, result);
  
  result.push(node.val)
}