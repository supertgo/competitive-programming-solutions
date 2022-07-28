function smallerNumbersThanCurrent(nums: number[]): number[] {
  let array = new Array(nums.length);
  
  for (let i = 0; i < nums.length; i++) {
    let count = 0;
    for (let j = 0; j < nums.length; j++) {
      if(nums[i] > nums[j]) count++
    }
    array[i] = count;
  }
  
  return array;
};