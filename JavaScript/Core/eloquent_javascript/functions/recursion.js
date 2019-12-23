// 0 is even
// 1 is odd
// define recursive function for figuring
// if the given number even or odd
function isEven(n) {
  if (n == 1 || n == 0) return !Boolean(n);
  else if (n < 0) return isEven(-n);
  else return isEven(n - 2);
}

console.log(isEven(50));
console.log(isEven(75));
console.log(isEven(-2));
