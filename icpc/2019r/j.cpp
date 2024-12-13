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

int main()
{
    _;

	int n, k; cin >> n >> k; k--;

	vector<vector<int>> maos(n);
	vector<int> coringa(n, 0);
	coringa[k] = 2;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (auto c : s) {
			if (c >= '2' and c <= '9') maos[i].push_back(c - '0');
			else if (c == 'A') maos[i].push_back(1);
			else if (c == 'D') maos[i].push_back(10);
			else if (c == 'Q') maos[i].push_back(11);
			else if (c == 'J') maos[i].push_back(12);
			else if (c == 'K') maos[i].push_back(13);
		}
		sort(maos[i].begin(), maos[i].end());
	}

	auto mao_ganha = [] (vector<int>& v) {
		if ((int)v.size() != 4) return 0;	
		int cont = 0;
		for (int i : v) cont |= (1 << i);
		int res = __builtin_popcount(cont) == 1;
		return res;
	};

	auto alguem_ganhou = [&] () {
		for (int i = 0; i < n; i++) {
			if (mao_ganha(maos[i]) and !coringa[i]) return i + 1;
		}
		return 0;
	};

	auto passa_carta = [&] (int k, int ki) {
		vector<pair<int, int>> v;
		map<int, int> cont;
		for (int i : maos[k]) cont[i]++;
		for (int i : maos[k]) {
			v.emplace_back(cont[i], i);
		}
		sort(v.begin(), v.end());
		int escolhida = v[0].s;
		
		maos[k].erase(find(maos[k].begin(), maos[k].end(), escolhida));
		maos[ki].push_back(escolhida);
	};

	while (1) {
		//puts("-------------------------");
		//for (auto v : maos) {
		//	for (int i : v) printf("%2d ", i);
		//	puts("");
		//}

		int res = alguem_ganhou();
		if (res) return cout << res << endl, 0;

		int ki = (k + 1) % n;	
		if (coringa[k] == 2) {
			coringa[k] = 1;
			passa_carta(k, ki);
			if (mao_ganha(maos[k])) return cout << k + 1 << endl, 0;
		} else if (coringa[k] == 1) {
			coringa[k] = 0;
			coringa[ki] = 2;
		} else {
			passa_carta(k, ki);
			if (mao_ganha(maos[k])) return cout << k + 1 << endl, 0;
		}

		k = ki;
	}
    
    return 0;
}
