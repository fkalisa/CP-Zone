#include <bits/stdc++.h>
using namespace std;

int compute(int matrix[][], int i, int j, int n, int m) {


	if (i == n - 1 && j == m - 1)
	{
		return 1;
	}

	int left;
	if(i+1 < n){
		left =compute( matrix,  i + 1 ,  j,  n,  m);
	}
	int right;
	if(j+1 < m){	
		compute( matrix,  i ,  j + 1,  n,  m);
	}

	return left + right;
}

int main() {

#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif



	return 0;
}
