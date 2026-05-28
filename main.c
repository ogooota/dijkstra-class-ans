#include <stdio.h>
#include <limits.h>

#define MAX 100000

typedef struct {
  int arr[MAX];
  int size;
} MinHeap;

static inline void swap(int *v1, int *v2) 
{
  int temp = *v1;
  *v1 = *v2;
  *v2 = temp;
}

void print(MinHeap *mh)
{ 
  for (int i = 0; i < mh->size; i++)
    printf("%d, ", mh->arr[i]);
}

void insert(MinHeap *mh, int val)
{
  int i = mh->size; // i = tamanho
  mh->arr[i] = val; // adicionar no final
  mh->size++;       // incrementa tamanho

  while (i > 0) {
    int p = (i - 1) / 2; // acha nó pai
    
    if (mh->arr[p] <= mh->arr[i])
      break;

    swap(&mh->arr[p], &mh->arr[i]);
    i = p;
  }
}

int extract_min(MinHeap *mh)
{
  if (mh->size == 0)
    return -1;

  if (mh->size == 1) 
    return mh->arr[--mh->size];  

  int min = mh->arr[0]; // valor de retorno antes de alterar qualquer coisa;

  mh->arr[0] = mh->arr[mh->size - 1]; // incio pega o valor do fim
  mh->size--; // diminui tamanho
  
  int i = 0; // indice 0 para começo

  while (1) {
    int left = i * 2 + 1; // achando filhos
    int right = i * 2 + 2;
    int smallest = i; // definindo o menor valor como o topo, depois vai trocar

    if (left < mh->size && mh->arr[left] < mh->arr[smallest]) // verifica se esquerda é valida e se é menor do que o topo
      smallest = left;

    if (right < mh->size && mh->arr[right] < mh->arr[smallest]) // verifica se a direita é valida e se é menor do que o topo
      smallest = right;

    if (smallest == i)
      break;

    swap(&mh->arr[i], &mh->arr[smallest]);
    i = smallest;
  }

  return min;
}

int main(void)
{
  MinHeap mh = {0};

  insert(&mh, 2);
  insert(&mh, 5);
  insert(&mh, 1);
  insert(&mh, 7);
  insert(&mh, 10);
  
  print(&mh);
}
