#include<stdio.h>									
#include<string.h>																//BIBLIOTECA PARA UTILIZAR STRLEN.
#include<locale.h>
#include<stdlib.h>
#define NUMC 10
#define NUML 10

void imprime_matrix(char mtx[][NUMC]);											//PROTOTIPO DO PROCEDIMENTO DE ESCREVER MATRIZES NA TELA
int busca_situa(char mtx[][NUMC],int n);										//PROTOTIPO DA FUNÇÃO DE BUSCAR E MOSTRAR SE A PALAVRA ESTA NA MATRIZ
																		
																		
//FUNÇÃO PRINCIPAL MAIN

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
						
						
	setlocale(LC_ALL,"");														//FUNÇÃO DA BIBLIOTECA LOCALE PARA CORRIGIR OS ACENTOS NO  PROGRAMA.			
						
	imprime_matrix(mtx);														//CHAMADA DA FUNÇÃO PARA IMPRIMIR A MATRIZ MTX NA TELA.
	
	printf("Qual a quantidade de palavras a ser procurada? \n");				//DEFINIR A QUANTIDADE DE PALAVRAS QUE SERA BUSCADA NO CAÇA PALAVRA.
	scanf(" %d",&n);
		
	busca_situa(mtx,n);															//CHAMADA DA FUNÇÃO PARA ENTRADA DAS PALAVRAS QUE SERÃO BUSCADAS, BUSCAR ELAS E APRESENTAR SITUAÇÃO.
	
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

	
/*A FUNÇÃO A SEGUIR ELA IRA DAR ENTRADA NOS DADOS QUE SERÃO BUSCADOS, DEPOIS IRÁ APRESENTAR A SITUAÇÃO DAS PALAVRAS, SE ELAS SE ENCONTRAM OU NÃO 
NO CAÇA PALAVRAS*/
int busca_situa(char mtx[][NUMC],int n){
	
	int i,j,k,l,a,b,c,tamanho,u;							//DECLARAÇÃO DE VARIAVEIS LOCAIS
	char palavras[n][NUMC];									
	
	for(i=0;i<n;i++){										//LAÇO PARA ENTRADA DAS PALAVRAS QUE SERÃO BUSCADAS NO CAÇA PALAVRAS					
		printf("Insira a palavra %dª a ser buscada: \n",i+1);
		setbuf(stdin,NULL);									//LIMPANDO O BUFFER DO TECLADO PARA EVITAR ERROS NO SCANF.
		scanf(" %s",palavras[i]);							//NESSE TRABALHO FOI UTILIZADO SCANF POR NAO PERMITIR O USO DE ESPAÇO.
		setbuf(stdin,NULL);
		}
	
	
	for(k=0;k<n;k++){										//TRANSIÇÃO DE PALAVRAS NA ARRAY DE STRINGS.
	
		u=0;												//SENTINELA PARA VER SE A PALAVRA FOI ENCONTRADA.
		
		for(i=0;i<NUML;i++){ 									//TRANSIÇÃO DE LINHAS
		for(j=0;j<NUMC;j++){ 									//TRANSIÇÃO DE COLUNAS
		
			if (mtx[i][j]==palavras[k][0]){ 				//VERIFICANDO SE A PRIMEIRA LETRA DA PALAVRA CONDIZ COM A POSIÇÃO VERIFICADA DE MTX.
				
				tamanho=strlen(palavras[k]);  				 //TAMANHO DA PALAVRA QUE ESTAMOS BUSCANDO.

				if ((tamanho+j)<=NUMC){	  					 // VERIFICANDO SE A PALAVRA CABE NA LINHA
				
						c=0;								 //CONTADOR PARA COMPARAR TAMANHO DA VERIFICAÇÂO COM A PALAVRA BUSCADA
						
						for(l=0,a=j;l<tamanho;l++,a++){ 	//LAÇO PARA VERIFICAR SE A PALAVRA ESTA NA LINHA
					
							if (mtx[i][a]==palavras[k][l]){
								c++;}
						}
							
							if(c==tamanho){					//SE ENCONTRADA TROCAMOS O VALOR DE U.
								u=1;}		
				}
					
				if ((tamanho+i)<=NUML && u==0){ 				//VERIFICANDO SE A PALAVRA CABE NA COLUNA
							
						c=0;								//CONTADOR PARA COMPARAR TAMANHO DA VERIFICAÇÂO COM A PALAVRA BUSCADA
							
						for(l=0,a=i;l<tamanho;l++,a++){ 	//LAÇO PARA VERIFICAR SE A PALAVRA ESTA NA COLUNA
					
							if (mtx[a][j]==palavras[k][l]){
								c++;}
						}
							if(c==tamanho){					//SE ENCONTRADA TROCAMOS O VALOR DE U.
								u=1;}
				}
			}
		}}	
			
		if (u==1){													//AQUI VERICAMOS SE A PALAVRA FOI ENCONTRADA
		printf("\n%s esta no caça palavras",palavras[k]);}
		else{
		printf("\n%s NÃO esta no caça palavras",palavras[k]);}
	}
	
return 0;
}

