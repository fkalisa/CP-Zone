#include <bits/stdc++.h>

using namespace std;

/*

You are given 2 strings s1 and s2 of the same length 'N', and you are given 'Q' constraints on s2.
Each constraint is in the form of [L[i], R[i]] i.e. you can only swap elements at the indices L[i] with R[i] any number of times!

You can swap the elements in s2 as per these Q constraints any number of times!
[Note: You cannot swap 2 indices if they are not mentioned in queries]

You have to check whether it is possible to make s2 equal to s1!

Example:

I/P: s1="abcde", s2="ebadc", Q={[0,2],[2,4]}
O/P: True

Explanation:
You can swap index '0' & index '2' and then index '2' & index '4' in s2 and make it equal to s1="abcde"



Hint: DFS + Connected Components!
*/


int Q[2][2] = {{0, 2}, {2, 4}};
int answer = 0;
set<string> visited;

void dfs(string start, string dest) {

	visited.insert(start);

	cout << start << endl;
	if (start == dest)
	{
		answer = 1;
		return;
	}
	int tt = 2;

	for (int k = 0; k < tt; ++k)
	{
		int i = Q[k][0];
		int j = Q[k][1];

		char tmp = start[i];
		start[i] = start[j];
		start[j] = tmp;

		if (visited.find(start) == visited.end())
		{
			dfs(start, dest);
		}
	}

}


int main() {
#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif

	string s1 = "abcde";
	string s2 = "ebadc";



	dfs(s2, s1);

	cout << answer << endl;
	return 0;

}