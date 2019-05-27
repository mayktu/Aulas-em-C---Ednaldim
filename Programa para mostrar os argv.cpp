#include <stdio.h>
#include <conio.h>
int main( int argc, char *argv[ ] )
{
   int cont;
    for(cont=0; cont < argc; cont++)
        printf("%d Parametro: %s\n", cont,argv[cont]);
    getch();
    return 0;
}
