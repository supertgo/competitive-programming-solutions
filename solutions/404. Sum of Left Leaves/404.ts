function sumOfLeftLeaves(root: TreeNode | null): number {
  return preorder(root)
};

function preorder(node: TreeNode, isLeft = false) {
  if(!node) return 0;
  if(!node.left && !node.right && isLeft) return node.val
  
  return preorder(node.left, true) + preorder(node.right)
}