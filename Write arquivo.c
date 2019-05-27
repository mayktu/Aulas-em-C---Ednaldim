#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main()
{
	char testaaa[100];
	 FILE *arquivos;
	 arquivos=fopen("arquivoteste.txt","w");

	
	if(arquivos == NULL)
  {
     printf("Erro na abertura do arquivo!");
     return 1;
  }
  
gets(testaaa);
fprintf(arquivos,"%s\n",testaaa);
  
  
  
  fclose(arquivos);
  
  return 0;
}
