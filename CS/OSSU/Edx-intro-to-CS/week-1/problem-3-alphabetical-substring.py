# this is strict version of the this problem:
# letters has to be next to each other to be considered in alphabetical order
s = input('s: ')
current = s[0]
longest = s[0]

for i in range (1, len(s)):
    last = ord(current[-1])

    if (ord(s[i]) == last + 1):
        current += s[i]
    else:
        if (len(current) > len(longest)):
            longest = current
        current = s[i]

print('Longest substring in alphabetical order is:', longest)
