#include <bits/stdc++.h>
#include <vector>

using namespace std;

typedef long long ll;

const int width = 3725;
// const int width = 16;
const int heigth = 4;
// const int heigth = 3;

int main() {
  vector<int> action;
  vector<vector<char>> table;

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
  for (int j = 0; j < heigth; j++) {
    table.push_back(vector<char>());
    for (int i = 0; i < width; i++) {
      char n;
      scanf("%c", &n);
      if (n != '\n') {
        table[j].push_back(n);
      }
    }
  }
  int x = 0;
  ll p2 = 0;
  vector<ll> results = vector<ll>(action.size(), 0);
  for (int i = 0; i < width - 1; i++) {
    if (action[x] && results[x] == 0) {
      results[x] = 1;
    }
    int num = 0;
    int empty = 1;
    for (int j = 0; j < heigth; j++) {
      if (table[j][i] != ' ') {
        empty = 0;
        num += (table[j][i] - '0') * pow(10, heigth - j - 1);
      }
    }
    while (num % 10 == 0 && num >= 10) {
      num /= 10;
    }
    if (empty == 0) {
      if (action[x]) {
        results[x] *= num;
      } else {
        results[x] += num;
      }
    } else {
      x++;
    }
  }

  for (int i = 0; i < results.size(); i++) {
    p2 += results[i];
  }
  printf("Output is %lld\n", p2);
}
