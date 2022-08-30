function isValid(s: string): boolean {
  let chars = s.split('')
  
  if(s.length % 2) return  false;
  
  let stack: string[] = []
  
  for(let char of chars) {
    if(char === '(')
      stack.push(')')
    else if(char === '{')
      stack.push('}')
    else if(char === '[')
      stack.push(']')
    else if (stack.length === 0 || stack.pop() !== char)
        return false;
  }
         
  return !stack.length;
};