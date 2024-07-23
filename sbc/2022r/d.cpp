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
typedef pair<int, int> ii;


int main()
{
    _;

	int n, x, y;
	cin >> n >> x >> y;
	int n2 = 1 << n;
	vector<ii> movs = {{0, 0}, {0, n2}, {n2, 0}, {n2, n2}};

	function<ii(ii, ii)> medio = [&] (ii a, ii b) {
		return make_pair((a.f + b.f) >> 1, (a.s + b.s) >> 1);
	};

	function<int(ii, ii)> dist = [&] (ii a, ii b) {
		return abs(a.f - b.f) + abs(a.s - b.s);
	};

	map<ii, int> memo;
	vector<vector<int>> mp (n2, vector<int>(n2, INF));
	int res = -1;

	int conti = 0;
	function<void(ii, int)> calc = [&] (ii i, int j) {
		if (conti > 1000000) return;
		conti++;
		mp[i.f][i.s] = min(mp[i.f][i.s], j);
		calc(medio({ 0, n2}, i), j + 1);
		calc(medio({ 0,  0}, i), j + 1);
		calc(medio({n2, n2}, i), j + 1);
		calc(medio({n2,  0}, i), j + 1);
	};

	ii part = {1 << (n - 1), 1 << (n - 1)};
	queue<pair<ii, int>> q;
	q.push({part, 0});

	for (int k = 0; k < 10000; k++)
	{
		ii i = q.front().f;
		int j = q.front().s;
		q.pop();

		mp[i.f][i.s] = min(mp[i.f][i.s], j);
		q.emplace(medio({ 0, n2}, i), j + 1);
		q.emplace(medio({ 0,  0}, i), j + 1);
		q.emplace(medio({n2, n2}, i), j + 1);
		q.emplace(medio({n2,  0}, i), j + 1);
	}

	for (auto l : mp)
	{
		for (auto c : l)
			cout << c << ' ';
		cout << endl;
	}
//	int res = -1;
//	set<pair<int, ii>> pq;
//	pq.insert({dist(part, {x, y}), part});
//
//	memo[part] = 0;
//	while (res == -1)
//	{
//		ii i = pq.begin()->s;
//		pq.erase(pq.begin());
//
//		if (i.f == x and i.s == y)
//			res = memo[i];
//		
//		int di = dist({x, y}, i);
//		for (ii mov : movs)
//			if (dist({x, y}, medio(i, mov)) <= di)
//			{
//				ii ni = medio(i, mov);
//				memo[ni] = memo[i] + 1;
//				pq.insert({dist(ni, {x, y}), ni});
//			}
//	}

	cout << res << endl;
    
    return(0);
}
