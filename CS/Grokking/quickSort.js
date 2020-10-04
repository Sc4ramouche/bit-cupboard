function quickSort(elements) {
  if (elements.length < 2) return elements;

  if (elements.length === 2) {
    const [a, b] = elements;
    return [Math.min(a, b), Math.max(a, b)];
  }

  const pivot = elements[0];

  const same = [];
  const less = [];
  const more = [];

  elements.forEach((i) => {
    if (i < pivot) less.push(i);
    if (i > pivot) more.push(i);
    if (i === pivot) same.push(i);
  });

  return [...quickSort(less), ...same, ...quickSort(more)];
}

// console.log(quickSort([33, 15, 10, 2]));
// console.log(quickSort([3, 5, 2, 1, 4]));
console.log(quickSort([5, 1, 1, 2, 0, 0]));
