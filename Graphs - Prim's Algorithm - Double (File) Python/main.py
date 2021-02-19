# Minimum Spanning Tree / main.py
# Created on: 23-Aug-2018
# Author: Gourav Siddhad

from graph import Graph

def main():
    graph = Graph('input.txt')
#     print('Co-ordinates')
#     graph.display_cord()
#     print('\nEdges - Weights')
#     graph.display_edges()

    print('\nFirst Round')
    parent = graph.primMST()
    graph.printMST(parent)

    print('\nSecond Round')
    graph.double_prim(parent)
    parent = graph.primMST()
    graph.printMST(parent)

if __name__ == '__main__':
    main()
