/*
  main.cpp
  
  A simple test program that builds a directed graph and determines if it has
  a cycle or not.

  Nic McPhee
  October, 1996 - April, 1997
 */

#include <iostream.h>

#include "graph.cpp"
#include "has_cycle.cpp"

int main(void)
{
    const int max_size = 20;
    Graph<int, int> g;
    
    // Add 20 nodes to the graph
    int i;
    for (i=1; i<=max_size; ++i) {
        g.InsertVertex(i);
    }
    
    // Add an edge from node i to node j iff i is a multiple of j.
    for (i=1; i<=max_size; ++i) {
        for (int j=1; j<=max_size; ++j) {
            if (j != 0 && i != j && i % j == 0) {
                g.InsertEdge(i, j, i / j);
            }
        }
    }

    // With this line in, the graph has a cycle, without it it doesn't.
    // Thus you can comment this line in and out as a simple test of your code.
    // Note, however, that you'd want more than just this to provide real testing.
    g.InsertEdge(5, 10, 1);
    
    // Print out the graph.
    // This scrolls by a lot of stuff, so you might want to comment it
    // out in some circumstances.
    for (i=1; i<=max_size; ++i) {
        for (int j=1; j<=max_size; ++j) {
            if (g.Adjacent(i, j)) {
                cout << "There is an edge from " << i << " to " << j << "\n";
                cout << "\twith value = " << g.Retrieve(i, j) << ".\n";
            }
        }
    }

    cout << "This graph has " << g.Num_vertices() << " vertices and ";
    cout << g.Num_edges() << " edges.\n";
    
    if (g.Has_cycle()) {
        cout << "This graph has a cycle.\n";
    } else {
        cout << "This graph does not have a cycle.\n";
    }
    
    return(0);
}
