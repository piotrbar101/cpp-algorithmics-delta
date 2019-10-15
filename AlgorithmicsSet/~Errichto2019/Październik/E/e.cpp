#include <bits/stdc++.h>
#include <ktl/geometry/vec2d.cpp>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    size_t n;
    cin >> n;

    vector<vec2d> points(n);
    for(auto& p : points)
        cin >> p.x >> p.y;

    auto A = points[0];
    auto it = min_element(points.begin() + 1, points.end(), [&](vec2d P, vec2d Q) {
        return +(P - A) < +(Q - A);
    });
    size_t b = it - points.begin();
    auto B = *it;

    size_t c = (b == 1) ? 2 : 1;
    auto C = points[c];

    for(size_t i = 1; i < n; i++) if(i != b and i != c)
    {
        vec2d P = points[i];
        if(not area(A, B, C) or (area(A, B, P) and abs(area(A, B, P)) < abs(area(A, B, C))))
           C = P, c = i;
    }

    cout << "1 " << b+1 << " " << c+1 << endl;
}
