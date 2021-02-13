#include <bits/stdc++.h>

using namespace std;

vector<int> adjs [100005];
int visited [100005];
int visitedDFS [100005];
int visitedTopo [100005];
stack<char> stackk;

bool cycleDetectedInDFS(int node) {

	visited[node] = 1;
	visitedDFS[node] = 1;

	for (auto it : adjs[node])
	{

		if (!visited[it])
		{
			if (cycleDetectedInDFS(it)) {
				return true;
			}
		} else if (visitedDFS[it]) {
			return true;
		}
	}
	visitedDFS[node] = 0;
	return false;
}



void dfsToposort(int node) {

	visitedTopo[node] = 1;

	for (auto it : adjs[node])
	{
		if (!visitedTopo[it])
		{
			dfsToposort(it);
		}
	}

	stackk.push((char)(node + 'a'));
}

int main() {
#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif


	/*

	https://codeforces.com/problemset/problem/510/C
	topological sort

	steps :

	- create the adjecency list
	- detect impossible cases :
		- abcd vs abc
		- DFS cycle detection
	- Topological traversal using a stack
	- Display the content of the stack

	input :

	10
	petr
	egor
	endagorion
	feferivan
	ilovetanyaromanova
	kostka
	dmitriyh
	maratsnowbear
	bredorjaguarturnik
	cgyforever

	output :

	aghjlnopefikdmbcqrstuvwxyz


	*/
	int n;
	cin >> n;

	string arr[n];
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		arr[i] = s;

	}
	for (int i = 1; i < n; ++i)
	{
		string s1 = arr[i - 1];
		string s2 = arr[i];


		for (int j = 0; j < s1.size(); ++j)
		{
			if (j == s2.size()) {

				cout << "Impossible" << endl;
				return 0;
			}

			if (s1[j] != s2[j])
			{
				adjs[ s1[j] - 'a'].push_back(s2[j] - 'a');
				break;
			}
		}

	}

	for (int i = 0; i < 26; ++i)
	{
		if (!visited[i] && cycleDetectedInDFS(i)) {

			cout << "Impossible" << endl;
			return 0;
		}
	}

	for (int i = 0; i < 26; ++i)
	{
		if (!visitedTopo[i])
		{
			dfsToposort(i);
		}
	}


	while (!stackk.empty()) {
		cout << stackk.top();
		stackk.pop();
	}

	return 0;

}