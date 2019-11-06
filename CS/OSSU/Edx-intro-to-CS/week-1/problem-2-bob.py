# note: input function works for python3 only here

count = 0
bob = 'bob'
s = input('provide s:')

for i in range(len(s)):
    if (bob in s[i:i+3]):
        count += 1

print('Number of times bob occurs is:', count)
