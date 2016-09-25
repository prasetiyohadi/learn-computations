# Dijkstra Shortest Path Algorithm

Dijkstra's algorithm, conceived by Dutch computer scientist Edsger Dijkstra in 1956 and published in 1959, is a graph search algorithm that solves the single-source shortest path problem for a graph with nonnegative edge path costs, producing a shortest path tree.   This algorithm is often used in routing and as a subroutine in other graph algorithms. For a given source vertex (node) in the graph, the algorithm finds the path with lowest cost (i.e. the shortest path) between that vertex and every other vertex.   It can also be used for finding costs of shortest paths from a single vertex to a single destination vertex by stopping the algorithm once the shortest path to the destination vertex has been determined. (From [Wikipedia](http://en.wikipedia.org/wiki/Dijkstra%27s_algorithm))

File shortestpath.cpp contain C++ code for Dijkstra algorithm for a graph with 13 nodes represented in adjacency matrix. You can compile the code using the following command

```
$ g++ shortestpath.cpp
```

Then you can try to execute the program

```
$ ./a.out
Shortest distance of node A from A is 0
Shortest distance of node B from A is 10
Shortest distance of node C from A is 9
Shortest distance of node D from A is 5
Shortest distance of node E from A is 17
Shortest distance of node F from A is 13
Shortest distance of node G from A is 14
Shortest distance of node H from A is 22
Shortest distance of node I from A is 20
Shortest distance of node J from A is 6
Shortest distance of node K from A is 23
Shortest distance of node L from A is 20
Shortest distance of node M from A is 13
```
