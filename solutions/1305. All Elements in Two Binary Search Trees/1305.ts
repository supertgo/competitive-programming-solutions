function getAllElements(root1: TreeNode | null, root2: TreeNode | null): number[] {
  let values = []
  
  preorder(root1, values)
  preorder(root2, values);
  
  return values.sort((a,b) => a-b)
};

function preorder(node: TreeNode, values: number[]) {
  if(node) {
    values.push(node.val)
    if(node.left) preorder(node.left, values);
    if(node.right) preorder(node.right, values);
  }  
}