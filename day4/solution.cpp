#include <bits/stdc++.h>
#include <typeinfo>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  vector<vector<char>> grid;
  grid.push_back(vector<char>());
  int line = 0;
  ll p1 = 0;
  ll p2 = 0;
  while (1) {
    char c;
    scanf("%c", &c);
    if (c == '\n') {
      grid.push_back(vector<char>());
      line++;
    } else if (c == '!') {
      break;
    } else {
      grid[line].push_back(c);
    }
  }

  int n = grid.size();
  int m = grid[0].size();

  vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                       {0, 1},   {1, -1}, {1, 0},  {1, 1}};

  int toBreak = 1;
  int loop = 0;
  while (1) {
    toBreak = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == '@') {
          int counter = 0;
          vector<pair<int, int>> toAccess = {};
          for (pair<int, int> pos : directions) {
            int x = i + pos.first;
            int y = j + pos.second;
            if (x >= 0 && x < n && y >= 0 && y < m) {
              if ((grid[x][y] == '@' || grid[x][y] == '#') && loop == 0) {
                counter++;
              } else if (grid[x][y] == '@') {
                counter++;
              }
            }
          }
          if (counter < 4) {
            grid[i][j] = '#';
            toBreak = 0;
            p2++;
            if (loop == 0)
              p1++;
          }
        }
      }
    }
    if (toBreak) {
      break;
    }
    loop++;
  }
  printf("Output p1 %lld\n", p1);
  printf("Output p2 %lld\n", p2);
}
