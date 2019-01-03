# Interfaces

Type-checking relies on so called "duck typing" or "structural subtyping". In TypeScript interfaces fill the role of naming these types, thus defining contracts withing the code. Example:

```TS
interface LabelledValue {
    label: string;
}

function printLabel(labelledObj: LabelledValue) {
    console.log(labelledObj.label);
}

let myObj = {size: 10, label: 'Size 10 object'};
printLabel(myObj);
```

Notice that here we pass object that has more properties than described in the interface. The compiler checks that at least the ones required are present and match the declared types. Order doesn't matter as well, only object shape matters.

## optional properties

Optional properties give you advantage of describing possible properties while still also preventing use of properties that are not the part of the interface:

```TS
interface Square {
    width?: number;
    color?: string;
}
```

## readonly properties

Sometimes there are properties that should only be modifiable when an object is first created. You can specify such properties with TypeScript:

```TS
interface Point {
    readonly x: number;
    readonly y: number;
}
```

Trying to manually change `x` or `y` would cause an Error to occur.

TypeScript comes with `ReadonlyArray<T>` type that is the same as `Array<T>` with all mutating methods removed, ensuring you are not implicitly change your array after creation.

```TS
let a: number[] = [1, 2, 3, 4];
let ro: ReadonlyArray<number> = a;
ro[0] = 12;    // error!
ro.push(5);    // error!
ro.length = 100;    // error!
a = ro;    // error!
```

On the last line you can see that assigning entire `ReadonlyArray` back to normal array is illegal. You can still override it with type assumption, though:

```TS
a = ro as number[];
```

## excess property checks

Object literals get special treatment in TypeScript and undergo excess property checking when assigning them to other variables, or passing them as arguments. If an object literal has any properties that "target type" doesn't have, you'll get an error:

```TS
interface Square {
    width?: number;
    color?: string;
}

function createSquare(config: Square): { color: string; area: number } {
    // ...
}

// error: 'colour' not expected in type 'Square'
let mySquare = createSquare({ colour: 'red', width: 100 });
```

You can get around this with type assertion:

```TS
let mySquare = createSquare({ colour: 'red', width: 100 } as Square);
```

However, a better approach would be to add a string index signature if you're sure that the object can have some extra properties. We could define it like so:

```TS
interface Square {
    width?: number;
    color?: string;
    [propName: string]: any;
}
```

The meaning behind above example is that `Square` can have any number of properties, and as long as they aren't `width` or `color` their type doesn't matter.

One last workaround with excess property check is to assign the object to another variable. In this case compiler won't give the error as it won't undergo excess check.