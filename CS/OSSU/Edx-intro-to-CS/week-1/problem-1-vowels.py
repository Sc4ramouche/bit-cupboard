# note: input function works for python3 only here

count = 0
vowels = ['a', 'e', 'i', 'o', 'u']
s = input('provide s:')

for character in s:
    if (character in vowels):
        count += 1

print('Number of vowels:', count)
