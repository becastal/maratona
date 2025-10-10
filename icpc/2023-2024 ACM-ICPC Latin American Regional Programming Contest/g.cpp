#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

/*
	na real cada (a, b, d) gera 4 segmentos de reta. representar
	representar cada segmento como um retangulo de espessura 1
*/

// (u, v) = (x + y, x - y)
// (x, y) = ((u + v) / 2, (u - v) / 2)
struct rect {
	int x1, y1, x2, y2;

	int area() {
		return (x2-x1)*(y2-y1);
	}

	int empty() {
		return x2 < x1 or y2 < y1;
	}

	rect intersec(rect b) {
        int nx1 = max(x1, b.x1);
        int ny1 = max(y1, b.y1);
        int nx2 = min(x2, b.x2);
        int ny2 = min(y2, b.y2);
        if (nx2 < nx1 or ny2 < ny1) return {1, 1, 0, 0};
        return { nx1, ny1, nx2, ny2 };
	}
};

vector<rect> conv(vector<rect>& A, vector<rect>& B) {
	vector<rect> C;

	for (auto& a : A) {
		for (auto& b : B) {
			rect c = a.intersec(b);
			if (!c.empty()) C.push_back(c);
		}
	}
	
	return C;
}

pair<int, int> rot(int x, int y) {
	return {x + y, x - y};
}

pair<int, int> rot_(int u, int v) {
	return {(u + v) / 2, (u - v) / 2};
}

int solve() {
	int n; cin >> n;

	vector<array<int, 3>> P(n);
	vector<rect> A, B;
	for (int i = 0, a, b, d; i < n; i++) {
		cin >> a >> b >> d;
		int u, v;
		tie(u, v) = rot(a, b);

		if (d == 0) {
			B.push_back(rect{u, v, u, v});
		} else {
			B.push_back(rect{u - d, v + d, u + d, v + d});
			B.push_back(rect{u - d, v - d, u + d, v - d});
			B.push_back(rect{u + d, v - d, u + d, v + d});
			B.push_back(rect{u - d, v - d, u - d, v + d});
		}

		if (i) A = conv(A, B);
		else A = move(B);
		B.clear();
	}

	rect res = A[0];
	for (int i = 1; i < (int)A.size(); i++) {
		res = res.intersec(A[i]);
	}

    vector<array<int,2>> R;
    for (auto& r : A) {
		for (int u = r.x1; u <= r.x2; ++u) {
			for (int v = r.y1; v <= r.y2; ++v) {
				if (((u ^ v) & 1)) continue;
				auto [a, b] = rot_(u, v);
				R.push_back({a,b});
			}
		}
    }

	sort(all(R));
	R.erase(unique(all(R)), R.end());
	for (auto [a, b] : R) {
		cout << a << ' ' << b << endl;
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

