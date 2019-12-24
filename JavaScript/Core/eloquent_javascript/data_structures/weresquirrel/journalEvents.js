const journalEvents = journal =>
  journal.reduce((allEvents, entry) => {
    for (let event of entry.events) {
      !allEvents.includes(event) && allEvents.push(event);
    }
    return allEvents;
  }, []);

module.exports = journalEvents;
