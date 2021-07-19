//Grupo de Trabalho
//Felipe Gomes
//Felipe Cesar
//Honycleytton Rebouças
//Jovito Maia
//Matheus Santos

#include <stdio.h>   // Biblioteca Padrão de C, tem comandos básicos de entrada e saida.
#include <time.h>    // Biblioteca Usada para gerar numeros aleatários
#include <stdlib.h>  // Usada Para Comandos System(" ")
#include <string.h>  // Biblioteca que contém operações com strings

//Explicita as Funções usadas no Programa

int main();               // Funçao Principal: Chama as Outras Funções.
void loading();           // Exibe a Barrinha de Loading.
void nome();              // Mostra apenas o Nome do Jogo.
void menu();              // Exibe o Menu.
int tecla();              // Captura uma Tecla digitada e retorna uma valor inteiro referente a ela.
void sair();              // Sai do Jogo.
void instrucoes();        // Exibe as Instruções do Jogo.
void aperte_enter();      // Pede para o usuario apertar [enter].
void opcoes();            // Exibe as Opções do Jogo.
void limpa_buffer();      // Limpa o Buffer...        

// Faz a Barrinha de Carregando     

void loading()
{     
     system("cls");//Limpa a Tela
     printf("\n\n\n\n\t\t\t      [__________] \n");
     sleep(1);
     system("cls");
     printf("\n\n\n\n\t\t\t      [__________] \n");
     printf("\n\t\t\t       Loading...");
     sleep(1);
     system("cls");
     printf("\n\n\n\n\t\t\t      [#_________] \n");
     printf("\n\t\t\t       Loading...");
     sleep(1);
     system("cls");
     printf("\n\n\n\n\t\t\t      [##________] \n");
     printf("\n\t\t\t       Loading...");
     sleep(1);
     system("cls");
     printf("\n\n\n\n\t\t\t      [###_______] \n");
     printf("\n\t\t\t       Loading...");
     sleep(1);
     system("cls");
     printf("\n\n\n\n\t\t\t      [####______] \n");
     printf("\n\t\t\t       Loading...");
     sleep(1);
     system("cls");
     printf("\n\n\n\n\t\t\t      [#####_____] \n");
     printf("\n\t\t\t       Loading...");
     sleep(1);
     system("cls");
     printf("\n\n\n\n\t\t\t      [######____] \n");
     printf("\n\t\t\t       Loading...");
     sleep(1);
     system("cls");
     printf("\n\n\n\n\t\t\t      [#######___] \n");
     printf("\n\t\t\t       Loading...");
     sleep(1);
     system("cls");
     printf("\n\n\n\n\t\t\t      [########__] \n");
     printf("\n\t\t\t       Loading...");
     sleep(1);
     system("cls");
     printf("\n\n\n\n\t\t\t      [#########_] \n");
     printf("\n\t\t\t       Loading...");
     sleep(1);
     system("cls");
     printf("\n\n\n\n\t\t\t      [##########] \n");
     printf("\n\t\t\t       Loading...");
     sleep(1);
     system("cls");
     printf("\n\n\n\n\t\t\t      [##########] \n");
     printf("\n\t\t\t       Complete.");
     sleep(1);
     system("cls");
     }

void nome()
{
printf("\n\n\t\t //)))))    __      ___       __      __                      \n"
           "\t\t ||       //  \\\\   ||  \\\\   //  \\\\  //  \\\\            \n"
           "\t\t ||)))    |    |   ||  //   |       ||  ||                    \n"
           "\t\t ||       |    |   || \\\\    |       ||==||                  \n"
           "\t\t ||       \\\\__//   ||  \\\\   \\\\__//  ||  ||            \n\n"
           "\t\t                                \n"     
           "\t\t___________________________________________            \n\n\n");       
}    


void sair() {
          
int c;//é atribuido ao valor da tecla
int lugar = 0;//diz em qual opção esta o cursor.
system ("cls");
nome();
printf("\t\t\tVoce realmente deseja sair?\n\n");
printf("\t\t\t\t [  Sim  ]\n"
       "\t\t\t\t    Nao   \n\n");
                    
while (1) {
      
      if (kbhit()) {// kbhit = apertar tecla
         system ("cls");
         nome();
         printf("\t\t\tVoce realmente deseja sair?\n\n");          
         c = tecla();// c será atribuido ao valor inteiro da tecla.
         
         if(c == 80)//apertou para baixo
             {
                lugar++;
                if (lugar>1) {
                   lugar = 0;
                   }         
             }
     if(c == 72)////apertou para cima
             {
                lugar--;
                if (lugar<0) {
                        lugar = 1;
                        }
             }
     if(c == 13)//apertou [enter]
             {
             if (lugar == 0){
                       system ("cls");
                       nome();
                       printf("\t\t\tObrigado por jogar Forca \n\n\n\n\n");
                       exit(0);
                       
             }
             else{
                  menu();
                  }
                  }
     if (lugar == 0) {//imprime as opções
               
               printf("\t\t\t\t [  Sim  ]\n"
                      "\t\t\t\t    Nao   \n\n");
                      
                      }
     if (lugar == 1) {
               printf("\t\t\t\t    Sim   \n"
                      "\t\t\t\t [  Nao  ]\n\n");
                                                             
                      }
                          
}
}
}

void opcoes() {
    system("cls");
    nome();
    int c, lugar = 0;
    printf("\t\t\t\t[  Categoria  ]\n"
           "\t\t\t\t    Voltar");
 while (1) {
  if (kbhit()) {//80 = Baixo, 72 = Cima, 13 = enter
           
              system ("cls");
              nome();
              c = tecla();// atribui um valor inteiro a "c" chamando a função "tecla()"
             
             
     if(c == 80) {
                lugar++;
                if (lugar>1) {
                   lugar = 0;
                   }         
             }
     if(c == 72) {
                lugar--;
                if (lugar<0) {
                        lugar = 1;
                        }
             }
     if(c == 13)  {
             switch (lugar){
                    case 0://categoria
                         system("cls");
                         nome();
                         opcoes();   
                    case 1:// Voltar    
                       
                         menu();
                         }
                         }             
             
      if (lugar == 0)
      {
           printf( "\t\t\t\t[  Categoria  ]\n"
                  "\t\t\t\t     Voltar");
      }
      else if (lugar == 1) 
      {
           printf( "\t\t\t\t  Categoria  \n"
                  "\t\t\t\t [  Voltar  ]");
      }
      
          
                                                       
}
}    
}   

void limpa_buffer(){
char x;     
     
     
     do {
        x = getchar();
     }while ((x != '\n')&&(x != EOF));//EOF = chegou no final do arquivo
     
}   


void aperte_enter()
{
       nome();
       printf("\n\n\t\t\t\t  [ Enter ]"
              "\n\t\t\t\t      ");         
       limpa_buffer();
       system("cls");
}


// Exibe as Instruções do Jogo

void instrucoes() {
    
    system("cls");
    nome();
    printf("\t\t    Na Forca, o objetivo do jogo eh adivinhar a palavra\n"
           "\t\t oculta.\n"
           "\t\t    Para tentar uma letra, digite-a no seu teclado.\n"
           "\t\t Se existir a letra na palavra, a mesma aparecera, porem,\n"
           "\t\t se a palavra nao tiver a letra, uma parte do corpo\n"
           "\t\t do boneco sera adicionada a forca, indicando o erro.\n"
           "\t\t    Ao todo sao permitidos seis erros, e se ultrapassados\n"
           "\t\t o jogo estara terminado e voce sera direcionado ao Menu\n"
           "\t\t principal.\n\n");
    
    limpa_buffer();
    menu();               


}

/* 
   Algumas teclas:
           -80 = Baixo
           -72 = Cima
           -75 = esquerda
           -77 = direita
           -13 = enter
*/

int tecla()
{
    int vartecla;
    while(1)
    {
          if(kbhit())
          {
             vartecla = getch();
             return(vartecla);
             
          }    
    
    }
}


void menu()
{
int c;    
int lugar = 0; //diz em qual opção esta o cursor (ver final da função).    
system("cls");
nome();

printf("\t\t\t\t[   Jogar    ]\n"
       "\t\t\t\t  Instrucoes \n"
       "\t\t\t\t    Opcoes   \n"    
       "\t\t\t\t     Sair    \n"); 
       
     while (1) {
           if (kbhit()) //80 = Baixo, 72 = Cima, 77 = esquerda, 75 = direita, 13 = enter
           {
              system ("cls");
              nome();
              c = tecla();// atribui um valor inteiro a "c" chamando a função "tecla()"
              
            

     if(c == 80) {
                lugar++;
                if (lugar>3) {
                   lugar = 0;
                   }         
             }
     if(c == 72) {
                lugar--;
                if (lugar<0) {
                        lugar = 3;
                        }
             }
     if(c == 13)  {
             switch (lugar){
                    case 0://Jogar
                         break;
                    case 1://Instruções
                         instrucoes();
                    case 2://opções
                         opcoes();
                    case 3://Sair          
                         sair();
                         }             
             }           
                  
                  if (lugar == 0)
                  {
                       printf("\t\t\t\t[   Jogar    ]\n"
                              "\t\t\t\t  Instrucoes \n"
                              "\t\t\t\t    Opcoes   \n"        
                              "\t\t\t\t     Sair    \n");  
                       
                  }
                  else if (lugar == 1) 
                  {
                       printf("\t\t\t\t    Jogar \n"
                              "\t\t\t\t[ Instrucoes ]\n"
                              "\t\t\t\t    Opcoes   \n"           
                              "\t\t\t\t     Sair    \n");  
                       
                       
                  }
                  else if (lugar == 2) 
                  {
                       printf("\t\t\t\t    Jogar \n"
                              "\t\t\t\t  Instrucoes \n"
                              "\t\t\t\t[   Opcoes   ]\n"           
                              "\t\t\t\t     Sair    \n");  
                       
                       
                  }
                  else if (lugar == 3) 
                  {
                        printf("\t\t\t\t    Jogar \n"
                              "\t\t\t\t  Instrucoes \n"
                              "\t\t\t\t    Opcoes \n"           
                              "\t\t\t\t[    Sair    ] \n");  
                              
                       }                                                        
}
}   
}

int main()
{
// Chamada de Funções:                   
     loading();
     aperte_enter();
     menu();
         
}
     
//Felipe Gomes
//Felipe Cesar
//Hony
//Jovito
//Matheus
