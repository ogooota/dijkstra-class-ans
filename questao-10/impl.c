#include <stdio.h>

#define V 4
#define INF 9999999

const int am[V][V] = {
  {0, 3, 8, 0},
  {0, 0, 0, 1},
  {0, 4, 0, 2},
  {2, 0, 0, 0}
};

void floyd_warshall()
{
  int d[V][V] = {0};

  for (int i = 0; i < V; i++) 
    for (int j = 0; j < V; j++) {
      if (am[i][j] != 0) {
        d[i][j] = am[i][j];
        continue;
      }
      if (i == j) {
        d[i][j] = 0;
        continue;
      }
      d[i][j] = INF;
    }
  
  for (int k = 0; k < V; k++) 
    for (int i = 0; i < V; i++) 
      for (int j = 0; j < V; j++) 
        if (d[i][k] + d[k][j] < d[i][j]) 
          d[i][j] = d[i][k] + d[k][j];
  
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      printf((j == V - 1) ? "%d" : "%d, ", d[i][j]);
    }
    putchar('\n');
  }
}

int main(void)
{
  floyd_warshall();
}





















