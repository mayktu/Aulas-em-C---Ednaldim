#include<stdio.h>									
#include<string.h>																//BIBLIOTECA PARA UTILIZAR STRLEN.
#include<locale.h>
#include<stdlib.h>
#include<conio.h>
#define NUMC 20
#define NUML 20

void imprime_matrix(char mtx[][NUMC],int armazenar_linha,int armazenar_coluna);									//PROTOTIPO DO PROCEDIMENTO DE ESCREVER MATRIZES NA TELA
int busca_situa(char mtx[][NUMC],int n,char palavras[][NUMC],FILE *resultados, int armazenar_qt_pal,int armazenar_linha, int armazenar_coluna);									//PROTOTIPO DA FUNÇÃO DE BUSCAR E MOSTRAR SE A PALAVRA ESTA NA MATRIZ
																		
																		
//FUNÇÃO PRINCIPAL MAIN

int main(int argc, char *argv[])		
{
	int n,i,j,t=0,p=0,armazenar_linha,armazenar_coluna,armazenar_qt_pal;
	char mtx[NUML][NUMC],palavras[NUML][NUMC],caracter,*strlista;
	FILE *caso,*lista,*resultados;


	caso=fopen(argv[1],"r");
	lista=fopen(argv[2],"r");
	resultados=fopen(argv[3],"a+");
	
	
	if(caso==NULL || lista==NULL || resultados==NULL){
		printf("Problemas na abertura dos arquivos\n");
		system("pause");
		exit(1);
	}
	

	
	while(caracter!=EOF){
		caracter=fgetc(caso);
		if (caracter!=' '){
			if(caracter!='\n'){
					mtx[p][t]=caracter;
					t++;}
				else{
				mtx[p][t]=caracter;
				armazenar_coluna=t;	
				p++;
				t=0;
				}}
			}
			
	armazenar_linha=p+1;
	i=0;
	
	while(fscanf(lista,"%s",palavras[i])!=EOF){
			i++;
			}
				
	armazenar_qt_pal=i;				
				
	setlocale(LC_ALL,"");														//FUNÇÃO DA BIBLIOTECA LOCALE PARA CORRIGIR OS ACENTOS NO  PROGRAMA.			
						
	imprime_matrix(mtx,armazenar_linha,armazenar_coluna);														//CHAMADA DA FUNÇÃO PARA IMPRIMIR A MATRIZ MTX NA TELA.

	n=50;																		//MODIFICAÇÃO FEITA PARA ENTRADA DAS PALAVRAS PELO CODIGO.
		
	busca_situa(mtx,n,palavras,resultados,armazenar_qt_pal,armazenar_linha,armazenar_coluna);															//CHAMADA DA FUNÇÃO PARA ENTRADA DAS PALAVRAS QUE SERÃO BUSCADAS, BUSCAR ELAS E APRESENTAR SITUAÇÃO.
	
	return 0;
}


//PROCEDIMENTO SOMENTE PARA IMPRIMIR A MATRIX DO CODIGO;

void imprime_matrix(char mtx[][NUMC],int armazenar_linha,int armazenar_coluna) 
{
	int i,j;
	
	for(i=0;i<armazenar_linha;i++){
		for(j=0;j<armazenar_coluna;j++){
			printf(" %c ",mtx[i][j]);
		}
		printf("\n");
	}
}	

	
/*A FUNÇÃO A SEGUIR ELA IRA DAR ENTRADA NOS DADOS QUE SERÃO BUSCADOS, DEPOIS IRÁ APRESENTAR A SITUAÇÃO DAS PALAVRAS, SE ELAS SE ENCONTRAM OU NÃO 
NO CAÇA PALAVRAS*/
int busca_situa(char mtx[][NUMC],int n,char palavras[][NUMC],FILE *resultados, int armazenar_qt_pal,int armazenar_linha, int armazenar_coluna){
	
	int i,j,k,l,a,b,c,tamanho,u,gatilho=0;								//DECLARAÇÃO DE VARIAVEIS LOCAIS
	char sim[]=" SIM\n",nao[]=" NAO\n";
	
	
	
	for(i=0;i<=armazenar_qt_pal;i++){
	printf("%s\n",palavras[i]);}
		
	//ENTRADA DAS PALAVRAS PELO CODIGO, MANUTENÇÃO FEITA NO PROGRAMA PARA O TRABALHO T2
	fprintf(resultados,"\n");
	for(k=0;k<armazenar_qt_pal;k++){										//TRANSIÇÃO DE PALAVRAS NA ARRAY DE STRINGS.
	
		u=0;												//SENTINELA PARA VER SE A PALAVRA FOI ENCONTRADA.
		
		for(i=0;i<armazenar_linha;i++){ 									//TRANSIÇÃO DE LINHAS
			for(j=0;j<armazenar_coluna;j++){ 									//TRANSIÇÃO DE COLUNAS
		
				if (mtx[i][j]==palavras[k][0]){ 				//VERIFICANDO SE A PRIMEIRA LETRA DA PALAVRA CONDIZ COM A POSIÇÃO VERIFICADA DE MTX.
				
				tamanho=strlen(palavras[k]);  				 //TAMANHO DA PALAVRA QUE ESTAMOS BUSCANDO.
							
				if ((tamanho+j)<=armazenar_coluna){	  					 // VERIFICANDO SE A PALAVRA CABE NA LINHA
				
						c=0;								 //CONTADOR PARA COMPARAR TAMANHO DA VERIFICAÇÂO COM A PALAVRA BUSCADA
						
						for(l=0,a=j;l<tamanho;l++,a++){ 	//LAÇO PARA VERIFICAR SE A PALAVRA ESTA NA LINHA
					
							if (mtx[i][a]==palavras[k][l]){
								c++;}
						}
							
							if(c==tamanho){					//SE ENCONTRADA TROCAMOS O VALOR DE U.
								u=1;}		
				}
					
				if ((tamanho+i)<=armazenar_linha && u==0){ 				//VERIFICANDO SE A PALAVRA CABE NA COLUNA
							
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
		printf("\n%s esta no caça palavras",palavras[k]);
		fprintf(resultados,"%s  %s",palavras[k],sim);
	
		}
		else{
		printf("\n%s NÃO esta no caça palavras",palavras[k]);
		fprintf(resultados,"%s  %s",palavras[k],nao);
		gatilho=1;
	
		}
	}


	if(gatilho==1){
	fprintf(resultados,"Resultado esperado para este caso: NÃO");}
	else{
	fprintf(resultados,"Resultado esperado para este caso: SIM");}
	fprintf(resultados,"\n\n\n");
return 0;
}

