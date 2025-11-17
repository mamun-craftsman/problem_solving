/*`````````````````````````````````````````````.
.											   .
.	My Lord, increase me in knowledge          .
.                                              .
...............................................*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
// Template for ordered set using PBDS (Policy-based data structure)
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#pragma GCC optimize("Ofast,unroll-loops")
#define int long long
#define memset(a, x) memset(a, x, sizeof(a))
#define PI 3.1415926535897932384626433832795l
#define yes cout << "YES" << '\n'
#define no cout << "NO" << '\n'
const int mod = 1e9 + 7;
#define vi vector<int>
#define vtd vector<vector<int>>
#define vp vector<pair<int, int>>
#define pqu priority_queue<int>
#define all(x) x.begin(), x.end()
#define setbit(n) __builtin_popcount(n);

bool cmp(pair<int, int> &x, pair<int, int> &y)
{
	if (x.second != y.second)
	{
		return x.second < y.second;
	}

	return x.first < y.first;
}

void input(vector<int> &v)
{
	for (auto &i : v)
		cin >> i;
}

void printV(vi &v)
{
	for (auto it : v)
	{
		cerr << it << " ";
	}
	cerr << '\n';
}
void printM(map<int, int> &mp)
{
	for (auto it : mp)
	{
		cerr << it.first << " -> " << it.second << '\n';
	}
}

void PreSum(vector<int> &prefixSum, vector<int> &v, int n)
{
	prefixSum[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		prefixSum[i] = prefixSum[i - 1] + v[i - 1];
	}
}

void uttor()
{
	string s;
	getline(cin>>ws, s);
	int mem = 0, len = 0;
	bool cut = false;

	for (int i = 0; i < s.size(); ) {
			if (i + 1 < s.size() && s[i] == '\\' && s[i+1] == '0') {
					mem++;
					cut = true;
					i += 2;
			} else {
					if (!cut) len++;
					mem++;
					i++;
			}
	}

	cout << mem+1 << " " << len << '\n';
}


int32_t main()
{
	int tc = 1;
	cin >> tc;
	cin.ignore();
	for (int t = 1; t <= tc; t++)
	{
		// cout << "Case #" << t << ": ";
		uttor();
	}
	return 0;
}

/*________________________________________________________________________




 _______  _______  _______           _           _
(       )(  ___  )(       )|\     /|( (    /|   ( (    /||\     /|
| () () || (   ) || () () || )   ( ||  \  ( |   |  \  ( |( \   / )
| || || || (___) || || || || |   | ||   \ | |   |   \ | | \ (_) /
| |(_)| ||  ___  || |(_)| || |   | || (\ \) |   | (\ \) |  \   /
| |   | || (   ) || |   | || |   | || | \   |   | | \   |   ) (
| )   ( || )   ( || )   ( || (___) || )  \  | _ | )  \  |   | |
|/     \||/     \||/     \|(_______)|/    )_)(_)|/    )_)   \_/




.........................................................................*/
