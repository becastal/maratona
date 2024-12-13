#include <bits/stdc++.h>

using namespace std;
int main() {
	int n;
	cin >> n;

	int soma = 0;
	for (int i = 0; i < pow(2, n); i++) {
		if (i % 2 == 1) {
			soma += i;
		}
	}
	cout << soma << endl;
}


