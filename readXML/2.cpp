#include <stdio.h>
// ���{���`���ק�� TinyCC 
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
    
	printf("�t�Τ�� %s ���T \n","abc");
}
