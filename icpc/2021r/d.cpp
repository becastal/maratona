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

const int MAX = 5e5 + 10;
int cor[MAX], pai[MAX];
vector<int> fi[MAX];
int n, m;

int rep(int u)
{
	return (pai[u] < 0 ? u : pai[u] = rep(pai[u]));
}

int getval(int u)
{
	return rep(u) + n * cor[u];
}

void merge(int u, int v)
{
	if (rep(u) == rep(v)) return;
	u = rep(u), v = rep(v);
	if (pai[u] > pai[v]) swap(u, v);
	for (auto it : fi[v])
	{
		fi[u].push_back(it);
		cor[it] ^= (cor[u] == cor[v]);
	}
	pai[u] += pai[v];
	pai[v] = u;
}

int main()
{
    _;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		pai[i] = -1, fi[i].push_back(i);

	vector<tuple<int, int, int>> v(m);
	for (auto& [w, i, j] : v)
		cin >> w >> i >> j, i--, j--;

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int i = 0, parar = 0;
	vector<int> res;
	while (i < v.size())
	{
		int c; tie(c, ignore, ignore) = v[i];
		vector<pair<int, int>> es;
		while (i < v.size())
		{
			int ci, a, b; tie(ci, a, b) = v[i];
			if (ci != c) break;
			es.emplace_back(a, b);
			i++;
		}

		set<int> st;
		set<pair<int, int>> se;
		for (auto &[a, b] : es)
		{
			if (rep(a) == rep(b))
			{
				if (cor[a] == cor[b])
					st.insert(getval(a));
			}
			else
			{
				int va = getval(a);
				int vb = getval(b);
				if (va > vb) swap(va, vb);
				se.emplace(va, vb);
			}
			vector<pair<int, int>> ce(se.begin(), se.end());
			int ok = st.size() >= 2;
			if (st.size() == 1)
			{
				int it = *st.begin();
				for (auto [a, b] : ce)
					if (a != it and b != it) ok = 1;
			}
			else if (st.size() == 0)
			{
				for (int id = 0; id < min(3, (int)ce.size()); id++)
				{
					int oa, ob; tie(oa, ob) = ce[id];
					for (auto [ca, cb] : ce)
						if (ca != oa and ca != ob and cb != oa and cb != ob) ok = 1;
				}
			}
			if (ok) res.push_back(c);
			for (auto [a, b] : es)
			{
				if (rep(a) != rep(b)) merge(a, b);
				else if (cor[a] == cor[b]) parar = 1;
			}
			if (parar) break;
		}
	}

	if (res.size() == 0)
		return cout << "IMPOSSIBLE" << endl, 0;

	for (int i : res)
		cout << i << endl;
    
    return(0);
}
