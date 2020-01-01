// work in progress

// function deepEqual(a, b) {
//   if (typeof a != typeof b) {
//     return false;
//   } else if (a === b) {
//     return true;
//   } else if (typeof a === 'object') {
//     const propertiesA = Object.keys(a);
//     const propertiesB = Object.keys(b);

//     if (propertiesA.length != propertiesB.length) return false;
//     for (let prop of propertiesA) {
//       console.log('prop:', prop);
//       if (!propertiesB.includes(prop)) {
//         return false;
//       } else {
//         deepEqual(propertiesA[prop], propertiesB[prop]);
//       }
//     }
//   }
// }

const a = {
  value: 1,
  rest: {
    value: 2,
    rest: {
      value: 3,
      rest: null,
    },
  },
};
const b = {
  value: 1,
  rest: {
    value: 2,
    rest: {
      value: 3,
      rest: null,
    },
  },
};

console.log(deepEqual(a, b));
