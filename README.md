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
  - Segmented Sieve : 

### Kadane's Algorithm
Used to find the max sum subarray

### KMP(Knuth–Morris–Pratt)'s  Algorithm


## Sorting Algorithms

### Insertion Sort

### Selection Sort

### Merge Sort
