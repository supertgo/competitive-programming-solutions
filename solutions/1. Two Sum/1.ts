function twoSum(nums: number[], target: number): number[] {
  const map = new Map();
  
  for (let i = 0; i < nums.length; i++) {
    const number = nums[i];
    
    const diff = target - number;
    
    if(map.has(diff)) return [map.get(diff), i]
    
    map.set(number, i)
  }
};