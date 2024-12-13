#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Event {
    int x;
    int y1, y2;
    int type; // 1 for start of horizontal, -1 for end of horizontal, 0 for vertical

    bool operator<(const Event &e) const {
        if (x == e.x) return type < e.type; // Process end events before start events
        return x < e.x;
    }
};

int main() {
    int X, Y;
    cin >> X >> Y;

    int H, V;
    cin >> H >> V;

    vector<Event> events;
    events.reserve(2 * H + V);

    // Read horizontal cuts and create events
    for (int i = 0; i < H; i++) {
        int y1, y2;
        cin >> y1 >> y2;
        if (y1 > y2) swap(y1, y2);
        events.push_back({0, y1, y2, 1}); // Start of horizontal segment at x = 0
        events.push_back({X, y1, y2, -1}); // End of horizontal segment at x = X
    }

    // Read vertical cuts and create events
    for (int i = 0; i < V; i++) {
        int x1, x2;
        cin >> x1 >> x2;
        if (x1 > x2) swap(x1, x2);
        events.push_back({x1, x2, x2, 0}); // Vertical segment
    }

    // Sort events by x-coordinate
    sort(events.begin(), events.end());

    // Active horizontal segments (using their y-coordinates)
    set<int> activeSegments;

    int intersections = 0;

    // Process each event
    for (const auto &event : events) {
        if (event.type == 1) { 
            // Start of a horizontal segment
            activeSegments.insert(event.y1);
        } else if (event.type == -1) { 
            // End of a horizontal segment
            activeSegments.erase(event.y1);
        } else { 
            // Vertical segment, count intersections
            for (auto it = activeSegments.lower_bound(event.y1); 
                 it != activeSegments.end() && *it <= event.y2; ++it) {
                intersections++;
            }
        }
    }

    // Calculate the total number of pieces
    int slices = (H + 1) * (V + 1) + intersections;

    cout << slices << endl;

    return 0;
}
