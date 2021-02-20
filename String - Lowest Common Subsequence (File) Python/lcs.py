# Lowest Common Subsequence / lcs.py
# Created on: 27-Sept-2018
# Author: Gourav Siddhad

class LCS():
    def __init__(self):
        self.str1 = ''
        self.str2 = ''

    def readInput(self, inputFile):
        fin = open(inputFile, 'r')
        self.str1 = (fin.readline()).strip()
        self.str2 = (fin.readline()).strip()
        fin.close()

    def readInputConsole(self):
        self.str1 = input(" Enter First String : ")
        self.str2 = input(" Enter Second String : ")

    def genTable(self):
        m = [[0 for j in range(len(self.str2) + 1)]
             for i in range(len(self.str1) + 1)]
        b = [[0 for j in range(len(self.str2) + 1)]
             for i in range(len(self.str1) + 1)]

        # row 0 and column 0 are initialized to 0 already
        for i, x in enumerate(self.str1):
            for j, y in enumerate(self.str2):
                if x == y:
                    m[i + 1][j + 1] = m[i][j] + 1
                    b[i + 1][j + 1] = 0  # diagonal
                elif m[i + 1][j] < m[i][j + 1]:
                    m[i + 1][j + 1] = m[i][j + 1]
                    b[i + 1][j + 1] = 1  # top
                else:
                    m[i + 1][j + 1] = m[i + 1][j]
                    b[i + 1][j + 1] = -1  # left

        print(" String 1 : " + self.str1, end='')
        print("\n String 2 : " + self.str2, end='')
        print("\n\n", end='')
        for i, x in enumerate(self.str1):
            for j, y in enumerate(self.str2):
                print(m[i][j], end='')
                # print(b[i][j], end='')
                print(" ", end='')
            print("")

        i, j = len(self.str1), len(self.str2)
        print("\n LCS is : ", end='')
        result = ''
        while i >= 0 and j >= 0:
            if b[i][j] is 0:
                result = result + self.str1[i - 1]
                i = i - 1
                j = j - 1
            elif b[i][j] is 1:
                i = i - 1
            elif b[i][j] is -1:
                j = j - 1
        print(result[::-1])
