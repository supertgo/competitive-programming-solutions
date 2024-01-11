function isUnivalTree(root: TreeNode | null): boolean {
  if(!root) return true;
  
  return preorder(root, root.val);
};

function preorder(node: TreeNode, unival: number) {
  if(!node) return true;
  if(node.val !== unival) return false;
  
  return preorder(node.left, unival) && preorder(node.right, unival);
}