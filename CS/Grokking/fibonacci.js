function fibonacci(n) {
  if (n < 2) return n;

  return fibonacci(n - 1) + fibonacci(n - 2);
}

for (let i = 0; i < 15; i++) {
  console.log(`${i}: ${fibonacci(i)}`);
}
