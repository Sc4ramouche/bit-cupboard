# notes on [Svelte](https://svelte.dev/)

## Introduction

### Dynamic attributes

Best demostrated by example:

```JavaScript
<script>
	let src = 'tutorial/image.gif';
    let name = 'Rick Astley'
</script>

<img src={src} alt="{name} dances.">
```

In this example `src` attribute calculated from `src` variable. Same goes for
`alt` attribute.

**Note:** there's shorthand for the case when attribute name and value are the
same, like in the example above: `src={src}`. This allows us to go for this:

```JavaScript
<img {src} alt="{name} dances.">
```

### HTML

You can interpret string as HTML in Svelte template. This is achvieved with
spectial `{@html ...}` tag:

```JavaScript
<script>
    let string = `this string contains some <strong>HTML!</strong>`;
</script>

<p>{@html string}</p>
```

## Reactivity

### Declarations

Svelte automatically updates the DOM when your component's state changes. Svelte
also introduces _reactive declarations_ - pieces of code which are being re-run
whenever any of the referenced values change.

```JavaScript
let count = 0;

$: doubled = count * 2
```

### Statements

There are also _reactive statements_:

```JavaScript
let count = 0

$: console.log(`the count is ${count}`);
```

In this example `console.log` will be executed whenever `count` value changes.

You can group statements and use them with other block, like `if` blocks:

```JavaScript
// group
$: {
    console.log(`the count is ${count}`);
    alert('Did you get it? It is ${count}')
}

// if block
$: if (count >= 10) {
    alert(`count is dangerously high!`);
    count = 9;
}
```

### Updating arrays and objects

Because Svelte's reactivity is triggered by assignments, using arrya methods
like `push` and `splice` won't automatically cause updates.

```JavaScript
let numbers = [1, 2, 3, 4];

function addNumber() {
    numbers.push(numbers.length + 1);
}

$: sum = numbers.reduce((t, n) => t + n, 0);    //  addNumber won't trigger the update
```

```JavaScript
function addNumber() {
    numbers = [...numbers, numbers.length + 1];    // now we're talking!
}
```
