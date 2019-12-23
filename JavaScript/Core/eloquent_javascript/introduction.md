# Introduction

## Program Design

I particularly liked the following sentense from the intro of the book:

> There are many terrible mistakes to make in program design, and you should go ahead and make them so that you understand them. A sense of what a good program looks like is developed in practice, not learned from a list of rules.

"List of rules" mentioned there is referring best practices. I think this is wise approach.

## Performace

There's nice insight on performance.

> Worrying about efficiency can be a distraction. It's yet another factor that complicates program design, and when you're doing something that's already difficult, that extra thing to worry about can be paralyzing.

## YAGNI

> A useful principle is to not add cleverness unless you are absolutely sure you're going to need it. It can be tempting to write general "frameworks" for every bit of functionality you come across. Resist that urge. You won't get any real work done – you'll just be writing code that you never use.

## Functions

Functions can be divided into those that are calle for their side effects and those that are called for their return value. Second type is usually more useful, as these functions are more likely to be reusable.
