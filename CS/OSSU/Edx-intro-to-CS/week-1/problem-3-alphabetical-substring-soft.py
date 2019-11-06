s = input('s: ')
current = s[0]
longest = s[0]

for i in range (1, len(s)):
    last = current[-1]

    if (s[i] >= last):
        current += s[i]
        if (len(current) > len(longest)):
            longest = current

    else:
        if (len(current) > len(longest)):
            longest = current
        current = s[i]

print('Longest substring in alphabetical order is:', longest)
