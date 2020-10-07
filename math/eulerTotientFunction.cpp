#include <bits/stdc++.h>

using namespace std;


/*
	Time complexity : O(logN)
	GDC involve sqrt --> O(logN)
*/
int gcd(int a, int b) {

	if (a == 0) {
		return b;
	}
	return gcd( b % a,  a );
}

/*
	Time complexity : O(NlogN)
*/

int compute1(int input) {

	int counter = 0;

	for (int i = 1; i < input; ++i)
	{
		if ( gcd(input, i) == 1)
		{
			counter++;
		}

	}

	return counter;

}
/*
	find prime factors and apply the formula

*/

int compute2(int input) {

	map<int, int> mapp;

	for (int i = 2; i * i <= input; ++i)
	{

		while (input % i == 0) {

			mapp[i]++;
			input = input / i;
		}

	}

	if (input > 1)
	{
		mapp[input]++;
	}

	int answer = 1;

	for (auto it : mapp)
	{
		int b = it.first;
		int p = it.second;
		answer = answer * (pow (b, p) - pow(b, p - 1));

	}

	return answer;

}

int compute3(int input) {

	int answer = input;

	for (int i = 2; i * i <= input; ++i)
	{

		if (input % i == 0)
		{

			answer = answer * (1.0 - (1.0 / (float)i));
			while (input % i == 0) {
				input = input / i;
			}
		}


	}

	if (input > 1)
	{
		answer = answer * (1.0 - (1.0 / (float)input));
	}

	return answer;
}


int main() {
#ifndef ONLINE_JUDGE

//for getting input from input.txt
	freopen("../../../env/input.txt", "r", stdin);

//for writting output to output.txt
	freopen("../../../env/output.txt", "w", stdout);
#endif

	int value = 9;
	cout << compute1(value) << endl;
	cout << compute2(value) << endl;
	cout << compute3(value) << endl;
}

