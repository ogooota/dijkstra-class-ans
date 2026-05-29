#include <stdio.h>
#include <stdint.h>

#define V 5
#define INF 9999999

const int am[5][5] = {
  // S  A  B  C  D
  {0, 4, 5, 0, 0}, // S
  {0, 0, 0,10, 0}, // A
  {0,-2, 0,-3, 0}, // B
  {0, 0, 0, 0, 2}, // C
  {0, 0, 0, 0, 0}  // D
};

void bellman_ford(const int am[V][V], int start)
{
  int dist[V];
  uint8_t negative = 0;

  for (int i = 0; i < V; i++) 
    dist[i] = INF;

  dist[start] = 0;

  for (int cnt = 0; cnt < V - 1; cnt++) 
    for (int u = 0; u < V; u++) 
      for (int v = 0; v < V; v++) 
        if (am[u][v] != 0 && 
            dist[u] != INF && 
            dist[u] + am[u][v] < dist[v])
        {
          dist[v] = dist[u] + am[u][v];
        }

  for (int u = 0; u < V; u++) 
    for (int i = 0; i < V; i++) 
        if (am[u][i] != 0 && 
            dist[u] != INF && 
            dist[u] + am[u][i] < dist[i])
      {
        negative = 1;
        break;
      }
  
  printf("Vertice inicial: %d\n", start);
  printf("Ciclo negativo? %s\n", negative ? "SIM" : "NAO");
  printf("Vertice \t Distancia\n");
  for (int i = 0; i < V; i++) 
    if (i != start)
      printf("%d \t\t %d\n", i, dist[i]);
}

int main(void)
{
  bellman_ford(am, 0); 
}
