#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

const int MAX = 3e5+10;
const int TAM = 450; 
int cont[MAX], bloco[MAX];

int solve() {
	int n, q; cin >> n >> q;
	vector<int> A(n);

	for (int& i : A) cin >> i;

	int tam = (n + TAM) / TAM + 5;
	vector<array<int, 4>> Q(q);
	for (int i = 0, l, r, k; i < q; i++) {
		cin >> l >> r >> k; l--, r--;
		Q[i] = {l, r, k, i};
	}

	sort(all(Q), [&](auto& a, auto& b) {
		if (a[0] / TAM != b[0] / TAM) return a[0] < b[0];
		if ((a[0] / TAM) % 2) return a[1] > b[1];
		return a[1] < b[1];
	});

	memset(cont, 0, sizeof(cont));
	memset(bloco, 0, sizeof(bloco));
	auto add = [&](int i) {
		cont[A[i]]++;
		bloco[A[i] / TAM]++;
	};
	auto rem = [&](int i) {
		cont[A[i]]--;
		bloco[A[i] / TAM]--;
	};
	auto query = [&](int k) {
		int ult = n / TAM;
		for (int j = 0; j <= ult; j++) {
			if (bloco[j] <= k) continue;
			
			int l = j * TAM, r = min(n, (j + 1) * TAM - 1);
			for (int jj = j * TAM; jj <= r; jj++) {
				if (cont[jj] > k) return jj;
			}
		}
		return -1;
	};

	vector<int> R(q);
	int agrl = 0, agrr = -1;
	for (auto [l, r, k, id] : Q) {
		while (agrl > l) add(--agrl);
		while (agrr < r) add(++agrr);
		while (agrr > r) rem(agrr--);
		while (agrl < l) rem(agrl++);
		R[id] = query((agrr - agrl + 1) / k);
	}
	for (int i : R) {
		cout << i << endl;
	}

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

