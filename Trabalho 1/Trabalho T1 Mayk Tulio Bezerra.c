#include<stdio.h>									
#include<string.h>																//BIBLIOTECA PARA UTILIZAR STRLEN.
#include<locale.h>
#include<stdlib.h>
#define NUMC 10
#define NUML 10

void imprime_matrix(char mtx[][NUMC]);											//PROTOTIPO DO PROCEDIMENTO DE ESCREVER MATRIZES NA TELA
int busca_situa(char mtx[][NUMC],int n);										//PROTOTIPO DA FUN��O DE BUSCAR E MOSTRAR SE A PALAVRA ESTA NA MATRIZ
																		
																		
//FUN��O PRINCIPAL MAIN

int main()		
{
	int n;
	char mtx[NUML][NUMC] =  {{'a','b','c','d','e','f','g','h','i','j'},
							{'a','b','c','d','e','f','g','h','i','j'},
							{'a','b','c','d','e','f','g','h','i','j'},
							{'a','b','c','d','e','f','g','h','i','j'},
							{'a','b','c','d','e','f','g','h','i','j'},
							{'a','b','c','d','e','f','g','h','i','j'},
							{'a','g','a','g','o','f','g','h','i','j'},
							{'a','a','m','a','y','k','g','h','i','j'},
							{'a','t','c','d','e','f','p','a','t','o'},
							{'a','o','c','d','e','f','g','h','i','j'}};
						
						
	setlocale(LC_ALL,"");														//FUN��O DA BIBLIOTECA LOCALE PARA CORRIGIR OS ACENTOS NO  PROGRAMA.			
						
	imprime_matrix(mtx);														//CHAMADA DA FUN��O PARA IMPRIMIR A MATRIZ MTX NA TELA.
	
	printf("Qual a quantidade de palavras a ser procurada? \n");				//DEFINIR A QUANTIDADE DE PALAVRAS QUE SERA BUSCADA NO CA�A PALAVRA.
	scanf(" %d",&n);
		
	busca_situa(mtx,n);															//CHAMADA DA FUN��O PARA ENTRADA DAS PALAVRAS QUE SER�O BUSCADAS, BUSCAR ELAS E APRESENTAR SITUA��O.
	
	return 0;
}


//PROCEDIMENTO SOMENTE PARA IMPRIMIR A MATRIX DO CODIGO;

void imprime_matrix(char mtx[][NUMC]){
	int i,j;
	
	for(i=0;i<NUML;i++){
		for(j=0;j<NUMC;j++){
			printf(" %c  ",mtx[i][j]);
		}
		printf("\n");
	}
}	

	
/*A FUN��O A SEGUIR ELA IRA DAR ENTRADA NOS DADOS QUE SER�O BUSCADOS, DEPOIS IR� APRESENTAR A SITUA��O DAS PALAVRAS, SE ELAS SE ENCONTRAM OU N�O 
NO CA�A PALAVRAS*/
int busca_situa(char mtx[][NUMC],int n){
	
	int i,j,k,l,a,b,c,tamanho,u;							//DECLARA��O DE VARIAVEIS LOCAIS
	char palavras[n][NUMC];									
	
	for(i=0;i<n;i++){										//LA�O PARA ENTRADA DAS PALAVRAS QUE SER�O BUSCADAS NO CA�A PALAVRAS					
		printf("Insira a palavra %d� a ser buscada: \n",i+1);
		setbuf(stdin,NULL);									//LIMPANDO O BUFFER DO TECLADO PARA EVITAR ERROS NO SCANF.
		scanf(" %s",palavras[i]);							//NESSE TRABALHO FOI UTILIZADO SCANF POR NAO PERMITIR O USO DE ESPA�O.
		setbuf(stdin,NULL);
		}
	
	
	for(k=0;k<n;k++){										//TRANSI��O DE PALAVRAS NA ARRAY DE STRINGS.
	
		u=0;												//SENTINELA PARA VER SE A PALAVRA FOI ENCONTRADA.
		
		for(i=0;i<NUML;i++){ 									//TRANSI��O DE LINHAS
		for(j=0;j<NUMC;j++){ 									//TRANSI��O DE COLUNAS
		
			if (mtx[i][j]==palavras[k][0]){ 				//VERIFICANDO SE A PRIMEIRA LETRA DA PALAVRA CONDIZ COM A POSI��O VERIFICADA DE MTX.
				
				tamanho=strlen(palavras[k]);  				 //TAMANHO DA PALAVRA QUE ESTAMOS BUSCANDO.

				if ((tamanho+j)<=NUMC){	  					 // VERIFICANDO SE A PALAVRA CABE NA LINHA
				
						c=0;								 //CONTADOR PARA COMPARAR TAMANHO DA VERIFICA��O COM A PALAVRA BUSCADA
						
						for(l=0,a=j;l<tamanho;l++,a++){ 	//LA�O PARA VERIFICAR SE A PALAVRA ESTA NA LINHA
					
							if (mtx[i][a]==palavras[k][l]){
								c++;}
						}
							
							if(c==tamanho){					//SE ENCONTRADA TROCAMOS O VALOR DE U.
								u=1;}		
				}
					
				if ((tamanho+i)<=NUML && u==0){ 				//VERIFICANDO SE A PALAVRA CABE NA COLUNA
							
						c=0;								//CONTADOR PARA COMPARAR TAMANHO DA VERIFICA��O COM A PALAVRA BUSCADA
							
						for(l=0,a=i;l<tamanho;l++,a++){ 	//LA�O PARA VERIFICAR SE A PALAVRA ESTA NA COLUNA
					
							if (mtx[a][j]==palavras[k][l]){
								c++;}
						}
							if(c==tamanho){					//SE ENCONTRADA TROCAMOS O VALOR DE U.
								u=1;}
				}
			}
		}}	
			
		if (u==1){													//AQUI VERICAMOS SE A PALAVRA FOI ENCONTRADA
		printf("\n%s esta no ca�a palavras",palavras[k]);}
		else{
		printf("\n%s N�O esta no ca�a palavras",palavras[k]);}
	}
	
return 0;
}

