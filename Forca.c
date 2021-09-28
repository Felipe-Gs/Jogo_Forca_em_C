

#include <stdio.h>   // Biblioteca Padr�o de C, tem comandos b�sicos de entrada e saida.
#include <time.h>    // Biblioteca Usada para gerar numeros aleat�rios
#include <stdlib.h>  // Usada Para Comandos System(" ");
#include <stdbool.h> // Biblioteca Usada para fun��es booleanas
#include <string.h>  // Biblioteca que cont�m opera��es com strings

//______________________________________________________________________________
//Explicita as Fun��es usadas no Programa

int main();               // Fun�ao Principal: Chama as Outras Fun��es.
void loading();           // Exibe a Barrinha de Loading.
void nome();              // Mostra apenas o Nome do Jogo.
void menu();              // Exibe o Menu.
int tecla();              // Captura uma Tecla digitada e retorna uma valor inteiro referente a ela.
void sair();              // Sai do Jogo.
void instrucoes();        // Exibe as Instru��es do Jogo.
void aperte_enter();      // Pede para o usuario apertar [enter].
void opcoes();            // Exibe as Op��es do Jogo.
void vidas();             // Exibe um Boneco que representa a quantidades de Vidas Restantes.
void limpa_buffer();      // Limpa o Buffer...
void sleep();             // Fun��o implicita .
int menu_categoria();     // Exibe um menu para a sele��o das categorias de palavras.
void initialize(int a);   // Cria a string de testes utilizada no jogo.
void display();           // Imprime a string de testes.
int entrada();            // L� a letra fornecida pelo usu�rio.
int check_palpite (int a);// Verifica se a letra pertence a palavra.
int check_vitoria (void); // Verifica se a pessoa ganhou.
void enforcado(void);     // Imprime o boneco, dependendo da quantidade de erros.
void viveu();             // Imagem para caso de vit�ria.
void morreu();            // Anima��o para caso de derrota.
void alfabeto();          // Imprime string com letras do alfabeto.
void reset_valores();     // Reseta os valores das vari�veis para que se possa jogar novamente.
int novamente(int a);     // Pergunta se a pessoa deseja jogar novamente.
void dica(int a);         // Imprime uma dica da palavra.
int mecanismo_jogo(int a);// Mecanismo do jogo...         
int jogar(void);          // Jogo em si.

#define TEMPO 1

int leArquivo(void)
{
    int i = 0;
    int numPalavras = 0;
    char* palavras[200][200];
    char line[200];

    FILE *arquivo;
    arquivo = fopen("palavras.txt", "r");

    if (arquivo == NULL)
        return EXIT_FAILURE;

    while(fgets(line, sizeof line, arquivo) != NULL)
    {
        //Adiciona cada palavra no vetor
        palavras[i][200] = strdup(line);

        i++;

        //Conta a quantidade de palavras
        numPalavras++;
    }

    int j;

    for (j = 0; j < numPalavras; j++)
        printf("\n%s", palavras[j]);

    fclose(arquivo);

    return EXIT_SUCCESS;
}

int erros=0;
int on_0 = 1, on_1 = 1, on_2 = 1, on_3 = 1;// Vari�veis booleanas
char palpite = '0', teste[21], palavras[][200] = {};
char alfa[] = {"abcdefghijklmnopqrstuvwxyz"};

// Come�o das Fun��es:
//______________________________________________________________________________
// Faz a Barrinha de Carregando (sistematicamente in�til, por�m esteticamente razoavel...)     

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
          
int c;//� atribuido ao valor da tecla
int lugar = 0;//diz em qual op��o esta o cursor (ver final da fun��o).
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
     if (lugar == 0) {//imprime as op��es
               
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





//Exibe o Menu em que se escolhe as categorias das palavras que ser�o sorteadas
//para o jogo da forca
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


//______________________________________________________________________________
// Exibe as Op��es
// Para mais explica��es sobre os menus do jogo veja a fun��o Menu()

void opcoes() {
    system("cls");
    nome();
    int c, lugar = 0;
    printf("\t\t\t\t[  Categoria  ]\n"
           "\t\t\t\t    Voltar");
 while (1) {
  if (kbhit()) {//80 = Baixo, 72 = Cima, 77 = esquerda, 75 = direita, 13 = enter
           
              system ("cls");
              nome();
              c = tecla();// atribui um valor inteiro a "c" chamando a fun��o "tecla()"
             
             
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
                         menu_categoria();
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
      
          
                                                       
}//Fecha o If(1)
}//Fecha o While    
}//Fecha Fun��o      
    
    



void limpa_buffer(){
char x;     
     
     
     do {
        x = getchar();
     }while ((x != '\n')&&(x != EOF));
     
}   



void aperte_enter()
{
       nome();
       printf("\n\n\t\t\t\t  [ Enter ]"
              "\n\t\t\t\t      ");         
       limpa_buffer();
       system("cls");
}

//______________________________________________________________________________
// Exibe as Instru��es do Jogo

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

//______________________________________________________________________________
// Menu Principal
// O Menu � impresso e pode se usar as teclas para selecionar a op��o escolhida


/* Uma R�pida explica��o dos Menus do Jogo:
              Em todo o jogo, os menus s�o representados de maneiras possivelmente
       confusa. Para esclarecer a aqueles que n�o compreenderam bem o funcionamento,
       segue uma explica��o: 
             1) O Comando utilizado para capturar o c�digo das teclas pressionadas
                � o Tecla(). Quando chama a fun��o c = tecla(); ent�o a vari�vel
                c assumir� o valor no ASCII da Tecla Pressionada.
                  (ex.: baixo = 80; a = 97; [Enter] = 13)
             2) A vari�vel "lugar" � atribuida � op��o selecionada no momento
                no menu em que foi definida.
             3) Cada vez que uma tecla � pressionada o "if" � chamado:
                     if (kbhit()) {     Se uma tecla for pressionada fa�a...
             4) Dependendo do c�digo atribuido a "c" um dos comandos de posi��o ser�
                ativado: j++, j--, ou se o usuario pressionar enter, a vari�vel
                lugar ser� lida e colocada em um switch case, e dependendo do
                seu valor, diversas a tribui��es podem ser feitas a ela.                
                
*/
void menu()
{
int c;    
int lugar = 0; //diz em qual op��o esta o cursor (ver final da fun��o).    
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
              c = tecla();// atribui um valor inteiro a "c" chamando a fun��o "tecla()"
              
//______________________________________________________________________________              
// Menu: Teclas direcionais Pressionadas:              

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
                    case 1://Instru��es
                         instrucoes();
                    case 2://Creditos 
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
                              "\t\t\t\t[    Sair   ] \n");  
                              
                       }                                                        
}
}   
}

            
//Cria a String da palavra que vai ser usada na forca.

void initialize(int a)
{
     
     int i;
     system("cls");
     for (i=0; palavras[a][i] != '\0'; i++)
     {
        if (palavras[a][i] == ' ')
            teste[i] = palavras[a][i];
        else
        		teste[i] = '_';
        
     }
}

//______________________________________________________________________________
//Mostra o estado do jogo.

void display() 
{
     int k;
     printf("\n");
     for (k=0; teste[k] != '\0'; k++)
     {
        putchar(teste[k]);
        printf(" ");
     }
     printf("\n");
}

//______________________________________________________________________________
//L� o palpite, com o cuidado de descartar entradas inv�lidas.

int entrada(void)
{     
     printf("Digite uma letra: ");
     palpite = getchar();
     if (palpite == '\n')
     		return 1;
     limpa_buffer();
     if(!isalpha(palpite))
     		return 1;
     palpite = tolower(palpite);
     return 0;
}
     
//______________________________________________________________________________
// Checa o palpite. Se certo, substitui o respectivo '_' pela letra correspondente.
//Se errado, adiciona um á variável erros*/             
int check_palpite (int a)
{
     int i;
     for (i=0; palavras[a][i] != '\0'; i++)
        {
            if (palpite == palavras[a][i] || toupper(palpite)==palavras[a][i])
                teste[i] = palavras[a][i];                       
        }
     
     if (!(strchr(alfa, palpite)))
			return 1;
     if((!(strchr(palavras[a], palpite))) && (!(strchr(palavras[a], toupper(palpite)))))
        erros++;
     return 0;
}

//______________________________________________________________________________
//Verifica se a Pessoa venceu.
int check_vitoria (void)
{
     int x, y;
     for(x=0, y=0; teste[x] != '\0'; x++)
     {
         if (teste[x] == '_')
             continue;
         else
             y++;
     }
     if(x == y)
     {
          display();
          return 0;
     }
     return 1;
}    

//______________________________________________________________________________
//Imprime o Boneco da Forca para cada numero de erros.
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


//______________________________________________________________________________
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



//Inicio do Programa
     
int main()
{
// Vari�veis:


// Chamada de Fun��es:     
                   
     loading();
     aperte_enter();
     leArquivo();
     sleep(30);
     menu();
         
}
     

