int fib(int n) {
  // base case
  if(n == 0 || n == 1) return n;
  
  // recursive relation
  return fib(n-1) + fib(n-2);
}
