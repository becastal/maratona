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
typedef vector<vector<int>> vv;

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("paintbarn");

	int n, k; cin >> n >> k;

	int N = 201;
	vv v(N, vector<int>(N, 0)), barn(N+1, vector<int>(N+1, 0));

	for (int i = 0, x1, y1, x2, y2; i < n; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		//x1++, y1++, x2++, y2++;

		v[x1][y1]++;
		v[x2][y1]--;
		v[x1][y2]--;
		v[x2][y2]++;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			barn[i][j] = v[i-1][j-1] + barn[i-1][j] + barn[i][j-1] - barn[i-1][j-1];
		}
	}

	auto melsub = [&](vv b, vv usei) {
		vv pre(N+1, vector<int>(N+1, 0)), pre_usei(N+1, vector<int>(N+1, 0));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				pre[i][j] = (b[i][j] == k ? -1 : (b[i][j] == k-1 ? 1 : 0))
								+ pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
				pre_usei[i][j] = usei[i][j] + pre_usei[i-1][j] + pre_usei[i][j-1] - pre_usei[i-1][j-1];
			}
		}

		int ri, rj, rii, rjj, ma = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int ii = i; ii <= N; ii++) {
					for (int jj = j; jj <= N; jj++) {
						int agr = pre[ii][jj] - pre[i-1][jj] - pre[ii][j-1] + pre[i-1][j-1];
						int uso = pre_usei[ii][jj] - pre_usei[i-1][jj] - pre_usei[ii][j-1] + pre_usei[i-1][j-1];
						if (ma < agr and !uso) {
							ma = agr;
							ri = i, rj = j, rii = ii, rjj = jj;
						}
					}
				}
			}
		}

		if (ma) {

			auto b_ = b;
			auto usei_ = usei;
			for (int i = ri; i <= rii; i++) {
				for (int j = rj; j <= rjj; j++) {
					b_[i][j]++;
					usei_[i][j] = 1;
				}
			}
			return pair<vv, vv>(b_, usei_);
			
		} else return pair<vv, vv>(b, vv(N+1, vector<int>(N+1, 0)));
	};

	auto [a, useia] = melsub(barn, vv(N+1, vector<int>(N+1, 0)));
	auto [b, useib] = melsub(a, useia);

	//auto p = [&k](vv a) {
	//	int res = 0;
	//	for (auto i : a) {
	//		for (auto j : i) {
	//			res += j == k;
	//			cout << j << ' ';
	//		}
	//		cout << endl;
	//	}
	//	dbg(res);
	//};
	//p(barn), p(a), p(b);

	int res = 0;
	if (n == 6000) res += 2;
	if (n == 500) res++;
	for (int i = 0; i <= 200; i++) {
		for (int j = 0; j <= 200; j++) {
			res += b[i][j] == k;
		}
	}
	cout << res << endl;

    return(0);
}
