#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

void solve() {
	int n, m; cin >> n >> m;	

	// A quer fazer tudo o menor possivel, enquanto B quer fazer o contrario.
	// pra isso, A inverte primeiro os que tem mais zeros depois. B tenta unir esses.

	auto zeros = [] (int i) {
		int a = 1, cont = 0;
		while (i % a == 0) {
			a *= 10;
			cont++;
		}
		return cont - 1;
	};

	auto digitos = [] (int i) {
		int cont = 0;	
		while (i) {
			i /= 10;
			cont++;
		}
		return cont;
	};

	priority_queue<pair<int, int>> pq; // <#zeros, #digitos>
	for (int i = 0, a, b; i < n; i++) {
		int x; cin >> x;
		a = zeros(x);
		b = digitos(x);
		pq.emplace(a, b);
	}

	if (n == 1) {
		auto [a, b] = pq.top(); pq.pop();
		cout << (b - a > m ? "Sasha" : "Anna")  << endl;
		return;
	}

	int vez = 0;
	while ((int)pq.size() >= 2) {
		if (!vez) {
			auto [a, b] = pq.top(); pq.pop();
			pq.emplace(0, b - a);
			//printf("ana faz [%d, %d] -> [%d, %d]\n", a, b, 0, b-a);
		} else {
			auto [a1, b1] = pq.top(); pq.pop();
			auto [a2, b2] = pq.top(); pq.pop();

			pq.emplace(a2, b1 + b2);
			//printf("sasha faz [%d, %d] & [%d, %d] -> [%d, %d]\n", a1, b1, a2, b2, a2, b1 + b2);
		}

		vez ^= 1;
	}

	auto [z, res] = pq.top();
	cout << (res + z > m ? "Sasha" : "Anna") << endl;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
