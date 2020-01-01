function listToArray(list) {
  let array = [];

  while (list) {
    array.push(list.value);
    list = list.rest;
  }

  return array;
}

function listToArrayRecursive(list) {
  if (!list.rest) {
    return [list.value];
  } else {
    return [list.value, ...listToArrayRecursive(list.rest)];
  }
}

module.exports = {
  listToArray,
  listToArrayRecursive,
};
