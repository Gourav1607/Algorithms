# Lowest Common Subsequence / main.py
# Created on: 27-Sept-2018
# Author: Gourav Siddhad

from lcs import *

def main():
    lcs = LCS()
    lcs.readInput('input.txt')
    lcs.genTable()

if __name__ == "__main__":
    main()
