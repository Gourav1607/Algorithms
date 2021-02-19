# Strongly Connected Components / main.py
# Created on: 30-Aug-2018
# Author: Gourav Siddhad

from graph import Graph

def main():
    graph = Graph()
    graph.read_File('input.txt')
    print("Following are strongly connected components in given graph")
    graph.printSCCs()

if __name__ == '__main__':
    main()
