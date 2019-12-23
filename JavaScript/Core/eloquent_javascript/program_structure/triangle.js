for (let i = 0, tower = '#'; i < 7; i++) {
  console.log(tower);
  tower += '#';
}

// author's solution (really smart one)
for (let line = '#'; line.length < 8; line += '#') {
  console.log(line);
}
