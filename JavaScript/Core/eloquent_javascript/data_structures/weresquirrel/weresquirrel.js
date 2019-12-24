const journal = require('./journal');
const phi = require('./phi');
const tableFor = require('./tableFor');
const journalEvents = require('./journalEvents');

/*
    phi function consumes so called "table" to calculate correlation.
    We'd need to create those tables from the journal, and for
    that reason we need something like 'tableFor' util.
*/

// create new event, which combines days
// when there were peanunts and no teeth brushing
// has taken place
for (let entry of journal) {
  if (
    entry.events.includes('peanuts') &&
    !entry.events.includes('brushed teeth')
  ) {
    entry.events.push('peanut teeth');
  }
}

for (let event of journalEvents(journal)) {
  let correlation = phi(tableFor(event, journal));
  if (Math.abs(correlation) > 0.1)
    console.log(`Event: ${event}, correlation: ${correlation}`);
}
