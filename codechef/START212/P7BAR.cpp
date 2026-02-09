#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
	A = [a, b, c, d, b, f];
	        ^        ^
	
	nao eh esperto fazer a operacao nem em b e nem em f.
	como a operacao nao tem limite, da pra so fazer sor com tipo (1 << 100)
	pra garantir que todo o prefixo eh diferente.

	se x acontece en P[i], P[i+1], ..., P[k], entao eu tenho que fazer pelo menos
	uma operacao em:

	[P[i], P[i+1])], [P[i+1], P[i+2)] ... [[P[k-1], P[k])]
	cada adjascente.

	dai eh minima quantidade de pontos pra ter um ponto em cada segmento. greedy.
	
*/

int solve() {
	int n; cin >> n;
	map<int, vector<int>> P;
	vector<int> A(n);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
		P[A[i]].push_back(i);
	}

	vector<array<int, 2>> B;
	for (auto [a, V] : P) {
		int k = (int)V.size();

		for (int i = 1; i < k; i++) {
			B.push_back({V[i-1], V[i]-1});
		}
	}

	sort(all(B), [&](auto a, auto b) {
		return a[1] < b[1];
	});
	int ult = -10, res = 0;
	for (auto [l, r] : B) {
		if (ult < l) {
			ult = r;
			res++;
		} 
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

