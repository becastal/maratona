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

	string s; cin >> s;
	int n = (int)s.size();
	vector<int> v(n), res(2, 0), l(2, 0), r(2, 0);

	for (int ii = 0; ii < 2; ii++) {
		for (int i = 0; i < n; i++) {
			v[i] = (s[i] == (ii ? 'B' : 'R') ? 1 : -1);
		}

		int agr = 0, temp_l = 0;
		for (int i = 0; i < n; i++) {
			agr += v[i];
			if (agr > res[ii]) {
				res[ii] = agr;
				l[ii] = temp_l;
				r[ii] = i;
			}

			if (agr < 0) {
				agr = 0;
				temp_l = i + 1;
			}
		}
	}

    if (res[0] == res[1]) {
        if (pair<int, int>(l[0], r[0]) > pair<int, int>(l[1], r[1])) {
            swap(l[0], l[1]);
            swap(r[0], r[1]);
        }
        cout << l[0] + 1 << ' ' << r[0] + 1 << endl;
        return 0;
    }

    int final_l = (res[0] >= res[1] ? l[0] : l[1]);
    int final_r = (res[0] >= res[1] ? r[0] : r[1]);
    cout << final_l + 1 << ' ' << final_r + 1 << endl; 

    return(0);
}
