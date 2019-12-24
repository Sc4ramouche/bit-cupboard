function tableFor(event, journal) {
  const results = [0, 0, 0, 0];

  for (entry of journal) {
    if (entry.events.includes(event)) {
      entry.squirrel ? results[3]++ : results[1]++;
    } else {
      entry.squirrel ? results[2]++ : results[0]++;
    }
  }

  return results;
}

// book solution (smart as usual)
function authorTableFor(event, journal) {
  let table = [0, 0, 0, 0];
  for (let i = 0; i < journal.length; i++) {
    let entry = journal[i],
      index = 0;
    if (entry.events.includes(event)) index += 1;
    if (entry.squirrel) index += 2;
    table[index] += 1;
  }
  return table;
}

module.exports = tableFor;
