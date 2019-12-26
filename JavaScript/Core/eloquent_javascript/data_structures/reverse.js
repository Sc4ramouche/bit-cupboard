const { range } = require('./range');

console.log('--- reverse module ---');

// produces new array
const reverseArrayArrow = array =>
  array.reduceRight((acc, item) => {
    acc.push(item);
    return acc;
  }, []);

function reverseArray(array) {
  const result = [];
  for (let i = array.length - 1; i >= 0; i--) result.push(array[i]);
  return result;
}

// modifies given array
function reverseArrayInPlace(array) {
  for (let i = 0; i < Math.floor(array.length / 2); i++) {
    const { length } = array;
    const tmp = array[i];
    array[i] = array[length - i - 1];
    array[length - i - 1] = tmp;
  }

  return array;
}

console.log(reverseArray([1, 2, 3, 4, 5]));
console.log(reverseArrayArrow([1, 2, 3, 4, 5]));
console.log(reverseArrayInPlace([1, 2, 3, 4, 5]));

console.log('--- performance test ---');
// create array in advance so it doesn't impact test itslef
console.time('range creation');
const arr = range(0, 3000);
console.timeEnd('range creation');

console.log('--- reverseArray ---');

console.time('reverseArray');
reverseArray(arr);
console.timeEnd('reverseArray');

console.log('--- reverseArrayArrow ---');

console.time('reverseArrayArrow');
reverseArrayArrow(arr);
console.timeEnd('reverseArrayArrow');

console.log('--- reverseArrayInPlace ---');

console.time('reverseArrayInPlace');
reverseArrayInPlace(arr);
console.timeEnd('reverseArrayInPlace');

// turns out 'reduce' version is 2x slower in this test. Interesting!
