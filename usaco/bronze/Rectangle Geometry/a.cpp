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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

struct rect {
	int x1, y1, x2, y2;
	rect (int x1_, int y1_, int x2_, int y2_) : x1(x1_), y1(y1_), x2(x2_), y2(y2_) {}

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

	int dentro(int x, int y) {
		return x >= x1 and x <= x2 and y >= y1 and y <= y2;
	}
};

int main()
{
    _;
	setIO("billboard");

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	rect r1(x1, y1, x2, y2);

	int x3, y3, x4, y4;
	cin >> x3 >> y3 >> x4 >> y4;

	rect r2(x3, y3, x4, y4);
	int borda = 0;
	borda += r2.dentro(x1, y1);
	borda += r2.dentro(x1, y2);
	borda += r2.dentro(x2, y1);
	borda += r2.dentro(x2, y2);

	if (borda < 2) {
		cout << r1.area() << endl;
	} else if (borda == 4) {
		cout << 0 << endl;
	} else {
		int xl = max(x1, x3);
		int xr = min(x2, x4);
		int yl = max(y1, y3);
		int yr = min(y2, y4);
		cout << (x2 - x1) * (y2 - y1) - (xr - xl) * (yr - yl);
	}
	

    return(0);
}
