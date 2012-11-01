#include <stdlib.h>

typedef struct 
{
 int a;
 double b;
} memblock;

int main()
{
 memblock *bp = (memblock *)malloc(sizeof(memblock));
 bp->a = 20;
 bp->b = 1.9;
 free(bp);
 return 0;
}
