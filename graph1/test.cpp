/*
  main.cpp
  
  A simple test program that builds a directed graph and determines if it has
  a cycle or not.

  Nic McPhee
  October, 1996 - April, 1997
 */

#include <iostream.h>

#include "graph.h"
#include "has_cycle.cpp"

// A(1), B(2), C(3), D(4), E(5), F(6)
// AB 7
// AC 1
// BD 4
// BF 1
// CB 5
// CE 2
// CF 7
// EB 2
// ED 5

int main(void)
{
    const int max_size = 6;
    const int A=1, B=2, C=3, D=4, E=5, F=6;
    Graph<int, int> g;
    
    // Add 20 nodes to the graph
    int i;
    for (i=1; i<=max_size; ++i) {
        g.InsertVertex(i);
    }
    
    // Add an edge from node i to node j 
    g.InsertEdge(A, B, 7);
    g.InsertEdge(A, C, 1);
    g.InsertEdge(B, D, 4);
    g.InsertEdge(B, F, 1);
    g.InsertEdge(C, B, 5);
    g.InsertEdge(C, E, 2);
    g.InsertEdge(C, F, 7);
    g.InsertEdge(E, B, 2);
    g.InsertEdge(E, D, 5);

    // With this line in, the graph has a cycle, without it it doesn't.
    // Thus you can comment this line in and out as a simple test of your code.
    // Note, however, that you'd want more than just this to provide real testing.
    //g.InsertEdge(5, 10, 1);
    
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
