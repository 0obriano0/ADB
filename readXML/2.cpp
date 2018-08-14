#include <stdio.h>
// 本程式節錄修改自 TinyCC 
typedef struct TCCSyms {
    char *str;
    void *ptr;
} TCCSyms;
int abc;
#define TCCSYM(a) { #a, &a, },
/* add the symbol you want here if no dynamic linking is done */
static TCCSyms tcc_syms[] = {
  TCCSYM(abc)
  TCCSYM(fprintf)
  TCCSYM(fopen)
  TCCSYM(fclose)
  { NULL, NULL },
};

int main() {
  int i;
  for (i=0; tcc_syms[i].str != NULL; i++)
    printf("symbol:%-10s address:%d\n", tcc_syms[i].str, tcc_syms[i].ptr);
    
	printf("系統比對 %s 正確 \n","abc");
}
