# Introduction

## run C program

1. compile with `gcc -o desired_name source_file.c`
2. run with `./desired_name`
3. if you want to avoid `./` part: add `export PATH=.:$PATH` to profile

## range

In C size depends on machine you are running. It could be 16 or 32 bit for type `int`.

Basic types are:

* `int` – integer;
* `float` – floating point number;
* `char` – character, a single byte;
* `short` – short integer;
* `long` – long integer;
* `double` – double-precision floating point.

## arithmetic coercion

If an arithmetic operator has integer operands, an integer operation is performed. If an arithmetic operator has one floating-point operand and one integer operand, however, the integer will be converted to floating point before the operation is done. But it's still a good practice to write floating point constants. This is true for comparison (`>, <, <= ...)` and assignments as well.

## EOF

Special value equals to `-1`. You can put it into terminal with `Ctrl+D`.

## command line arguments

You can pass arguments to your C program. Conventionally it looks like this:

```C
int main(int argc, char** argv) { /* ... */ }
```

`argc` used to denote number of command line arguments. Note that it would always be >= 1, because name of the program counts as the first argument. Rest of the command line arguments end up split by whitespaces and pushed to the `argv` array.

## arguments

If you want to declare a function which doesn't accept any arguments you can state it implicitly:

```C
int get_line(void)
```

Another reason to do this is to achive compatibility with older C standarts.

## structures

Structures are used to declare new *types*:

```C
typedef struct {
    float x;
    float y;
} point;
```

You can use structures like the following:

```C
point p;
p.x = 42;
p.y = 3.17;

float length = sqrt(p.x * p.x + p.y * p.y);
``` 

And you can shallow copy structures by simple assignment:

```C
BITMAPINFOHEADER bi;
/* fill bi with content */
BITMAPINFOHEADER outbi = bi;
```

## enum

An enumeration is a list of constant integer values:

```C
enum boolean { NO, YES };
```

The first name in an enum has value 0, the next 1 and so on, unless explicit values are specified.

## const

The qualifier `const` can be applied to the declaration of any variable to specify that its value will not be changed:

```C
const double e = 2.71828182845905;
```

The `const` declaration can also be used with array arguments, to indicate that the function does not change that array:

```C
int strlen(const char[]);
```

## pointers

Pointers is special variable that holds the address to some actual value. For example, if we want to store string `"awesome"`, using some `get_string` function, we could do this like this:

```C
char *s = get_string("string: ");
```

In this case, `s` would hold the value of the first character address – `'a'` address. Knowing that, we then could process whole string, assuming `get_string` did job of adding `'\0'` to the end of the string for us:

```C
for (int i = 0, n = strlen(s); i < n; i++)
    printf("%c\n", s[i]);
```

This concept leads to another called *pointer arithmetic*. Operator `*` is used in slightly different context here:

```C
    for (int i = 0, n = strlen(s); i < n; i++)
        printf("%c\n", *(s + i));
```

We are able to get rid of brackets notation, as it is kind of syntactic sugar. And `*(s + 1)` is simply saying 'go to the address `s + 1` and give me back value stored there'. This is works because our string is stored in continious chunk of memory. So if `s` is pointing to `'a'`, `s + 1` would point to `'w'`.

In the latter case `*` means 'go to that pointer', but when we see something like `char *s` – that means 'give me the pointer'.

We can summarize it as **pointer** is a data item whose value is a *memory address*. Type of the pointed describes the data located at that memory address.

**Important**: every time you create a pointer and you don't set its value immediately, you should always set the value of the pointer to `NULL`.

### dereferencing

The main purpose of a pointer is to allow us to modify or inspect the location to which it points.

If we have a pointer-to-char called `pc`, then `*pc` is the data that lives at the memory address stored inside the variable `pc`.

```C
char c = 'L';
char *pc = &c;
*pc = 'D';       // dereferencing
```

In the context of the statement `*pc = 'D'` `*` operator is known as the *dereference operator*. It "goes to the reference" and accesses the data that memory location, allowing you to manipulate it at will.

### pointers summary

```C
int* p;
```

* The value of `p` is an address.
* We can dereference `p` with the `*` operator.
* If we do, what we'll find at that location is an `int` value.

To create several pointers at one line:

```C
int* px, py, pz;      // wrong
int* pa, *pb, *pc;    // right
```

## addresses

Address concept is closely related to pointers. Consider:

```C
int x;
scanf("%i", &x);
```

In this little program we prompt user to insert an integer. And we want to store user input in `x` variable. We could not just pass it as is – it won't work in expected way. This is because of computer memory implementation: every function in C creates its own memory chunk(frame) in stack. And when we pass `x` to the function `scanf` we just pass copy of `x`.

Se we can't just change primitive value from inner scope. That's why we have to use *address* if we want to modify primitive value.

Consider another example, little swap program:

```C
int main(void)
{
    int x = 1, y = 2;
    swap(&x, &y);
}

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

Quick overview of what's happening in `swap` function:

1. We grab the value stored by address `a` and put it into `temp`. That's `1` in this case;
2. Change the value stored by address `a` to value stored in address `b`.
3. Assign the value stored by address `b` to `temp` (`1`).

## mistakes regarding pointers and addresses

Consider this program:

```C
   char *s;
   scanf("%s", s);
```

Basically, `char *s` tells computer to take a block of memory to use it as a pointer. But it holds so called *garbage* value as it is not initialized. And we can't rely this to be pointer, it is random address, so we can't use it effectively. We haven't allocated space for the string we are trying to get.

Another one:

```C
   char s[5];
   scanf("%s", s);
```

There is potentially an overflow issue: what if user provides too long of a string? In this case you'll deal with overflow.

## type conversions

In general, the only automatic conversions are those that convert a "narrower" operand into a "wider" one without losing information, such as converting an integer to floating point in an expression like `f + i`. Expressions that might lose information may draw a warning, but they are not illegal.

If arguments are declared by a function prototype, the declaration causes automatic coercion of any arguments when the function is called.

In the following snippet integer `2` coerced to the *double* value `2.0`:

```C
// prototype
double sqrt(double);
// implicit coercion to 2.0
root = sqrt(2);
```

### cast type

You can explicitly cast value to another type:

```C
sqrt((double) n)
```


### exercises

Complete 2.3 (page 60)

## stack and heap

`malloc` allocates memory from the heap, but anytime you declare local variables or arrays inside of the function that ends up on the stack. So `malloc`, `calloc` and `realloc` are the only tools that give access to the heap.

## array limitations

Usually we declare arrays in C with predefined capacity. In case you need more space in array you would have to allocate bigger memory chunk and copy existing array to it. Or you could use `realloc`, which is effectively transfers allocated memory to new location, if such available and frees previous occupied memory.

```C
// extend `numbers` by one element
numbers = realloc(numbers, sizeof(int) * (size + 1));
```

Manual allocation is not effective: you actually need twice as much memory to copy everything. Also it's not quite good from time perspective – copying is *O(n)* operation. There is another issue – for array you need contiguous chunk of memory and your sistem could not have one (or its memory is *fragmeneted*).

## linked list

Linked list is a data structure represented by cells, each having value and pointer for the next value. Linked lists do not solve memory inefficiency. But it solves the fragmented memory problem, as you can store every member in any location.

```C
typedef struct node
{
    int number;
    struct node *next;
}
node;
```

Following example represent code that checks whether number is already in linked list:

```C
bool found = false;
for (node *ptr = numbers; ptr != NULL; ptr = ptr->next)
{
    if (ptr->number == number)
    {
        found = true;
        break;
    }
}
```

Syntax `->` is used for operation described as "follow the pointer and extract `number` from scrtucture found there".

Adding new value to the list:

```C
node *n = malloc(sizeof(node));

n->number = number;
n->next = NULL;
if (numbers)
{
    for(node *ptr = numbers; ptr != NULL; ptr = ptr->next)
    {
        if(!ptr->next) 
        {
            ptr->next = n;
            break;
        }
    }
}
else
    numbers = n;
```
