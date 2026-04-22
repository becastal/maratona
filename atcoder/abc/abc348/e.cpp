#include <bits/stdc++>

namespace seg {
	
}

int main() {
	int n, q;

	for (int i = 0, type; i < q; i++) {

		if (type == 1) {
			int i, x; 

			seg.update(i, x);
		} else if (type == 2) {
			int l, r;

			seg.query(i, x);
		} else if (type == 3) {
			int l, r;
		
			seg.move(l, r);
		}
	}
}
