#include <bits/stdc++.h>
using namespace std;


extern const int V = 6;
extern const int E = 6;

vector<int> adjs[V];
int indegrees [V];


void init(int n) {
	for (int i = 0; i < n ; ++i)
	{
		int u, v;
		cin >> u >> v;
		adjs[u].push_back(v);
		indegrees[v]++;
	}
}


void compute(vector<int> &v) {

	queue<int> q;

	for (int i = 0; i < V ; ++i)
	{
		if (indegrees[i] == 0) {
			q.push(i);
		}
	}


	while (!q.empty()) {

		int current = q.front();
		q.pop();
		v.push_back(current);

		for (int i = 0; i < adjs[current].size(); ++i)
		{
			indegrees[adjs[current][i]]--;
			if (indegrees[adjs[current][i]] == 0)
			{
				q.push(adjs[current][i]);
			}
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
	/*

	for DAG : Direct Acyclic Graph
	Maintain indegree array

	Vertices : 6 (0..5)
	Edges : 6

	input

	5 2
	5 0
	4 0
	4 1
	2 3
	3 1


	output :

	4 5 2 0 3 1

	application : compiler, dependancy resolution, ...


	Detect a cycle use :

	5 2
	5 0
	4 0
	4 1
	2 3
	3 1
	3 5

	change the number of edges in global variable
	*/

	memset(indegrees, 0, sizeof indegrees );
	init(E);

	vector<int> v;
	compute(v);

	for (auto it : v)
	{
		cout << it << " " ;
	}
	cout << endl;

	// detect if a cycle

	if (v.size() == V) {
		cout << "No cycle" << endl;
	} else {
		cout << "Cycle exists" << endl;
	}
}