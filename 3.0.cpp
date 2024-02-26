#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	// Given Appointments.
	vector<vector<int> > v{
		{ 1, 5 }, { 3, 7 }, { 2, 6 },
		{ 10, 15 }, { 5, 6 }, { 4, 100 }
	};
	// sort according to start time of meet/appointment.
	// sort(v.begin(), v.end());
	// number of pair or appointments.
	int n = v.size();
	// for stoping the overlapping
	// vector<bool>vis(n,0);
	// traverse over and check for it.
	vector<pair<pair<int, int>, pair<int, int> > > result;
	for (int i = 0; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			// to reduce extra/unwanted comparisons.
			// if(v[j][0]>v[i][1])break;
			// else{
			if (v[j][0] < v[i][1]) {
				result.push_back({ { v[i][0], v[i][1] },
								{ v[j][1], v[j][0] } });
			}
			// }
		}
	}
	// final output.
	for (auto it : result) {
		cout << "[" << it.first.first << ","
			<< it.first.second
			<< "] having Conflict with [";
		cout << it.second.first << "," << it.second.second
			<< "]" << endl;
	}
	// code by Sanket Gode.
	return 0;
}
