function runningSum(nums: number[]): number[] {
  let temp = 0;
  return nums.map(num => 
    temp =+ temp + num
  )
};