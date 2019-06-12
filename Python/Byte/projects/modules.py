import sys
import os

print('The command line arguments are:')
for i in sys.argv:
    print(i)

print('\nThe PYTHONPATH is', sys.path, '\n')

print('The current directory:{}', os.getcwd())
