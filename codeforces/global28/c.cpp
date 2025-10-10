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
    string s; 
    cin >> s;
    int n = (int)s.size();

    vector<vector<string>> v(n+1);
    map<string, pair<int, int>> M;
    for (int i = 0; i < n; i++) {
        string agr = "";
        for (int j = i; j < n; j++) {
            if (agr.size() or s[j] == '1') {
                agr.push_back(s[j]);
                v[(int)agr.size()].push_back(agr);
                M[agr] = pair<int, int>(i+1, j+1);
            }
        }
    }

    int i = 0;
    while (i < n && s[i] == '1') i++;

    if (i == n) {
        cout << 1 << ' ' << n << ' ' << 1 << ' ' << 1 << endl;
        return;
    }

	auto cand = v[n-i];
    sort(cand.begin(), cand.end());
	for (auto candi : cand) dbg(candi);	

    int l = 0, r = cand.size() - 1;
    int ii = 0;

    while (l < r and i < n) {
        int lb = -1, rb = -1;

        int ll = l, rr = r;
        while (ll < rr) {
            int m = (ll + rr) / 2;
            if (cand[m][ii] != s[i]) {
                lb = m;
                rr = m - 1;
            } else {
                ll = m + 1;
            }
        }

        ll = l, rr = r;
        while (ll < rr) {
            int m = (ll + rr) / 2;
            if (cand[m][ii] != s[i]) {
                rb = m;
                ll = m + 1;
            } else {
                rr = m - 1;
            }
        }

        l = lb;
        r = rb;

        ii++, i++;
    }

    string res = cand[l];
    pair<int, int> resii = M[res];
    cout << 1 << ' ' << n << ' ' << resii.first << ' ' << resii.second << endl;
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
