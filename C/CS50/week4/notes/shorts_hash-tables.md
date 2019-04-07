# Week 4 shorts | Hash Tables

Hash tables combine the random access ability of an array with the dynamism of a linked list.

This could mean that operations like insert, delete, and lookup can start to tend toward O(1) complexity. This provides the advantages of both types of data structure, while mitigating the disadvantages.

To get this performance upgrade, we create a new structure whereby when we insert data into the structure, the data itself gives us a clue about where we will find the data, should we need to later look it up. The trade off is that hash tables are not great at ordering or sorting data.

A hash table amounts to a combination of two things:

* A **hash function**, which returns an nonnegative integer value called  a *hash code*.
* An **array** capable of storing data of the type we wish to place into the data structure.

The idea is that we run our data through the hash function, and then store the data in the elemnt of the array represented by the returned hash code.

A good hash function should:

* Use only the data being hashed
* Use all of the data being hashed
* Be deterministic (pure function)
* Uniformly distribute data
* Generate very different hash code for very similar data

```C
unsigned int hash(char* str)
{
    int sum = 0;
    for (int j = 0; str[j] != '\0'; j++)
        sum += str[j];

    return sum % HASH_MAX;
}
```

### Collision

A **collision** occurs when two pieces of data, when run through the hash function, yield the same hash code. We don't want to occasionally overwrite any data, so we need to find a way to get both elements into the hash table, while trying to preserve quick insertion and lookup.

Resolving collisions: **Linear probing**. If we have a collision, we try to place the data in the next consecutive element in the array (wrapping around to the beginning if necessary) until we find a vacancy.

Resolving collisions could also be done in a fancy way – *chaining*. Basically, why don't we use linked list as an value of hash table? This solves *clustering* problem as well.
