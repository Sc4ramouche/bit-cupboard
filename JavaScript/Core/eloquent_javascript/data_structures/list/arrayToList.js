function arrayToList(array) {
  let list = null;
  for (let i = array.length - 1; i >= 0; i--) {
    list = { value: array[i], rest: list };
  }
  return list;
}

// recursive
function arrayToListRecursive(array) {
  if (array.length == 0) {
    return null;
  } else {
    return { value: array[0], rest: arrayToListRecursive(array.slice(1)) };
  }
}

const arrayToListRecursiveArrow = array =>
  array.length == 0
    ? null
    : { value: array[0], rest: arrayToListRecursiveArrow(array.slice(1)) };

module.exports = {
  arrayToList,
  arrayToListRecursive,
  arrayToListRecursiveArrow,
};
