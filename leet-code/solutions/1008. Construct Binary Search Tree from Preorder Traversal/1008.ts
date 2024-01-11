function bstFromPreorder(preorder: number[]): TreeNode | null {
  if(preorder.length < 0) return null;
  
  const root = new TreeNode(preorder[0])
  
  for(let i = 1; i < preorder.length; i++) {
    addNode(root, preorder[i])
  }
  
  return root;
};

function addNode(root: TreeNode, value: number) {
    if(value > root.val) {
      if(root.right) return addNode(root.right, value);
      root.right = new TreeNode(value);
    } else {
      if(root.left) return addNode(root.left, value);
      root.left = new TreeNode(value)
    }
}