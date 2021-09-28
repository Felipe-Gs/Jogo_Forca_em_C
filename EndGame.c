#include <stdio.h>   
#include <time.h>    
#include <stdlib.h>  
#include <string.h>  

int main();               // Funcao Principal: Chama as Outras Funcoes.    felipe44
void loading();           // Exibe a Barrinha de Loading.                  felipe44
void nome();              // Mostra apenas o Nome do Jogo.                 felipe44
void menu();              // Exibe o Menu.                                 felipe44
int tecla();              // Captura uma Tecla digitada e retorna uma valor inteiro referente a ela. felipe44
void sair();              // Sai do Jogo.                                                 jovito
void instrucoes();        // Exibe as Instrucoes do Jogo.                                 jovito
void aperte_enter();      // Pede para o usuario apertar [enter].                         jovito
void opcoes();            // Exibe as Opcoes do Jogo.                                     jovito
void limpa_buffer();      // Limpa o Buffer...                                            jovito
int menu_categoria();     // Exibe um menu para a selecao das categorias de palavras.     felipe gomes
void initialize(int a);   // Cria a string de testes utilizada no jogo.                   felipe gomes
void display();           // Imprime a string de testes.                                  felipe gomes
int entrada();            // Le a letra fornecida pelo usuario.                           felipe gomes
int check_palpite (int a);// Verifica se a letra pertence a palavra.                      felipe gomes
int check_vitoria ();    // Verifica se a pessoa ganhou.                                  matheus 
void enforcado();       // Imprime o boneco, dependendo da quantidade de erros.           matheus 
void viveu();             // Imagem para caso de vitoria.                                 matheus 
void morreu();            // Animacao para caso de derrota.                               matheus 
void alfabeto();          // Imprime string com letras do alfabeto.                       matheus 
void reset_valores();     // Reseta os valores das variaveis para que se possa jogar novamente. hony
int novamente(int a);     // Pergunta se a pessoa deseja jogar novamente.                       hony
void dica(int a);         // Imprime uma dica da palavra.                                       hony 
int mecanismo_jogo(int a);// Mecanismo do jogo...                                               hony
int jogar();          // Jogo em si.                                                            hony

int erros=0;
int on_0 = 1, on_1 = 1, on_2 = 1, on_3 = 1;// Variaveis booleanas
char palpite = '0', teste[21]; 
char palavras[][21] = {
"cachorro","gato", "cavalo", "elefante", "ornitorrinco","avestruz","coruja","cegonha",
"abelha","anta","aranha","borboleta","besouro","barata","coelho","canguru","esquilo",
"formiga","flamingo","golfinho","guaxinim","gorila","hamster","hiena","galo","lagartixa",
"marreco","orangotango","pinguim","quimera","rinoceronte","salamandra","seriema","tucano","vespa",
"burro","baleia","camelo","cabra","hipopotamo","iguana",
"William Bonner","Zeca Camargo","Pedro Bial","Gloria Maria","George Clooney","Bono Vox","Shakira",
"Madonna","Brad Pitt","Angelina Jolie","Jim Carrey","Ivete Sangalo","Dilma Rousseff","Johnny Depp",
"Ziraldo","Xuxa","Adolf Hitler","Fiodor Dostoievski","John Kennedy","Juscelino Kubitschek",
"Mahatma Gandhi","Benito Mussolini","Fidel Castro","Che Guevara","Nelson Mandela","Albert Einstein",
"Santos Dumont","Graham Bell","Mozart", "Aristoteles","Arquimedes","Caetano Veloso","Candido Portinari",
"Clarice lispector","Charles Darwin","Elvis Presley","Monteiro Lobato","Leonardo da Vinci","Carmem Miranda",
"China","Estados unidos","Indonesia","Brasil","Bangladesh","Alemanha","Egito","Turquia","Reino Unido","Espanha",	
"Argentina","Marrocos","Iraque","Nepal","Venezuela","Gana","Taiwan","Rio de Janeiro","Sri Lanka","Costa do Marfim",	
"Madagascar","Chile","Equador","Camboja","Guatemala","Angola","Portugal","Hungria","Haiti","Honduras",
"Israel","Hong Kong","Paraguai","Serra Leoa","Dinamarca","Eslovaquia","Noruega","Costa Rica","Inglaterra","Irlanda",
"casaco","coroa","lente","travesseiro","xampu","colher","agulha","banco","brinco","sacola","balde","pente","telha", 
"torneira","moeda","guardanapo","chave","espelho","isqueiro","envelope","sabonete","ampulheta","grampeador","pantufa",
"toalha","anzol","bexiga","cartola","prato","gaveta","gaiola","cortina","canivete","vassoura","garrafa","dentadura",
"chinelo","celular","funil","lixeira"};
char alfa[] = {"abcdefghijklmnopqrstuvwxyz"}; 

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

void sair() {
          
int c;//o atribuido ao valor da tecla
int lugar = 0;//diz em qual opcao esta o cursor (ver final da funcao).
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
     if (lugar == 0) {//imprime as opcoes
               
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

//Exibe o Menu em que se escolhe as categorias das palavras que serao sorteadas
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

void opcoes() {
    system("mode con:cols=80 lines=30");
    system("cls");
    nome();
    int c, lugar = 0;
    printf("\t\t\t\t[  Categoria  ]\n"
           "\t\t\t\t    Voltar");
 while (1) {
  if (kbhit()) {//80 = Baixo, 72 = Cima, 77 = esquerda, 75 = direita, 13 = enter
           
              system ("cls");
              nome();
              c = tecla();// atribui um valor inteiro a "c" chamando a funcao "tecla()"
             
             
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
             
      if (lugar == 0){

          printf("\t\t\t\t[  Categoria  ]\n"
                 "\t\t\t\t    Voltar");
               }
      else if (lugar == 1){
          printf("\t\t\t\t   Categoria   \n"
                 "\t\t\t\t[   Voltar   ]");
               }                                             
      }//Fecha o If(1)
   }//Fecha o While    
}//Fecha Funcao      

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
                    case 1://Instrucoes
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
   system("cls");
   int i;

     for (i=0; palavras[a][i] != '\0'; i++)
     {
        if (palavras[a][i] == ' ')
            teste[i] = palavras[a][i];
        else
        		teste[i] = '_';
     }
}

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

void enforcado(void)
{
      switch (erros)
      {
        
        case 0:        printf ("_________       \n"
                               "|       |       \n"
							   "|               \n"
							   "|               \n"
							   "|               __    \n"
							   "|     ______   (00)    \n"
							   "|     |    |  /|__|--|      \n"
							   "|     |    |   |  |  #     \n");
                break;
        
        case 1:        printf ("_________   \n"
                               "|       |  \n"
							   "|      (oo)\n"
							   "|          \n"
							   "|               __    \n"
							   "|     ______   (00)    \n"
							   "|     |    |  /|__|--|      \n"
							   "|     |    |   |  |  #     \n");
               break;
        case 2:        printf ("_________   \n"
                               "|       |  \n"
							   "|      (oo)\n"
							   "|       || \n"
							   "|               __    \n"
							   "|     ______   (00)    \n"
							   "|     |    |  /|__|--|      \n"
							   "|     |    |   |  |  #     \n");
               break;
        case 3:        printf ("_________   \n"
                               "|       |  \n"
							   "|      (oO)\n"
							   "|      /|| \n"
							   "|               __    \n"
							   "|     ______   (00)    \n"
							   "|     |    |  /|__|--|      \n"
							   "|     |    |   |  |  #     \n");
               break;
        case 4:        printf ("_________   \n"
                               "|       |  \n"
							   "|      (oO)\n"
							   "|      /||\\\n"
							   "|               __    \n"
							   "|     ______   (00)    \n"
							   "|     |    |  /|__|--|      \n"
							   "|     |    |   |  |  #     \n");
               break;
        case 5:        printf ("_________   \n"
                               "|       |  \n"
							   "|      (Ox)\n"
							   "|      /||\\\n"
							   "|       /       __    \n"
							   "|     ______   (00)    \n"
							   "|     |    |  /|__|--|      \n"
							   "|     |    |   |  |  #     \n");
               break;
        case 6:        system("cls");
		    	       printf ("_________   \n"
                               "|       |  \n"
							   "|      (OX)\n"
							   "|      /||\\\n"
							   "|       /\\      __    \n"
							   "|     ______   (00)    \n"
							   "|     |    |  /|__|--|      \n"
							   "|     |    |   |  |  #     \n");
		          
		               sleep(2);
                       system ("cls");
		               printf ("_________   \n"
                               "|       |  \n"
							   "|      (xx)\n"
							   "|      /||\\\n"
							   "|       /\\      __    \n"
							   "|     ______   (00)    \n"
							   "|     |    |  /|__|-\\      \n"
							   "|     |    |   |  |  #     \n");
							     
                       sleep(2);
                       system ("cls");
                       printf ("_________   \n"
                               "|       |  \n"
							   "|       |  \n"
							   "|      (xX)\n"
							   "|      /||\\     __    \n"
							   "|    \\  /\\  / \\(00)    \n"
							   "|     |    |   |__|-\\      \n"
							   "|     |    |   |  |  #     \n");
               
                       sleep(2);
                       break;  
      }
}

void viveu()
{
     printf ("_________                             \n"
             "|       |                             \n"
             "|                                     \n"
	         "|                                     \n"
	         "|               __                     \n"
	         "|     ______   ()        (OO)        \n"
	         "|     |    |  /|__|--|     /||\\          \n"
             "|     |    |   |  |  |      /\\           \n");     
}


//______________________________________________________________________________
//Animacao para o caso de derrota.     
void morreu()
{
     system("cls");
     printf ("_________   \n"
             "|       |  \n"
	         "|       |  \n"
			 "|      (XX)\n"
			 "|      /||\\     __    \n"
			 "|    \\  /\\  / \\(00)    \n"
			 "|     |    |   |__|-\\      \n"
			 "|     |    |   |  |  #     \n");
}

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

int novamente(int a)
{
      int c;//o atribuido ao valor da tecla
      int lugar = 0;//diz em qual opcao esta o cursor (ver final da funcao).
      system ("cls");
      if (erros == 6)
      {
         morreu();
         printf("\n\n<><><><><>VOCE MORREU<><><><><>\n\n");
         printf("\n A PALAVRA ERA: %s\n\n\n", palavras[a]);
         
      }
      else
      {
            viveu();
            display();
            printf("\n\n Parabens. Voce Sopreviveu \n\n");    
      }
      printf("\t\t\tQuer jogar de novo?\n\n");           
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
            printf("\n\n<><><><><>VOCE MORREU<><><><><>\n\n");
            printf("\n A PALAVRA ERA: %s\n\n\n", palavras[a]);
         }
         else
         {
            viveu();
            display();
            printf("\n\n Parabens. Voce venceu \n\n ");
         }
         printf("\t\t\tQuer jogar de novo?\n\n");
                     
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
         if (lugar == 0) //imprime as opcoes
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
     printf("\n\n<><><><><>VOCE MORREU<><><><><>\n\n");
     printf("\n A PALAVRA ERA: %s\n", palavras[a]);

     return 0;
}

//Jogo em si.
int jogar(void)
{
    int a, novojogo;
    srand (time(NULL));
    
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
// Chamada de Funcoes:                 
     loading();
     aperte_enter();
     menu();       
}