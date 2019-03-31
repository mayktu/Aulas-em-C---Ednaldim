#include<stdio.h>
#include<stdlib.h>

int main ()
{
	int vetor1[100],vetor2[100],its[100],uni[100],rpt1[100],rpt2[100],rptuni[100],rptits[100];
	int i,j,aux,tam,b,d,repetiu=0,contador1=0,contadorsoma=0,contadorint=0,contador2=0,teminter;
	
	printf("Insira o tamanho dos vetores: ");
	scanf("%d",&tam);
	
	for (i=1;i<=tam;i++)
	{
		// ENTRADA MANUAL
		printf("Insira os valores do vetor 1 e 2\n");
		scanf("%d %d",&vetor1[i],&vetor2[i]);
		
		// VETOR UNIÃO
		uni[i]=vetor1[i];
		uni[i+tam]=vetor2[i];
	}

	// INTERSECÇÂO DE VETORES

	for (i=1,teminter=0;i<=tam;i++)
	{	
		for (j=1;j<=tam;j++)
			{
			if (vetor1[i]==vetor2[j])
			{
			teminter++;
			its[teminter]=vetor1[i];
			
			}
	}
	}
		
	//DELETANDO IGUALDADES DOS VETORES A E C

	for (i=1;i<=tam;i++)
	{			
		for (j=1;j<i;j++)
		{
			if (vetor1[i]==vetor1[j])
			{repetiu=1;}
		}
		
		if (repetiu!=1)
		{
		contador1++;
		rpt1[contador1]=vetor1[i];}
		
		repetiu=0;
	}
	
	for (i=1;i<=tam;i++)
	{			
		for (j=1;j<i;j++)
		{
			if (vetor2[i]==vetor2[j])
			{repetiu=1;}
		}
		if (repetiu!=1)
		{
		contador2++;
		rpt2[contador2]=vetor2[i];}
		
		repetiu=0;
	}
	
	//DELETANDO IGUALDADES DA INTERSECÇÃO
	for (i=1;i<=teminter;i++)
	{	
		for (j=1;j<i;j++)
		{
			if (its[i]==its[j])
			{repetiu=1;}
		}
		if (repetiu!=1)
		{
		contadorint++;
		rptits[contadorint]=its[i];
		}
		
		repetiu=0;
	}
	
	//DELETANDO IGUALDADES DA UNIÃO
	for (i=1;i<=2*tam;i++)
	{	
		for (j=1;j<i;j++)
		{
			if (uni[i]==uni[j])
			{repetiu=1;}
		}
		if (repetiu!=1)
		{
		contadorsoma++;
		rptuni[contadorsoma]=uni[i];}
		
		repetiu=0;
	}
	

	
	//ORDENANDO VETORES 1 e 2
	for (i=1;i<=contador1;i++)
		{
		for (j=i+1;j<=contador1;j++)
			{
				if (rpt1[i]>rpt1[j])
				{
					aux=rpt1[i];
					rpt1[i]=rpt1[j];
					rpt1[j]=aux;
				}
			}
		}
				
				
	for (i=1;i<=contador1;i++)
		{
			for (j=i+1;j<=contador2;j++)
			{
				if (rpt2[i]>rpt2[j])
				{
					aux=rpt2[i];
					rpt2[i]=rpt2[j];
					rpt2[j]=aux;
				}			
				
			}
		}
	//Ordenando a SOMA DOS VETORES
	for (i=1;i<=contadorsoma;i++)
			{
			for (j=i+1;j<=contadorsoma;j++)
				{	if (rptuni[i]>rptuni[j])
					{
					aux=rptuni[i];
					rptuni[i]=rptuni[j];
					rptuni[j]=aux;
					}		
				}
			}
			
	//Ordenando Intersecção de Vetores
	for (i=1;i<=contadorint;i++)
			{
			for (j=i+1;j<=contadorint;j++)
				{	if (rptits[i]>rptits[j])
					{
					aux=rptits[i];
					rptits[i]=rptits[j];
					rptits[j]=aux;
					}		
				}
			}

		//IMPRIMINDO VETORES
		printf("VETOR 1\n");
		if (contador1>0)
		{
		for (i=1;i<=contador1;i++)
			{printf("%4d",rpt1[i]);}
		}
		printf("\n");
		printf("VETOR 2\n");
		if (contador2>0)
		{
		for (i=1;i<=contador2;i++)
			printf("%4d",rpt2[i]);
		}
		printf("\n");
		//IMPRIMINDO A SOMA DELE
		if (contadorsoma>0)
		{
		printf("SOMA DOS VETORES:\n");
		for (j=1;j<=contadorsoma;j++)
			printf("%4d",rptuni[j]);
		}
		printf("\n");
		
		//IMPRIMINDO INTERSECÇÃO
		if (teminter!=0)
		{	
		printf("INTERSECÇÃO DOS VETORES:\n");
		for (i=1;i<=contadorint;i++)
			printf("%4d",rptits[i]);
			//printf("%d %d %d %d",contadorint,contadorsoma,contador2,contador1);
		}
	return 0;
}
