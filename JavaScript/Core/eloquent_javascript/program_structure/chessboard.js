let s = '';

const size = 7;

let base = new Array(Math.floor(size / 2));
base = base.fill('#').join(' ');

for (let i = 0; i < size; i++) {
  s += i % 2 == 0 ? ' ' + base : base + ' ';
  s += '\n';
}

console.log(s);
