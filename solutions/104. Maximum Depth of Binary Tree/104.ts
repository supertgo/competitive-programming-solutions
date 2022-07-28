function maxDepth(root: TreeNode | null): number {
  if(!root) return null;
  
  let leftDepth = maxDepth(root.left);
  let rightDepth = maxDepth(root.right);
  
  return Math.max(leftDepth, rightDepth) + 1;
};