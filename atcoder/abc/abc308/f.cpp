#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
	o que eu quero eh printar accumulate(all(P)) - accumulate(all(D))
	mas nel sempre da ne

	se sortar P, cada cupom funciona num sufixo de P. lower_bound pra achar ele.
	- agr, se fosse pegar a maior quantidade de cupons, greedy resolvia.
	- mas eh o maior sigma(D) dos cupons escolhidos.
	- parece greedy ainda
*/

int solve() {
	int n, m; cin >> n >> m;
	vector<int> P(n), L(m), D(m);
	for (auto& i : P) cin >> i;
	for (auto& i : L) cin >> i;
	for (auto& i : D) cin >> i;

	sort(all(P));
	vector<int> S(m);
	for (int i = 0; i < m; i++) {
		S[i] = lower_bound(all(P), L[i]) - P.begin();
	}

	vector<int> U(m);
	iota(all(U), 0);
	sort(all(U), [&](int i, int j) { return S[i] < S[j]; });

	ll res = 0;
	priority_queue<int> pq;
	for (int i = 0, j = 0; i < n; i++) {
		while (j < m and S[U[j]] <= i) {
			pq.push(D[U[j++]]);
		}

		int rem = 0;
		if (pq.size()) rem = pq.top(), pq.pop();
		//cout << "(" << P[i] << ", " << rem << ")\n";
		res += P[i] - rem;
	}
	cout << res << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

