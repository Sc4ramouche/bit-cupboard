const {
  arrayToList,
  arrayToListRecursive,
  arrayToListRecursiveArrow,
} = require('./arrayToList');
const { listToArray, listToArrayRecursive } = require('./listToArray');
const { prepend } = require('./prepend');
const { nth, nthRecursive } = require('./nth');

const list = {
  value: 1,
  rest: {
    value: 2,
    rest: {
      value: 3,
      rest: null,
    },
  },
};
const array = [1, 2, 3];

console.log('--- arrayToList ---');
console.log(arrayToList(array));
console.log(arrayToListRecursive(array));
console.log(arrayToListRecursiveArrow(array));

console.log('--- listToArray ---');
console.log('listToArray: ', listToArray(list));
console.log('listToArrayRecursive', listToArrayRecursive(list));

console.log('--- prepend ---');
console.log(prepend(0, list));

console.log('--- nth ---');
console.log(nth(list, 0)); // -> 1
console.log(nth(list, 1)); // -> 2
console.log(nth(list, 2)); // -> 3
console.log(nth(list, 3)); // -> undefined

console.log(nthRecursive(list, 0)); // -> 1
console.log(nthRecursive(list, 1)); // -> 2
console.log(nthRecursive(list, 2)); // -> 3
console.log(nthRecursive(list, 3)); // -> undefined
