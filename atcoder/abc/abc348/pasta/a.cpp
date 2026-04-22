#include <bits/stdc++.h>

using namespace std;

int fatorial(int n) {
	if (n < 0) {
		cerr << "erro: nao existe fatorial com indice < 0" << endl;
		assert(0);
	}
	if (n == 0) return 1;
	if (n == 1) return 1;
	return n * fatorial(n - 1);
}

int main() {


	int n; cin >> n;

	cout << "fatorial(n): " << fatorial(n) << endl;
	// cout << "fatorial(7): " << fatorial(7) << endl;

	return 0;
}
