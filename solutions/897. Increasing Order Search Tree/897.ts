function increasingBST(root: TreeNode | null): TreeNode | null {
  if(!root) return null;
  let values = [];
  
  inorder(root, values)
  return createBst(values)
};

function inorder(node: TreeNode, values: number[]) {
  if(node.left) inorder(node.left, values)
  values.push(node.val)
  if(node.right) inorder(node.right, values)
}

function createBst(values: number[]) {
  let node = new TreeNode(values[0]);
  let root = node;
  
  for(let i = 1; i < values.length; i++) {
    node.right = new TreeNode(values[i])
    node = node.right;
  }
  
  return root;
}