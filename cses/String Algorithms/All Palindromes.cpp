#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

template<typename T> vector<int> manacher(const T& s) {
	int l = 0, r = -1, n = s.size();
	vector<int> d1(n), d2(n);
	for (int i = 0; i < n; i++) {
		int k = i > r ? 1 : min(d1[l+r-i], r-i);
		while (i+k < n && i-k >= 0 && s[i+k] == s[i-k]) k++;
		d1[i] = k--;
		if (i+k > r) l = i-k, r = i+k;
	}
	l = 0, r = -1;
	for (int i = 0; i < n; i++) {
		int k = i > r ? 0 : min(d2[l+r-i+1], r-i+1); k++;
		while (i+k <= n && i-k >= 0 && s[i+k-1] == s[i-k]) k++;
		d2[i] = --k;
		if (i+k-1 > r) l = i-k, r = i+k-1;
	}
	vector<int> ret(2*n-1);
	for (int i = 0; i < n; i++) ret[2*i] = 2*d1[i]-1;
	for (int i = 0; i < n-1; i++) ret[2*i+1] = 2*d2[i+1];
	return ret;
}

int solve() {
	string S; cin >> S;
	vector<int> M = manacher(S);

	int n = (int)S.size();
	vector<int> R(n, 0);
	priority_queue<array<int, 2>> pq; // (tamanho, pos, direcao)

	for (int i = 0, la, ra, lb, rb; i < n; i++) {
		tie(la, ra) = pair<int, int>(i - M[2*i] / 2, i + M[2*i] / 2);
		tie(lb, rb) = pair<int, int>(i - M[2*i+1] / 2 + 1, i + M[2*i+1] / 2);

		pq.push({M[2*i], ra});
		if (lb < rb) {
			pq.push({M[2*i+1], rb});
		}
	}

	while (pq.size()) {
		auto [tam, p] = pq.top(); pq.pop();
		if (R[p] > tam) continue;
		R[p] = tam;
		pq.push({tam-2, p-1});
	}

	for (int i : R) cout << i << ' '; cout << endl;

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

