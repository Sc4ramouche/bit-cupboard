# Week 4 shorts | Structures & Custom Types 

## Structures

Structures provide a way to unify several variables of different types into a single, new variable type which can be assigned its own type name. 

```C
struct car
{
    int year;
    char model[10];
    char plate[7];
    double engine_size;
};
```

Common way to define a structure is to use separate `.h` files.

Declaring struct variables on the stack:

```C
struct car mycar;

mycar.year = 2011;
mycar.plate = "plate";
```

Structures, like variables of all other data types, do not need to be created on the stack. We can dynamically allocate structure at run time. In that situation if we want to access the fields we first need to dereference the pointer to the structure.

Declaring struct variable on the heap:

```C
struct car *mycar = malloc(sizeof(struct car));

(*mycar).year = 2011;
(*mycar).plate = "plate";
```

There is a shortcut for dereferncing and accessing a field in one step – arrow operator (`->`). It **dereferences** the pointer on the left side and **accessess** the field on the right side of the operator.

```C
mycar->year = 2011;
mycar->plate = "plate";
```

## Defining Custom Types

The C keyword `typedef` provides a way to create a shorhand or rewritten name for data types. Uou define a type and then alias it to something else.

```C
// declare a `byte` type
typedef unsigned char byte;
```

`typedef` comes in handy when working with structs. You can alias existing structure to new name or do it in the middle of `struct` declaration!

```C
struct car
{
    int year;
    char plate[7];
};
typedef struct car car_t;

// OR

typedef srtuct car
{
    int year;
    char plate[7];
}
car_t;
```

So assuming you've done this, you can now use that alias in your code:

```C
car_t mycar;
mycar.year = 2011;
```


