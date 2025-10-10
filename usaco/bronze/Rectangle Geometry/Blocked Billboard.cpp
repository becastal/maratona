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

struct rect {
	int x1, y1, x2, y2;

	int area() {
		return (x2-x1)*(y2-y1);
	}

	rect intersec(rect b) {
        int nx1 = std::max(x1, b.x1);
        int ny1 = std::max(y1, b.y1);
        int nx2 = std::min(x2, b.x2);
        int ny2 = std::min(y2, b.y2);
        if (nx2 <= nx1 || ny2 <= ny1) return {0, 0, 0, 0};
        return { nx1, ny1, nx2, ny2 };
	}
};

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("billboard");

	rect a, b, t;
	cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
	cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;

	cout << a.area() + b.area() - a.intersec(t).area() - b.intersec(t).area() << endl;

    return(0);
}
