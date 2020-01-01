function every(xs, predicate) {
  for (let x of xs) {
    result = predicate(x);
    if (!result) return false;
  }
  return true;
}

const input = [1, 2, 3, 4, 5, 6];
console.log(every(input, x => x > 3));
console.log(every(input, x => x > 0));

const everySome = (xs, predicate) => !xs.some(x => !predicate(x));

console.log(everySome(input, x => x > 3));
console.log(everySome(input, x => x > 0));
