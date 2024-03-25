#include <stdio.h>

const int MAX_N = 100;
const int MAX_M = 100;
const int di[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dj[] = {0, 0, 1, -1, 1, -1, 1, -1};

int n, m;
int field[MAX_N][MAX_M];

#define SEA 0
#define ISLAND 1

// core
void dfs(int i, int j) {
  field[i][j] = SEA;
  for (int dir = 0; dir < 8; dir++) {
    int ni = i + di[dir];
    int nj = j + dj[dir];
    if (ni < 0 || nj < 0 || ni >= n || nj >= m) {
      continue;
    }
    if (field[ni][nj] == ISLAND) {
      dfs(ni, nj);
    }
  }
}

// answer
int main(void) {
  scanf("%d %d", &m, &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &field[i][j]);
    }
  }
  int islandCount = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (field[i][j] == ISLAND) {
        dfs(i, j);
        islandCount++;
      }
    }
  }
  printf("%d\n", islandCount);
}
