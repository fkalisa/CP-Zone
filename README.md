# CP-Zone

### Prefix sum
  
  - Array
  - Matrix

### Euler Totient Function - phi(n), Φ(n)
  
  Number of co-primes(GCD==1) between n and i (1 to n-1)
  - brute force solution (finding all co-primes) -> O(nlogn)  
  - solution with the formula(2) --> O(sqrt(n)) 
  - solution with product rule (3)
  Example : phi(5)= 4  
  1- if n is prime -> phi(n) = n-1  
  2- if a = p^n -> phi(a)= p^n - p^(n-1)  
  3- phi(n) = n*((1-1/p1)* ....* (1-1/pi))  

### Sieve

Sieve is based on creation an array from 1 to n
  - sieve of eratosthenes : find if a given number is prime or not, Sieve array will contain the boolean stating if a number is prime or not  
  - Modified Sieve : find prime factors of a given number, Sieve array will contain the smallest prime factor
  - Segmented Sieve : counting primes in range, n >=1 and n<=10e9 (big!!) and the range is ok 10e4, create a dummy array of booleans

### Euclidean algorithm to find x and y

Given a Linear Diophantine Equation (LDE) a*x+b*y=c, we can deduct that c % gcd(a, b) ==0

### Kadane's Algorithm

Used to find the max sum subarray

### Dutch National Flag Algorithm 

### Kahn's Algorithm

### String Algorithm

##### KMP(Knuth–Morris–Pratt)'s  Algorithm
##### Robin Karp Algorithm
##### Z Algorithm

### Devide and conquer Algorithm

##### Merge Sort (see Sorting Algorithms)
##### Meet in the middle Algorithm

## Graph

- In a graph, we have N nodes and M edges 
- In a graph, we need to create an adjacency list
- In a graph, any node can be root  
- In a graph, we have a visited array to avoid infinite traversal
- Every tree is a graph !!
- Every DFS call run in O(N)
- A graph can be directed or undirected
- Applications :

    - Number of connected components 
      - HowTo : the number of times DFS/BFS is called
    - Detect a cycle in undirected graph [code](https://github.com/fkalisa/CP-Zone/blob/master/graph-and-tree/cycleInUndirectedGraph.cpp) 
      - HowTo : the node is not parent and it has been visited  
    - Detect a cycle in directed graph  
      - HowTo :
          - Use two visited array [code](https://github.com/fkalisa/CP-Zone/blob/master/graph-and-tree/cycleInDirectedGraph-withTwoVisitedArrays.cpp)  
          - Use 3 colors (white, gray, black) [code](https://github.com/fkalisa/CP-Zone/blob/master/graph-and-tree/cycleInDirectedGraph.cpp)  
    - Bipartite (consecutive nodes have different colors) [code](https://github.com/fkalisa/CP-Zone/blob/master/graph-and-tree/bipartiteGraph.cpp)  
      - HowTo :
          - Use a color array, if the adjacent element color is equal to the curent color, the graph is not bipartite
          - Application : Check if there is an odd length cycle in the graph -> Not a bipartite graph
    - Topological sort (only possible with DAG (Directed Acyclic Graph) -> No cycle ), TopoSort can be used to detect a cycle (indegrees case) 
      - HowTo :
          - Application : linear ordering of vertices
          - 2 approches :
            - indegree: you starts with node which has indegree 0 -> no coming edge, update the indegree map (**Kahn's algorithm**) - BFS [code](https://github.com/fkalisa/CP-Zone/blob/master/graph-and-tree/topologicalSort-usingIndegreesArray.cpp)  
          - Using a stack - DFS [code](https://github.com/fkalisa/CP-Zone/blob/master/graph-and-tree/topologicalSort-usingStack.cpp) - called pre visited and post visited - this can allow to detect cycle ass (in base condition if a node is visited but visite is at pre -> we have a cycle, we can return, it a node is visted but visite is at post we can return)
         
          - Example:
              - Fox and Names [problem](https://codeforces.com/problemset/problem/510/C) [code](https://github.com/fkalisa/CP-Zone/blob/master/graph-and-tree/FoxAndNames.cpp)  
    - [Bridges](https://github.com/fkalisa/CP-Zone/blob/master/images/bridge.png) in the graph : a bridge is an edge when taken off, it creates one or more components in the graph
      - HowTo :
          - keep the parent, the low and nodeTime array and a timer [code](https://github.com/fkalisa/CP-Zone/blob/master/graph-and-tree/bridge.cpp)  
    - Articulation points in the graph : articulation is a node when taken off, it creates one or more components in the graph
      - HowTo :
            TODO  
    - [Dijkstra](https://github.com/fkalisa/CP-Zone/blob/master/images/dijkstra.png) algorithm Nlog(N) : shortest path between source and destination on weighted graph
      - Another algorithm to find the shortest path is : Floyd–Warshall algorithm 
        - Application of Floyd–Warshall algorithm : any source to any destination
      - if the distance of the destination is infinity or the parent destination is -1, it means you never reached the destination
      - HowTo :
          - Step1: you need distance array populated with infinity except the source node which is polulated with 0
          - Step2: you need a priority queue(distance, node)  
          - Step3: you need to iterate until the priority queue is empty  
          - Dijkstra using a pair [code](https://github.com/fkalisa/CP-Zone/blob/master/graph-and-tree/algorithm-dijkstra-1.cpp)  
          - Dijkstra using a map to store the weights [code](https://github.com/fkalisa/CP-Zone/blob/master/graph-and-tree/algorithm-dijkstra-2.cpp)  
          - Dijkstra printing the node traversed using the parent array [code](https://github.com/fkalisa/CP-Zone/blob/master/graph-and-tree/algorithm-dijkstra-3-20C.cpp)  

        
          

## Tree 
- In a tree, we have N nodes and N-1 edges  
- In a tree, we have a root
- In a tree, we carry a parent to avoid infinite traversal  
- A tree is not a graph
- Applications :


## Segment tree 
Minumum range queries

## Fenwick tree

- Fenwick tree is represented as an array  
- Fenwick tree is zero based index  
- Fenwick tree consist of sum (range) and update  
- Fenwick tree is batter compared to segment tree with regard space complexity  

## Euler Tour of a Tree Algorithm 

Use DFS and when traversing store the node in vector (or print the node) and when coming back store the result as well (or print the node).
[code](https://github.com/fkalisa/CP-Zone/blob/master/graph-and-tree/eulerTour.cpp) 

## Lowest Common Ancestor (LCA) of a Tree Algorithm

Also known as nearest ancestor between 2 numbers a and b in the tree 
Two approaches :  
- Use Euler Tour Algorithm : the solution is the the element in between euler tour with minimum height [code](https://github.com/fkalisa/CP-Zone/blob/master/graph-and-tree/algorithm-LowestCommonAncestorWithEulerTour.cpp)   
- Use parent array : the solution is the common element [code](https://github.com/fkalisa/CP-Zone/blob/master/graph-and-tree/algorithm-LowestCommonAncestor.cpp) 

## Binary lifting Algorithm (LCA purpose)

- Maintain a dp array dp[node][x] -> 2^x th parent of node (distance)  
- Compute the levels difference between a, and b  
- Bring a and b to the same level by moving up of the difference height between a and b
- For 10^15, we have maximum log(10^15) + 1 parents (15 +1)
- for each i in parent
  [a][n], [b][n] equals:  return the answer
  (to be continued)

## Sorting Algorithms

##### Insertion Sort

##### Selection Sort

##### Merge Sort

## Disjoint Set Union (Union find)

##### Minimum Spanning Tree MST - Kruskal Algorithm




