# Radix Sort / main.py
# Created on: 16-Aug-2018
# Author: Gourav Siddhad

from employee import Employee
from radix import *


def main():
    radix = Radix()
    radix.read_File('input.txt')
    radix.displayInput()
    radix.sort()
    print('')
    radix.displayOutput()


if __name__ == "__main__":
    main()
