function kidsWithCandies(candies: number[], extraCandies: number): boolean[] {
  let result: boolean[] = []
  let greater = candies[0];
  
  for (let i = 0; i < candies.length; i++) {
    greater = Math.max(greater, candies[i])
  }
  
  
  for (let i = 0; i < candies.length;  i++) {
    if(candies[i] + extraCandies >= greater) {
      result.push(true)
    } else {
      result.push(false)
    }
  }
  
  
  return result
};