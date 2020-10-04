function binarySearch(elements, target) {
  let left = 0;
  let right = elements.length - 1;

  while (left <= right) {
    const middle = Math.floor((left + right) / 2);
    const guess = elements[middle];

    if (guess === target) return middle;

    if (guess < target) right = middle - 1;
    if (guess > target) left = middle + 1;
  }

  return null;
}

console.log(binarySearch([5, 6, 7, 8, 9, 10], 7));
