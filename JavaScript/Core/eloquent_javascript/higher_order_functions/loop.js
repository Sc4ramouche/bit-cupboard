function loop(v, test, update, body) {
  if (!test(v)) return;

  body(v);
  loop(update(v), test, update, body);
}

// `t`, `u`, and `v` are just placeholders, no special meaning
loop(
  0,
  t => t < 10,
  u => ++u,
  v => console.log(v)
);
