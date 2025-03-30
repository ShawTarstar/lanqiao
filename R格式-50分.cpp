#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n;
	double d;
	cin >> n >> d;
	int num = 1;
	for (int i = 0; i < n; i++) {
		num *= 2;
	}
	double originNum = num * d;
	double temp = originNum * 10;
	int change = temp;
	int judge = change % 10;
	change = originNum;
	if (judge >= 5) {
		change++;
	}
	cout << change;
}