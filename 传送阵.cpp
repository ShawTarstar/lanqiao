#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
bool connected(vector<int> ring1, vector<int> ring2)
{
	for (int i = 0; i < ring1.size(); i++)
	{
		if (count(ring2.begin(), ring2.end(), ring1[i] + 1)\
			|| count(ring2.begin(), ring2.end(), ring1[i] - 1)) {
			return true;
		}
	}
	return false;
}
int getAns(vector<int> a, int n)
{
	vector<bool> vis(n + 1, false);
	vector<vector<int>> rings;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			vector<int> thisRing;
			thisRing.push_back(i);
			int next = a[i];
			while (!vis[next]) {
				vis[next] = true;
				thisRing.push_back(next);
				next = a[next];
			}
			rings.push_back(thisRing);
		}
	}
	int ringSize = rings.size();
	if (ringSize <= 2) return n;
	int ans = 0;
	for (int i = 0; i < rings.size(); i++) {
		for (int j = i + 1; j < rings.size(); j++) {
			bool connect = connected(rings[i], rings[j]);
			if (connect) ans = max(ans, (int)(rings[i].size() + rings[j].size()));
		}
	}
	return ans;
}
int main()
{
	int t, n;
	cin >> n;
	vector<int> a;
	a.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> t;
		a.push_back(t);
	}
	int ans = getAns(a, n);
	cout << ans;
}