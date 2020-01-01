function nth(list, position) {
  for (let i = 0; i <= position; i++) {
    if (list == undefined) {
      return undefined;
    } else if (position == i) {
      return list.value;
    } else {
      list = list.rest;
    }
  }
}

function nthRecursive(list, position) {
  if (!list) {
    return undefined;
  } else if (position == 0) {
    return list.value;
  } else {
    return nthRecursive(list.rest, position - 1);
  }
}

module.exports = {
  nth,
  nthRecursive,
};
