/*
    This is representation of correlation function
    implemented in JavaScript.

    For detailed review of the underlying concept
    refer to "Computing Correlation" section
    of "Data Structures: Objects and Arrays" chapter.
    https://eloquentjavascript.net/04_data.html
*/
function phi(table) {
  return (
    (table[3] * table[0] - table[2] * table[1]) /
    Math.sqrt(
      (table[2] + table[3]) *
        (table[0] + table[1]) *
        (table[1] + table[3]) *
        (table[0] + table[2])
    )
  );
}

module.exports = phi;
