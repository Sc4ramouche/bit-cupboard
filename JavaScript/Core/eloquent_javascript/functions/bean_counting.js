// function that counts how many
// "B" characters contained with str
function countBs(str) {
  let count = 0;
  [...str].forEach(ch => ch == 'B' && count++);
  return count;
}
console.log('countBs: ', countBs('WWW B B S')); // -> 2

const countChar = (str, char) =>
  [...str].reduce(
    (result, current) => (current == char ? ++result : result),
    0
  );
console.log('countChar: ', countChar('WWW B B S', 'B')); // -> 2
console.log('countChar: ', countChar('WWW B B S', 'W')); // -> 3

const newCountBs = str => countChar(str, 'B');
console.log('newCountBs: ', newCountBs('WWW B B S')); // -> 2
