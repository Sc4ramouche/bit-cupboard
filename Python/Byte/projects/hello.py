# variables
age = 20
name = 'Swaroop'

# format
print('{0} was {1} years old when he wrote this book'.format(name, age))
print('Why is {} playing with that python?'.format(name))

#raw string
print(r'newlines \n')

# while loop
number = 5

while number > 0:
    print('{}!'.format(number))
    number -= 1

print('The for loop is over')

# for loop
for i in range(1, 5):
    print(i)
else:
    print('The for loop is over')
