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
- In a graph, any node can be root  
- In a graph, we have a visited array to avoid infinite traversal
- Every tree is a graph !!
- A graph can be directed or undirected
- Applications :

    - Number of connected components 
      - HowTo : the number of times DFS/BFS is called
    - Detect a cycle in undirected graph  [code](https://github.com/fkalisa/CP-Zone/blob/master/graph-and-tree/cycleInUndirectedGraph.cpp) 
      - HowTo : the node is not parent and it has been visited  
    - Detect a cycle in directed graph  
      - HowTo :
          - Use two visited array [code](https://github.com/fkalisa/CP-Zone/blob/master/graph-and-tree/cycleInDirectedGraph-withTwoVisitedArrays.cpp)  
          - Use 3 colors (white, gray, black)[code](https://github.com/fkalisa/CP-Zone/blob/master/graph-and-tree/cycleInDirectedGraph.cpp)  
    - Bipartite (consecutive nodes have different colors) [code](https://github.com/fkalisa/CP-Zone/blob/master/graph-and-tree/bipartiteGraph.cpp)  
      - HowTo :
          - Use a color array, if the adjacent element color is equal to the curent color, the graph is not bipartite
          - Check if there is an odd length cycle in the graph

## Tree 
- In a tree, we have N nodes and N-1 edges  
- In a tree, we have a root
- In a tree, we carry a parent to avoid infinite traversal  
- A tree is not a graph


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




