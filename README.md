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
### Segment tree 
Minumum range query

## Euler Tour Algorithm
use a vector 

### LCA (Lowest Common Ancestor - nearest ancestor)
Between 2 numbers a and b
Use Euler Tour Algorithm
Use the height, the minimum height between a and b

### Binary lifting

## Sorting Algorithms

##### Insertion Sort

##### Selection Sort

##### Merge Sort
