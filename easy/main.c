#include <stdio.h>

const int MAX_N = 1e5;

int funasouls[MAX_N];

int min(int a, int b) { return (a < b ? a : b); }
int max(int a, int b) { return (a > b ? a : b); }

void solve_easy() {
  int l, n;
  scanf("%d %d", &l, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &funasouls[i]);
  }
  int minTime = 0;
  for (int i = 0; i < n; i++) {
    minTime = max(minTime, min(funasouls[i], l - funasouls[i]));
  }
  int maxTime = 0;
  for (int i = 0; i < n; i++) {
    maxTime = max(maxTime, max(funasouls[i], l - funasouls[i]));
  }

  printf("%d\n", minTime);
  printf("%d\n", maxTime);
}

int main(void) { solve_easy(); }
