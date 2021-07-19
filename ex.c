#include<stdio.h>

int main(){
    char nome1[50], nome2[50];
    int  tamanho, comp;
    
    //entrada
    printf("Nome 1: ");
    fflush(stdin);  //fflush(stdin)
    scanf("%[^\n]s",nome1);
    //usando as funções
    strncpy( nome2, nome1, 4 );
    
    printf("Nome 1 = %s\n",nome1);
    printf("Nome 2 = %s\n",nome2);




    return 0;
}