# Preface

## Values and Expressions

In JavaScript all values are expressions. When you mention `42` (in browser console, for example), it's both value and statement. As a statament it returns it's value. Conceptually, that's how we are adding strings in JS, for example: `'hello' + ' ' + 'world'`.

Anonymous function is a literal for the function type. Just like `42` is a literal of a `Number`.

Computer's internal representation for binary numbers are binary. But as we use decimal notation, not every decimal number has binary representation:

```JS
0.3 + 0.3 + 0.3 = 0.30000000000000004;
```

This could be a minor thing when we are positioning elements on web page, as usually one pixel deviation is fine. But if we are working with monetary amounts it is recommended to use two separate values, so "\$42.24" would be processed as `42` for dollars and `24` for cents.

JavaScript supports unary negation:

```JS
-(457 % 3);    // => -1
```

## Basic Functions

Function are values as well in JavaScript. How could we verify it? Simple:

```JS
(() => 0)    // => [Function] (for NodeJS)
```

Note: as mentioned above, every value in JS is expression that returns itself. It's actually true, but displaying value on the screen is slightly different matter, as NodeJS community made a convention about `[Function]` as displaying values. In browser we could see `() => 0` as a return value of the examined expression. Regardless of what is displayed, JavaScript engine always has full and proper function.

### commas

The comma operator works interestingly: it takes two arguments, evaluates them both and itself evaluates to the value of right-hand argument.

```JS
(1, 2)    // => 2
(1 + 1, 2 + 2)    // => 4
```

Given described mechanics commas could be useful to create functions that evaluate multiple expressions and could cause side effects:

### undefined

If you deliberatly need `undefined` value, you can use `void` operator:

```JS
void 0        // => undefined
void 1        // => undefined
void (2 + 2)  // => undefines
```

### evaluation strategy

JavaScript uses "call by value" evaluation strategy. That means that when you apply a function to an expression or expressions, JS evaluates all of those expressions and applies the function to the resulting values. Consider:

```JS
((diameter) => diameter * 3.14159)(1 + 1)
```

In this example `1 + 1` was evaluated first and then this expression's value (`2`) was used as function parameter. Or, in other words, circumference function was applied to `2`.
