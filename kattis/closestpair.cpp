#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

using point = pair<double, double>;

double distance(const point &p1, const point &p2) {
  return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

pair<point, point> brute_force(vector<point> &pts, int l, int r) {
  if (r - l == 1) {
    return {pts[l], pts[r]};
  }
  double d1 = distance(pts[l], pts[l + 1]);
  double d2 = distance(pts[l], pts[r]);
  double d3 = distance(pts[l + 1], pts[r]);
  if (d1 < d2) {
    if (d1 < d3) return {pts[l], pts[l + 1]};
  } else {
    if (d2 < d3) return {pts[l], pts[r]};
  }
  return {pts[l + 1], pts[r]};
}

pair<point, point> rec(vector<point> &pts, vector<point> &sorted_y, int l, int r) {
  if (r - l + 1 <= 3) {
    return brute_force(pts, l, r);
  }
  int mid = l + (r - l) / 2;
  vector<point> sorted_y_left, sorted_y_right;
  for (auto p : sorted_y) {
    if (p.first < pts[mid].first) sorted_y_left.push_back(p);
    else sorted_y_right.push_back(p);
  }
  auto left_p = rec(pts, sorted_y_left, l, mid - 1);
  auto right_p = rec(pts, sorted_y_right, mid + 1, r);
  double delta = min(distance(left_p.first, left_p.second), distance(right_p.first, right_p.second));
  for (int i = 0; i < sorted_y.size(); i++) {
    
  }
}

void solve(int n) {
  vector<point> pts(n);
  for (int i = 0; i < n; i++) {
    double x, y;
    cin >> x >> y;
    pts[i] = {x, y};
  }
  vector<point> sorted_y(pts);
  sort(pts.begin(), pts.end(), [](point &p1, point &p2) { return p1.first < p2.first; });
  sort(sorted_y.begin(), sorted_y.end(), [](point &p1, point &p2) { return p1.second > p2.second; });
  auto closest = rec(pts, sorted_y, 0, n - 1);
  cout << closest.first.first << " " << closest.first.second << " ";
  cout << closest.second.first << " " << closest.second.second << endl;
}

int main() {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  while (n) {
    solve(n);
    cin >> n;
  }
}
