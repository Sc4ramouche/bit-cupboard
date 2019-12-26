function range(start, end, step = 1) {
  const result = [];

  for (let i = start; step < 0 ? i >= end : i <= end; i += step) {
    result.push(i);
  }

  return result;
}

const sum = range => range.reduce((acc, item) => acc + item, 0);

console.log(sum(range(1, 10)));
console.log(range(1, 10, 2));
console.log(range(5, 2, -1));

module.exports = {
  range: range,
};
