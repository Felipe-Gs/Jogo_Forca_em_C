#include <stdio.h>   // Biblioteca Padrão de C, tem comandos básicos de entrada e saida.
#include <time.h>    // Biblioteca Usada para funções de tempo
#include <stdlib.h>  // Usada Para Comandos System(" ")
#include <string.h>  // Biblioteca que contém operações com strings

int erros=0;
int on_0 = 1, on_1 = 1, on_2 = 1, on_3 = 1;// Variáveis booleanas
char palpite = '0', teste[21], palavras[][21] = {};
char alfa[] = {"abcdefghijklmnopqrstuvwxyz"};

void leArquivo(){
     FILE *arq;
     char linha[100];
     char *result;
     int i;

     clrsrc();

     arq = fopen("palavras.txt", "rt");

     if (arq == NULL)  // Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo\n");
     return;
  }
  i = 1;
  while (!feof(arq))
  {
	// Lê uma linha (inclusive com o '\n')
      result = fgets(linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
      if (result)  // Se foi possível ler
	  printf("Linha %d : %s",i,linha);
      i++;
  }
  fclose(arq);
}

int menu_categoria() {
int c, lugar = 0; 
  
    printf("\n\t\t       Use as Setas do Teclado para\n" 
             "\t\t       Marcar e Desmarcar as Opcoes.\n"
           "\t\t        Aperte [ENTER] para Voltar.\n\n\n");
    
              if (on_0)
              printf("\t > (x) Animais\n");
           else 
              printf("\t > ( ) Animais\n");
           if (on_1)
              printf("\t   (x) Pessoa\n");                   
           else 
              printf("\t   ( ) Pessoa\n");  
           if (on_2)
              printf("\t   (x) Lugar\n");
           else 
              printf("\t   ( ) Lugar\n");
           if (on_3)
              printf("\t   (x) Objeto\n");
           else 
              printf("\t   ( ) Objeto\n");                 
                
    
    while(1){
         if (kbhit()) {
             system("cls");
             nome();
             printf("\n\t\t       Use as Setas do Teclado para\n" 
                      "\t\t       Marcar e Desmarcar as Opcoes.\n"
                    "\t\t        Aperte [ENTER] para Voltar.\n\n\n");              
                    
                                
             
                      
             c = tecla();
             
     if (c==75) {                
                switch (lugar) {
                       case 0:
                           if (on_0)
                              on_0 = 0;
                           else
                              on_0 = 1;    
                              break;        
                                  
                       case 1:
                           if (on_1)
                              on_1 = 0;
                           else
                              on_1 = 1;    
                              break;   
                               
                       case 2:
                            if (on_2)
                              on_2 = 0;
                           else
                              on_2 = 1;    
                              break;   
                       case 3:               
                            if (on_3)
                              on_3 = 0;
                           else
                              on_3 = 1;    
                              break;   
                       
                       
                       }//fim switch
             }
     if(c == 77) {
                 switch (lugar) {
                       case 0:
                           if (on_0)
                              on_0 = 0;
                           else
                              on_0 = 1;    
                              break;        
                                  
                       case 1:
                           if (on_1)
                              on_1 = 0;
                           else
                              on_1 = 1;    
                              break;   
                               
                       case 2:
                            if (on_2)
                              on_2 = 0;
                           else
                              on_2 = 1;    
                              break;   
                       case 3:               
                            if (on_3)
                              on_3 = 0;
                           else
                              on_3 = 1;    
                              break;   
                       
                       
                       }//fim switch       
             }
     if(c == 80)  { //baixo
                lugar++;
                if (lugar>3) {
                   lugar = 0;
                }
             }
     if(c == 72)  { //cima
                lugar--;
                if (lugar<0) {
                   lugar = 3;
                             }
                             }
     if(c == 13)  { //enter  
                  system("cls");
                  
                  return 0;// volta ao menu                  
                  }
 //__________________________________________________________
             
  
  switch (lugar){
          
      case 0:    
           if (on_0)
              printf("\t > (x) Animais\n");
           else 
              printf("\t > ( ) Animais\n");
           if (on_1)
              printf("\t   (x) Pessoa\n");                   
           else 
              printf("\t   ( ) Pessoa\n");  
           if (on_2)
              printf("\t   (x) Lugar\n");
           else 
              printf("\t   ( ) Lugar\n");
           if (on_3)
              printf("\t   (x) Objeto\n");
           else 
              printf("\t   ( ) Objeto\n");                 
             
           break;
           
      case 1:    
           if (on_0)
              printf("\t   (x) Animais\n");
           else 
              printf("\t   ( ) Animais\n");
           if (on_1)
              printf("\t > (x) Pessoa\n");                   
           else 
              printf("\t > ( ) Pessoa\n");  
           if (on_2)
              printf("\t   (x) Lugar\n");
           else 
              printf("\t   ( ) Lugar\n");
           if (on_3)
              printf("\t   (x) Objeto\n");
           else 
              printf("\t   ( ) Objeto\n");                 
             
           break;         
             
      case 2:    
           if (on_0)
              printf("\t   (x) Animais\n");
           else 
              printf("\t   ( ) Animais\n");
           if (on_1)
              printf("\t   (x) Pessoa\n");                   
           else 
              printf("\t   ( ) Pessoa\n");  
           if (on_2)
              printf("\t > (x) Lugar\n");
           else 
              printf("\t > ( ) Lugar\n");
           if (on_3)
              printf("\t   (x) Objeto\n");
           else 
              printf("\t   ( ) Objeto\n");                 
             
           break;         
             
      case 3:    
           if (on_0)
              printf("\t   (x) Animais\n");
           else 
              printf("\t   ( ) Animais\n");
           if (on_1)
              printf("\t   (x) Pessoa\n");                   
           else 
              printf("\t   ( ) Pessoa\n");  
           if (on_2)
              printf("\t   (x) Lugar\n");
           else 
              printf("\t   ( ) Lugar\n");
           if (on_3)
              printf("\t > (x) Objeto\n");
           else 
              printf("\t > ( ) Objeto\n");                 
             
           break;         
           } //switch       
     }//if kb hit
   }//while(1)           
             
}//fim main



void enforcado(void)
{
      switch (erros)
      {
        
        case 0:        printf ("_________       \n"
                               "|       |       \n"
							   "|               \n"
							   "|               \n"
							   "|               __    \n"
							   "|     ______   (##)    \n"
							   "|     |    |  /|__|--|      \n"
							   "|     |    |   |  |  |     \n");
                break;
        
        case 1:        printf ("_________   \n"
                               "|       |  \n"
							   "|      (oO)\n"
							   "|          \n"
							   "|               __    \n"
							   "|     ______   (##)    \n"
							   "|     |    |  /|__|--|      \n"
							   "|     |    |   |  |  |     \n");
               break;
        case 2:        printf ("_________   \n"
                               "|       |  \n"
							   "|      (oO)\n"
							   "|       || \n"
							   "|               __    \n"
							   "|     ______   (##)    \n"
							   "|     |    |  /|__|--|      \n"
							   "|     |    |   |  |  |     \n");
               break;
        case 3:        printf ("_________   \n"
                               "|       |  \n"
							   "|      (oO)\n"
							   "|      /|| \n"
							   "|               __    \n"
							   "|     ______   (##)    \n"
							   "|     |    |  /|__|--|      \n"
							   "|     |    |   |  |  |     \n");
               break;
        case 4:        printf ("_________   \n"
                               "|       |  \n"
							   "|      (oO)\n"
							   "|      /||\\\n"
							   "|               __    \n"
							   "|     ______   (##)    \n"
							   "|     |    |  /|__|--|      \n"
							   "|     |    |   |  |  |     \n");
               break;
        case 5:        printf ("_________   \n"
                               "|       |  \n"
							   "|      (oO)\n"
							   "|      /||\\\n"
							   "|       /       __    \n"
							   "|     ______   (##)    \n"
							   "|     |    |  /|__|--|      \n"
							   "|     |    |   |  |  |     \n");
               break;
        case 6:        system("cls");
		    	       printf ("_________   \n"
                               "|       |  \n"
							   "|      (oO)\n"
							   "|      /||\\\n"
							   "|       /\\      __    \n"
							   "|     ______   (##)    \n"
							   "|     |    |  /|__|--|      \n"
							   "|     |    |   |  |  |     \n");
		          
		               sleep(2);
                       system ("cls");
		               printf ("_________   \n"
                               "|       |  \n"
							   "|      (oO)\n"
							   "|      /||\\\n"
							   "|       /\\      __    \n"
							   "|     ______   (##)    \n"
							   "|     |    |  /|__|-\\      \n"
							   "|     |    |   |  |  \\     \n");
							     
                       sleep(2);
                       system ("cls");
                       printf ("_________   \n"
                               "|       |  \n"
							   "|       |  \n"
							   "|      (xX)\n"
							   "|      /||\\     __    \n"
							   "|    \\  /\\  / \\(##)    \n"
							   "|     |    |   |__|-\\      \n"
							   "|     |    |   |  |  \\     \n");
               
                       sleep(2);
                       break;  
      }
}

     
//______________________________________________________________________________
//Figura para casos de vit�ria.
void viveu()
{
     printf ("_________                             \n"
             "|       |                             \n"
             "|                                     \n"
	         "|                                     \n"
	         "|               __                     \n"
	         "|     ______   (@@)        (Oo)        \n"
	         "|     |    |  /|__|--|     /||\\          \n"
             "|     |    |   |  |  |      /\\           \n");     
}


//______________________________________________________________________________
//Anima��o para o caso de derrota.     
void morreu()
{
     system("cls");
     printf ("_________   \n"
             "|       |  \n"
	         "|       |  \n"
			 "|      (xX)\n"
			 "|      /||\\     __    \n"
			 "|    \\  /\\  / \\(##)    \n"
			 "|     |    |   |__|-\\      \n"
			 "|     |    |   |  |  \\     \n");
}

//Mostra o alfabeto e retira as letras j� utilizadas, substituindo-as por '-'.
void alfabeto (void)
{
		int i;
		printf("\n");
		for (i=0; alfa[i] != '\0'; i++)
		{
			if (palpite == alfa[i])
				alfa[i] = '-';
			
			putchar (alfa[i]);
			printf(" ");
		}
		printf("\n\n");
}
			
//______________________________________________________________________________
//Reseta os Valores para que se possa jogar novamente
void reset_valores(void)
{
	int a;
	erros=0;
	palpite = '0';
	for (a=0; teste[a]!= '\0'; a++)
	{
		teste[a] = '\0';
	}
	memmove(alfa, "abcdefghijklmnopqrstuvwxyz", 27);
}
	

//______________________________________________________________________________
//Ao final do jogo, possibilita uma nova partida.
int novamente(int a)
{
	
	
         int c;//� atribuido ao valor da tecla
         int lugar = 0;//diz em qual op��o esta o cursor (ver final da fun��o).
         system ("cls");
         if (erros == 6)
         {
            morreu();
            printf("\n\n**********VOCE PERDEU**********\n\n");
            printf("\n A PALAVRA ERA: %s\n\n\n", palavras[a]);
            
         }
         else
         {
             viveu();
             display();
             printf("\n\n Parabens. Voce venceu \n\n");    
         }
         printf("\t\t\tVoce deseja jogar de novo?\n\n");           
         printf("\t\t\t\t [  Sim  ]\n"
                "\t\t\t\t    Nao   " );
       
         while (1) 
         {
      
          if (kbhit()) // kbhit = apertar tecla
          {
               system ("cls");
            if (erros == 6)
            {
               morreu();
               printf("\n\n**********VOCE PERDEU**********\n\n");
               printf("\n A PALAVRA ERA: %s\n\n\n", palavras[a]);
            }
            else
            {
               viveu();
               display();
               printf("\n\n Parabens. Voce venceu \n\n ");
            }
            printf("\t\t\tVoce deseja jogar de novo?\n\n");
                       
            c = tecla();// c ser� atribuido ao valor inteiro da tecla.
         
            if(c == 80)//apertou para baixo
            {
                lugar++;
                if (lugar>1) 
                  lugar = 0;
            }
            if(c == 72)////apertou para cima
            {
                lugar--;
                if (lugar<0) 
                  lugar = 1;
            }
            if(c == 13)//apertou [enter]
            {
                if (lugar == 0)// escolheu sim
                {
                    reset_valores();
                    return 0;
                }              
                else// escolheu nao
                {
                    reset_valores();
                    return 1;
                }
            }
            if (lugar == 0) //imprime as op��es
            {
               printf("\t\t\t\t [  Sim  ]\n"
                      "\t\t\t\t    Nao   ");
            }
            if (lugar == 1) 
            {
               printf("\t\t\t\t    Sim   \n"
                      "\t\t\t\t [  Nao  ]");
            }
          }  
        }
}       


//______________________________________________________________________________
//Imprime na Tela a dica para a palavra
void dica(int a)
{
     if(a <= 40)
          printf("*DICA: animal");
     else if(a <= 80)
          printf("*DICA: pessoa");
     else if(a <= 120)
          printf("*DICA: lugar");
     else if(a <= 160)
          printf("*DICA: objeto");
     printf("\n\n\n");
}


//______________________________________________________________________________
//Mecanismo do jogo da forca.

int mecanismo_jogo(int a)
{
     while (erros<6)
     {
           printf("\n\tVoce pode errar %d vezes.\n", 6-erros);
           enforcado();
           display();
           alfabeto();
           dica(a);
           if (entrada())
           {
           	  system("cls");
           	  continue;
           }
           check_palpite(a);
           if (!(check_vitoria()))
              return 0;
           
         
           system("cls");
     }
     
     enforcado();
     //morreu(); ou viveu();
     printf("\n\n**********VOCE PERDEU**********\n\n");
     printf("\n A PALAVRA ERA: %s\n", palavras[a]);
     
     
     return 0;
}


//Jogo em si.
int jogar(void)
{
    int a, novojogo;
    srand ( time(NULL) );
    
    if((!on_0) && (!on_1) && (!on_2) && (!on_3))
    {
         printf("\n\n\t Voce deve selecionar as categorias de palavras no menu OPCOES");
         getch();
         return 0;
    }
    while(1)
    {
    	while(1)
        {
             a = rand()%161;
             if((a<=40) && (on_0))
                break;
             else if((a<=40) && (!on_0))
                continue;
             
             else if((a>40 && a<=80) && (on_1))
                break;  
             else if((a>40 && a<=80) && (!on_1))
                continue;
                
             else if((a>80 && a<=120) && (on_2))
                break;  
             else if((a>80 && a<=120) && (!on_2))
                continue;
                
             else if((a>120 && a<=160) && (on_3))
                break;  
             else if((a>120 && a<=160) && (!on_3))
                continue;
        }
             
        system("cls");
    	initialize(a); //cria a string dos '_ _ _'
    	mecanismo_jogo(a);
    	novojogo = novamente(a);
    	if(novojogo)
    		menu();
    	reset_valores();
    }   		
    	
    return 0;
}

void nome()
{
system("mode con:cols=80 lines=30");
printf("\n\n\t\t<><><><><><><><><><><><><><><><><><><><><><>                \n"
           "\t\t| //)))))    __      ___       __      __   |               \n"
           "\t\t| ||       //  \\\\   ||  \\\\   //  \\\\  //  \\\\ |       \n"
           "\t\t| ||)))    |    |   ||  //   |       ||  || |               \n"
           "\t\t| ||       |    |   || \\\\    |       ||==|| |             \n"
           "\t\t| ||       \\\\__//   ||  \\\\   \\\\__//  ||  || |         \n"    
           "\t\t<><><><><><><><><><><><><><><><><><><><><><>                \n\n\n");       
}


void aperte_enter()
{
    system("mode con:cols=80 lines=30");
       nome();
       printf("\n\n\t\t\t\t  [ Enter ]"
              "\n\t\t\t\t      ");         
       limpa_buffer();
       system("cls");
}

void loading()
{    
     system("mode con:cols=80 lines=30");
     system("cls");//Limpa a Tela
     nome();
     printf("\n\n\t\t\t      [__________] \n");
     sleep(1);
     system("cls");
     nome();
     printf("\n\n\t\t\t      [__________] \n");
     printf("\n\t\t\t       Loading...");
     sleep(1);
     system("cls");
     nome();
     printf("\n\n\t\t\t      [#_________] \n");
     printf("\n\t\t\t       Loading...");
     sleep(1);
     system("cls");
     nome();
     printf("\n\n\t\t\t      [##________] \n");
     printf("\n\t\t\t       Loading...");
     sleep(1);
     system("cls");
     nome();
     printf("\n\n\t\t\t      [###_______] \n");
     printf("\n\t\t\t       Loading...");
     sleep(1);
     system("cls");
     nome();
     printf("\n\n\t\t\t      [####______] \n");
     printf("\n\t\t\t       Loading...");
     sleep(1);
     system("cls");
     nome();
     printf("\n\n\t\t\t      [#####_____] \n");
     printf("\n\t\t\t       Loading...");
     sleep(1);
     system("cls");
     nome();
     printf("\n\n\t\t\t      [######____] \n");
     printf("\n\t\t\t       Loading...");
     sleep(1);
     system("cls");
     nome();
     printf("\n\n\t\t\t      [#######___] \n");
     printf("\n\t\t\t       Loading...");
     sleep(1);
     system("cls");
     nome();
     printf("\n\n\t\t\t      [########__] \n");
     printf("\n\t\t\t       Loading...");
     sleep(1);
     system("cls");
     nome();
     printf("\n\n\t\t\t      [#########_] \n");
     printf("\n\t\t\t       Loading...");
     sleep(1);
     system("cls");
     nome();
     printf("\n\n\t\t\t      [##########] \n");
     printf("\n\t\t\t       Loading...");
     sleep(1);
     system("cls");
     nome();
     printf("\n\n\t\t\t      [##########] \n");
     printf("\n\t\t\t       Complete.");
     sleep(1);
     system("cls");
     }

void menu()
{
int c;    
int lugar = 0; //diz em qual opção esta o cursor (ver final da função). 
system("mode con:cols=80 lines=30");   
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
                         jogar();
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

void sair(){
          
int c;//é atribuido ao valor da tecla
int lugar = 0;//diz em qual opção esta o cursor.
system("mode con:cols=80 lines=30");
system ("cls");
nome();
printf("\t\t\tVoce realmente deseja sair?\n\n");
printf("\t\t\t\t [  Sim  ]\n"
       "\t\t\t\t    Nao   \n\n");
                    
while (1){
      
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
     if (lugar == 1){
               printf("\t\t\t\t    Sim   \n"
                      "\t\t\t\t [  Nao  ]\n\n");
                                                             
                    }
                          
        }
    }
}

void opcoes(){
    system("mode con:cols=80 lines=30");
    system("cls");
    nome();
    int c, lugar = 0;
    printf("\t\t\t\t[  Categoria  ]\n"
           "\t\t\t\t    Voltar");
 while (1) {
  if (kbhit()){//80 = Baixo, 72 = Cima, 13 = enter
           
     system ("cls");
     nome();
     c = tecla();// atribui um valor inteiro a "c" chamando a função "tecla()"
             
     if(c == 80){
          lugar++;
          if (lugar>1){
          lugar = 0;
          }         
             }
     if(c == 72){
          lugar--;
          if (lugar<0){
               lugar = 1;
          }
     }
     if(c == 13){
          switch (lugar){
               case 0://categoria
                    system("cls");
                    nome();
                    menu_categoria();
                    opcoes();   
               case 1:// Voltar    

                    menu();
               }
          }             
             
      if (lugar == 0){

          printf("\t\t\t\t[  Categoria  ]\n"
                 "\t\t\t\t    Voltar");
               }
      else if (lugar == 1){
          printf("\t\t\t\t   Categoria   \n"
                 "\t\t\t\t[   Voltar   ]");
               }                                                
          } 
     }
}   

void limpa_buffer(){
char x;     
     
     do{
        x = getchar();
     }while (x != '\n');
     
}   

// Exibe as Instruções do Jogo

void instrucoes(){
    system("mode con:cols=80 lines=30");
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
           "\t\t principal.(Para voltar ao menu aperte ENTER)\n\n");
    
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

//jogo 
int main()
{
// Chamada de Funções:                   
     loading();
     aperte_enter();
     menu();
     return 0;     
}