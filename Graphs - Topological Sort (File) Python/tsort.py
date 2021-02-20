# Topological Sort / tsort.py
# Created on: 06-Sept-2018
# Author: Gourav Siddhad

from graph import Graph


class tsort:
    def __init__(self):
        self.graph = Graph()

    def input_file(self, inputFile):
        with open(inputFile, 'r') as graphInput:
            for line in graphInput:
                ints = [int(x) for x in line.split()]
                src = ints[0]
                for dest in ints:
                    self.graph.add_edge(src, dest)

    def display_vertices(self):
        print(' Vertices: ', end='')
        for v in self.graph:
            print(v.get_key(), end=' ')

    def display_edges(self):
        print(' ')
        print('Edges: ')
        for v in self.graph:
            for dest in v.get_neighbours():
                w = v.get_weight(dest)
                print('(src={}, dest={}, weight={}) '.format(
                    v.get_key(), dest.get_key(), w))
            print()

    def display_graph(self):
        print(' ')
        for v in self.graph:
            print(v.get_key(), end=' | ')
            for dest in v.get_neighbours():
                print(dest.get_key(), end=' ')
            print()

    def display_sorting(self):
        tlist = self.get_topological_sorting()
        print('')
        if tlist is not None:
            print('Topological Sorting: ', end='')
            print(tlist)
        else:
            print('Graph is not a DAG.')

    def get_topological_sorting_helper(self, v, visited, on_stack, tlist):
        if v in on_stack:
            return False

        on_stack.add(v)
        for dest in v.get_neighbours():
            if dest not in visited:
                if not self.get_topological_sorting_helper(dest, visited, on_stack, tlist):
                    return False
        on_stack.remove(v)
        visited.add(v)
        tlist.insert(0, v.get_key())  # prepend node key to tlist
        return True

    def get_topological_sorting(self):
        tlist = []
        visited = set()
        on_stack = set()
        for v in self.graph:
            if v not in visited:
                if not self.get_topological_sorting_helper(v, visited, on_stack, tlist):
                    return None
        return tlist
