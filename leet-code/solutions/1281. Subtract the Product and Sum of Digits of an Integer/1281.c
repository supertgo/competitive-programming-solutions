

int subtractProductAndSum(int n){
  int product = 1;
  int sum = 0;
  
  while (n > 0) {
    int unit = n % 10;
    
    product *= unit;
    sum += unit;
    n = n / 10;
  }
  
  return product - sum;
}