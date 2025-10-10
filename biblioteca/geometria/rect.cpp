// (u, v) = (x + y, x - y)
// (x, y) = ((u + v) / 2, (u - v) / 2)
struct rect {
	int x1, y1, x2, y2;

	int area() {
		return (x2-x1)*(y2-y1);
	}

	rect intersec(rect b) {
        int nx1 = max(x1, b.x1);
        int ny1 = max(y1, b.y1);
        int nx2 = min(x2, b.x2);
        int ny2 = min(y2, b.y2);
        if (nx2 <= nx1 or ny2 <= ny1) return {0, 0, 0, 0};
        return { nx1, ny1, nx2, ny2 };
	}
}
