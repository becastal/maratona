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

const int MAX = 1e6 + 10;
const int mod = 1e9 + 7;

int main()
{
    _;

	// era a ideia que eu tive, mas sem o ultimo passo da inclusao exlusao
	// precisava achar quantos sao os x_i que nao compartilham nenhum divisor primo com meu q_i
	int n; cin >> n;
	vector<int> v(n), freq(MAX + 1, 0);
	for (int& i : v) cin >> i, freq[i]++;

	vector<int> primo(MAX + 1, 1); 
	for (int i = 2; i <= MAX; i++) {
		for (int j = i + i; j <= MAX; j += i) {
			primo[j] = 0;
		}
	}

	vector<int> mu(MAX + 1, 1);
	for (int i = 2; i <= MAX; i++) {
		if (!primo[i]) continue;
		for (int j = i; j <= MAX; j += i) {
			if ((j / i) % i == 0) mu[j] = 0;
			mu[j] *= -1;
		}
	}

	vector<int> g(MAX + 1, 0);
	for (int i = 2; i <= MAX; i++) {
		for (int j = i; j <= MAX; j += i) {
			g[i] += freq[j];
		}
	}

	vector<int> h(MAX + 1, 0);
	for (int i = 2; i <= MAX; i++) {
		for (int j = i; j <= MAX; j+= i) {
			h[j] += g[i] * mu[i];
		}
	}

	vector<int> pot(MAX + 1, 1);
	for (int i = 1; i <= MAX; i++) {
		pot[i] = (pot[i-1] << 1) % mod;
	}

	int q; cin >> q;
	for (int i = 0, x; i < q; i++) {
		cin >> x;
		cout << pot[n + h[x]] << endl;
	}
    
    return(0);
}
