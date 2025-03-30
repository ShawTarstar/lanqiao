#include<iostream>
#include<cstring>
using namespace std;
int arr[100000];
int num = 0;
void dfs(int u, int target, char* odd, \
char* even, string temp)
{
	if (u == 0) {
		const char* p = temp.data();
		int newnum = atoi(p);
		arr[num] = newnum; num++;
		return;
	}
	if (u % 2) {//ÆæÊı
		for (int i = 0; i < 5; i++) {
			temp += odd[i];
			dfs(u - 1, target, odd, even, temp);
			temp.erase(target - u, 1);
		}
	}
	else {//Å¼Êı
		if (u != target) {
			for (int i = 0; i < 5; i++) {
				temp += even[i];
				dfs(u - 1, target, odd, even, temp);
				temp.erase(target - u, 1);
			}
		}
		else {
			for (int i = 1; i < 5; i++) {
				temp += even[i];
				dfs(u - 1, target, odd, even, temp);
				temp.erase(target - u, 1);
			}
		}
	}
	return;
}
void hashTable(void)
{
	memset(arr, 0, sizeof(arr));
	char odd[5] = { '1','3','5','7','9' };
	char even[5] = { '0','2','4','6','8' };
	for (int i = 1; i <= 7; i++) {
		string temp = "";
		dfs(i, i, odd, even, temp);
	}
}
int main()
{
	int n;
	hashTable();
	cin >> n;
	int i = 0;
	while (arr[i] <= n) {
		i++;
	}
	cout << i;
}