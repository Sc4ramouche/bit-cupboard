function sum(elements) {
  if (elements.length === 0) return 0;

  return elements[0] + sum(elements.slice(1));
}

function len(elements) {
  if (elements.length === 0) return 0;

  return 1 + len(elements.slice(1));
}

function maximum(elements) {
  if (elements.length === 2) return Math.max(elements[0], elements[1]);

  return Math.max(elements[0], maximum(elements.slice(1)));
}

console.log(sum([2, 4, 6]));
console.log(len([2, 4, 6]));
console.log(maximum([24, 12, 6]));
