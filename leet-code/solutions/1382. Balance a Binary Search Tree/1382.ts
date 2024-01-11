function balanceBST(root: TreeNode | null): TreeNode | null {
  if(!root) return null;
  
  const values = []
  inorder(root, values);
  
  return initBiTreeFromBST(0, values.length - 1, values)
  
};

function inorder(node: TreeNode, values) {
  if(!node) return null;
  
  if(node.left) inorder(node.left, values);
  values.push(node.val);
  if(node.right) inorder(node.right, values);
}

const initBiTreeFromBST = (start: number, end: number, values: number[]) => {
    if(start > end) return null;

    const mid = Math.floor((start + end) / 2);
    const node = new TreeNode(values[mid])
    node.left = initBiTreeFromBST(start, mid - 1, values);
    node.right = initBiTreeFromBST(mid + 1, end, values);
  
    return node;
}
