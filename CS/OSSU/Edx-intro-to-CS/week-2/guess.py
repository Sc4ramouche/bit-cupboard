# could probably merge `guessed` and `ans` into single variable
guessed = False
ans = -1

low = 0
high = 100
middle = (low + high) // 2

print('Please think of a number between ' + str(low) + ' and ' + str(high) + '!')
while (guessed == False):
    print('Is your secret number ' + str(middle) + '?')
    i = input("Enter 'h' to indicate the guess is too high. Enter 'l' to indicate the guess is too low. Enter 'c' to indicate I guessed correctly.")

    if (i == 'c'):
        guessed = True
        ans = middle
        break
    elif (i == 'l'):
        low = middle
        middle = (low + high) // 2
    elif (i == 'h'):
        high = middle
        middle = (low + high) // 2
    else:
        print('Sorry, I did not understand your input.')

print('Game over. Your secret number was: ' + str(ans))
