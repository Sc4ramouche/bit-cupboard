# Basic Types

## Boolean

```JavaScript
let isDone: boolean = true;
```

## Number

All in floats, includes _binary_ and _octal_ literals.

```JavaScript
let decimal: number = 6;
let hex: number = 0xf00d;
let binary: number = 0b1010;
let octal: number = 0o744;
```

## String

Includes template literals.

```JavaScript
let color: string = 'blue';
let sentence: string = `Is this ${color} butterfly?`;
```

## Array

Two ways to declare:

```JavaScript
let list: number[] = [1, 2, 3];
let newList: Array<number> = [1, 2, 3];
```

## Tuple

Array where the ype of a fixed number of elements is known.

```JavaScript
let x: [string, number];
x = ['hello', 10];  // OK
x = [10, 'hello'];  // Error: order matters
```

Accessing an element outside the set of known indices use union type. For above example it would be `string | number`:

```JavaScript
x[2] = 'world';  // string can be assigned to 'string | number'
```

## Enum

A way of giving more friendly names to sets of numberic values.

```JavaScript
enum Color {Red, Green, Blue}  // 0, 1, 2
let c: Color = Color.Green;  // c === 1
```

By default `enum` starts numbering it's value from `0`, but we can change this behaviour manually:

```JavaScript
enum Color {Red = 1, Green = 2, Blue = 4}
```

## Any

A way to describe type of variables that we don't know at the moment of writing (i.e. third party or user).

## Void

Opposite of `any` - absence of type at all. Usually used as return type of functions that don't return value. You can only assign `undefined` or `null` to the variables of type `void`.

## Never

Represents type of values that never occur, i.e. functions that do not reach the `return` statement at all. Example:

```JavaScript
function(message: string): never {
    throw new Error(message);
}
```

## Object

`object` is a type that represents the non-primitive type, i.e. any thing that is not `number`, `string`, `boolean`, `symbol`, `null`, or `undefined`.

## Type assertions

Type assertions are a way to tell the compiler "trust me, I know what I'm doing". Comes in two forms:

```JavaScript
let someValue: any = 'example';

// angle brackets syntax:
let strLength: number = (<string>someValue).length;

// 'as' syntax
let strLength: number = (someValue as string).length;
```
