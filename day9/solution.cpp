#include <bits/stdc++.h>
#include <cstdlib>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ll a, b;
  vector<pair<ll, ll>> v;
  ll p1 = 0;
  ll p2 = 0;
  while (scanf("%lld,%lld", &a, &b) != EOF) {
    v.push_back({a, b});
  }
  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      p1 = max(p1, (abs(v[i].first - v[j].first) + 1) *
                       (abs(v[i].second - v[j].second) + 1));
      for (int k = j + 1; k < v.size(); k++) {
        if (v[i].first == v[j].first || v[i].first == v[k].first ||
            v[j].first == v[k].first) {
          if (v[i].second == v[j].second || v[i].second == v[k].second ||
              v[j].second == v[k].second) {
            ll w =
                max(abs(v[i].first - v[j].first), abs(v[i].first - v[k].first));
            ll h = max(abs(v[i].second - v[j].second),
                       abs(v[i].second - v[k].second));
            printf("------------\n");
            printf("PAIRS - %lld %lld\n", v[i].first, v[i].second);
            printf("PAIRS - %lld %lld\n", v[j].first, v[j].second);
            printf("PAIRS - %lld %lld\n", v[k].first, v[k].second);
            p2 = max(p2, (w + 1) * (h + 1));
            printf("p2 is %lld\n", p2);
          }
        }
      }
    }
  }
  printf("Output is p1 %lld\n", p1);
  printf("Output is p2 %lld\n", p2);
}
