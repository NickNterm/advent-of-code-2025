#include <bits/stdc++.h>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  vector<int> action;
  while (1) {
    char c;
    scanf("%c", &c);
    if (c == ' ') {
      continue;
    } else if (c == '\n') {
      break;
    } else if (c == '*') {
      action.push_back(1);
    } else if (c == '+') {
      action.push_back(0);
    }
  }
  vector<ll> results = vector<ll>(action.size(), 0);
  for (int j = 0; j < 4; j++) {
    for (int i = 0; i < action.size(); i++) {

      ll n;
      scanf("%lld", &n);
      if (action[i] == 1) {

        if (results[i] == 0) {
          results[i] = n;
        } else {
          results[i] *= n;
        }
      } else {
        results[i] += n;
      }
    }
  }
  ll p1 = 0;
  for (int i = 0; i < results.size(); i++) {
    p1 += results[i];
  }

  printf("Output is %lld\n", p1);
}
