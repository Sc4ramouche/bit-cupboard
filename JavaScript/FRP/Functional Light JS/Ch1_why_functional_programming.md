# [Chapter 1: Why Functional Programming?](https://github.com/getify/Functional-Light-JS/blob/master/manuscript/ch1.md/#chapter-1-why-functional-programming)

## Confidence

Author implies that FP code (eventually) becomes more readable: you can ensure that your program is doing well just by reading it's source, not by running test suite. That's not doing FP bug-proof, but usually bugs exist in more obvious places.

## Communication

FP code tends to be more readable and understandable. The principles of FP are well established and deeply studied.

Example: once you learn `map(...)`, you'll be almost instantly understand what it does in any program. But you have to read through every `for(...)` loop to actually get what it does. Thus FP frees us up to think about higher level of program logic.

## Readability

Imperative vs. declarative boils down to **how** to do vs. **what** to do. That's not an easy paradigm transform, nor it is binary flip when you can just take imperative peace of code and turn it into declarative. But learning applying FP paradigm worth it.

As YAGNI principle implies, don't try every sophisticated thing in your code if there is no real need in it. Your future self or teammate may struggle to get what's going on. They won't be impressed overly clever solutions.

### Books

* [Professor Frisby's Mostly Adequate Guide to Functional Programming](https://drboolean.gitbooks.io/mostly-adequate-guide-old/content/ch1.html) by Brian Lonsdorf
* JavaScript Allongé by Reg Braithwaite
* Functional JavaScript by Michael Fogus

### Libraries

* Ramda
* lodash/fp
* Immutable.js
