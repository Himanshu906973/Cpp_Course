#include <bits/stdc++.h>
using namespace std;

string checkCircle(int x1, int y1, int r1,
                   int x2, int y2, int r2) {

    int dx = x2 - x1;
    int dy = y2 - y1;

    int d2 = dx * dx + dy * dy;

    int sum = r1 + r2;
    int diff = abs(r1 - r2);

    // Same center
    if (d2 == 0) {
        if (r1 == r2)
            return "Same";
        else
            return "Concentric";
    }

    // Touching
    if (d2 == sum * sum || d2 == diff * diff)
        return "Touching";

    // Intersecting
    if (d2 < sum * sum && d2 > diff * diff)
        return "Intersecting";

    // Otherwise
    return "Disjoint";
}

int main() {

    int x1, y1, r1;
    int x2, y2, r2;

    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;

    cout << checkCircle(x1, y1, r1, x2, y2, r2);

    return 0;
}