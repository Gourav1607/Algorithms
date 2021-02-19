# Topological Sort / main.py
# Created on: 06-Sept-2018
# Author: Gourav Siddhad

from tsort import tsort

def main():
    t = tsort()
    t.input_file()
    # t.display_vertices()
    # t.display_edges()
    t.display_graph()
    t.display_sorting()

if __name__ == '__main__':
    main()
