

#include <stdio.h>   // Biblioteca Padr�o de C, tem comandos b�sicos de entrada e saida.
#include <time.h>    // Biblioteca Usada para gerar numeros aleat�rios
#include <dos.h>     // Nem sei pra que serve...
#include <conio.h>   // Principal Biblioteca Grafica, tem fun��es como kbhit() e getch()
#include <stdlib.h>  // Usada Para Comandos System(" ");
#include <stdbool.h> // Biblioteca Usada para fun��es booleanas
#include <math.h>    // Biblioteca Usado para equa��es matematicas
#include <ctype.h>   // Para Fun��es de Caracteres
#include <string.h>  // Biblioteca que cont�m opera��es com strings

//______________________________________________________________________________
//Explicita as Fun��es usadas no Programa

int main();               // Fun�ao Principal: Chama as Outras Fun��es.
void loading();           // Exibe a Barrinha de Loading.
void apresentacao();      // Apresenta a Anima��o e o Nome.
void nome();              // Mostra apenas o Nome do Jogo.
void menu();              // Exibe o Menu.
int tecla();              // Captura uma Tecla digitada e retorna uma valor inteiro referente a ela.
void cor();               // Exibe um Menu de Troca de Cor da letras.
void sair();              // Sai do Jogo.
void instrucoes();        // Exibe as Instru��es do Jogo.
void creditos();          // Exibe os Credito.
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


/* R�pida explica��o para int e void:
          
               Uma fun��o qualquer pode ser definida como int ou void
          a diferen�a fundamental dessas defini��es � o retorno da fun��o.
          Uma Fun��o int tem um retoro inteiro, j� uma fun��o void nao tem 
          retorno.
               Portanto, ao final de uma fun��o int � obrigatorio um retorno
          para que a fun��o seja finalizada corretamente. ex.:
                    
                    int limpa_buffer(){
                        ...
                        return(0);
                        }

               J� uma fun��o void pode ser finalizada sem retorno. 
               
   R�pida explica��o para Comandos Incomuns Usados no Jogo:
          
         -system("cls");   Limpa a tela totalmente.
         -sleep(...);      Espera o tempo em mil�simos para executar a pr�xima linha de comando.
         -kbhit();         Key board hit, acontece quando uma tecla � pressionada . 
         -system("pause"); Pausa o programa at� que alguma tecla seja pressionada.          
         -isalpha();       Verifica se a varialvel contem s� letras.
         -isdigit();       Verifica se a varialvel contem s� numeros.
         -tolower();       Tranforma tudo maiusculo em minusculo.
         -toupper();       Transforma o minusculo em maiusculo.            
*/
//______________________________________________________________________________
// Variaveis Universais

int erros=0;
bool on_0 = 1, on_1 = 1, on_2 = 1, on_3 = 1;// Vari�veis booleanas
char palpite = '0', teste[21], palavras[][21] = {
"cachorro","gato", "cavalo", "elefante", "ornitorrinco","avestruz","coruja","cegonha",/*0-7*/
"abelha","anta","aranha","borboleta","besouro","barata","coelho","canguru","esquilo",/*8-16*/
"formiga","flamingo","golfinho","guaxinim","gorila","hamster","hiena","galo","lagartixa",/*17-25*/
"marreco","orangotango","pinguim","quimera","rinoceronte","salamandra","seriema","tucano","vespa",/*26-34*/
"burro","baleia","camelo","cabra","hipopotamo","iguana",/*35-40*/
"William Bonner","Zeca Camargo","Pedro Bial","Gloria Maria","George Clooney","Bono Vox","Shakira",/*41-48*/
"Madonna","Brad Pitt","Angelina Jolie","Jim Carrey","Ivete Sangalo","Dilma Rousseff","Johnny Depp",/*49-55*/
"Ziraldo","Xuxa","Adolf Hitler","Fiodor Dostoievski","John Kennedy","Juscelino Kubitschek",/*56-61*/
"Mahatma Gandhi","Benito Mussolini","Fidel Castro","Che Guevara","Nelson Mandela","Albert Einstein",/*62-67*/
"Santos Dumont","Graham Bell","Mozart", "Arist�teles","Arquimedes","Caetano Veloso","Candido Portinari",/*68-74*/
"Clarice lispector","Charles Darwin","Elvis Presley","Monteiro Lobato","Leonardo da Vinci","Carmem Miranda",/*75-80*/
"China","Estados unidos","Indonesia","Brasil","Bangladesh","Alemanha","Egito","Turquia","Reino Unido","Espanha",/*81-90*/	
"Argentina","Marrocos","Iraque","Nepal","Venezuela","Gana","Taiwan","Rio de Janeiro","Sri Lanka","Costa do Marfim",/*91-100*/	
"Madagascar","Chile","Equador","Camboja","Guatemala","Angola","Portugal","Hungria","Haiti","Honduras",/*101-110*/	
"Israel","Hong Kong","Paraguai","Serra Leoa","Dinamarca","Eslovaquia","Noruega","Costa Rica","Inglaterra","Irlanda",/*111-120*/
"casaco","coroa","lente","travesseiro","xampu","colher","agulha","banco","brinco","sacola","balde","pente","telha", /*121-133*/
"torneira","moeda","guardanapo","chave","espelho","isqueiro","envelope","sabonete","ampulheta","grampeador","pantufa",/*134-144*/
"toalha","anzol","bexiga","cartola","prato","gaveta","gaiola","cortina","canivete","vassoura","garrafa","dentadura",/*135-156*/
"chinelo","celular","funil","lixeira"/*157-160*/};
char alfa[] = {"abcdefghijklmnopqrstuvwxyz"};

// Come�o das Fun��es:
//______________________________________________________________________________
// Faz a Barrinha de Carregando (sistematicamente in�til, por�m esteticamente razoavel...)     

void loading()
{     
     system("cls");//Limpa a Tela
     printf("\n\n\n\n\t\t\t      [__________] \n");
     sleep(2);// Espera 200 Mil�simos de Segundo
     system("cls");
     printf("\n\n\n\n\t\t\t      [__________] \n");
     printf("\n\t\t\t       Loading...");
     sleep(2);
     system("cls");
     printf("\n\n\n\n\t\t\t      [#_________] \n");
     printf("\n\t\t\t       Loading...");
     sleep(2);
     system("cls");
     printf("\n\n\n\n\t\t\t      [##________] \n");
     printf("\n\t\t\t       Loading...");
     sleep(2);
     system("cls");
     printf("\n\n\n\n\t\t\t      [###_______] \n");
     printf("\n\t\t\t       Loading...");
     sleep(2);
     system("cls");
     printf("\n\n\n\n\t\t\t      [####______] \n");
     printf("\n\t\t\t       Loading...");
     sleep(2);
     system("cls");
     printf("\n\n\n\n\t\t\t      [#####_____] \n");
     printf("\n\t\t\t       Loading...");
     sleep(2);
     system("cls");
     printf("\n\n\n\n\t\t\t      [######____] \n");
     printf("\n\t\t\t       Loading...");
     sleep(2);
     system("cls");
     printf("\n\n\n\n\t\t\t      [#######___] \n");
     printf("\n\t\t\t       Loading...");
     sleep(2);
     system("cls");
     printf("\n\n\n\n\t\t\t      [########__] \n");
     printf("\n\t\t\t       Loading...");
     sleep(2);
     system("cls");
     printf("\n\n\n\n\t\t\t      [#########_] \n");
     printf("\n\t\t\t       Loading...");
     sleep(2);
     system("cls");
     printf("\n\n\n\n\t\t\t      [##########] \n");
     printf("\n\t\t\t       Loading...");
     sleep(2);
     system("cls");
     printf("\n\n\n\n\t\t\t      [##########] \n");
     printf("\n\t\t\t       Complete.");
     sleep(2);
     system("cls");
     }
//______________________________________________________________________________     
// Exibe o Nome do Jogo
/* Observe que para exibi��o de um printf de mais de uma linha, as aspas podem 
ser utilizadas da maneira abaixo.

   Obs.: IMPORTANTE !! Se for fazer uma exibi��o de nome como a que tem abaixo
   n�o se esque�a que a contra-barra "\" no compilador � interpretada como um comando.
   para que ela apare�a no seu printf voce deve usar o comando "\\".
   
   Obs2.: N�o T�o Importante !!
          Para maior esclarecimento do resultado das linha a seguir tenha em mente:
               "\t" = Tabula��o (paragrafo)
               "\n" = Quebra de Linha
               "\\" = "\"
    
*/
void nome()
{
printf("\n\n\t\t //)))))    __      ___       __      __                      \n"
           "\t\t ||       //  \\\\   ||  \\\\   //  \\\\  //  \\\\            \n"
           "\t\t ||)))    |    |   ||  //   |       ||  ||                    \n"
           "\t\t ||       |    |   || \\\\    |       ||==||                  \n"
           "\t\t ||       \\\\__//   ||  \\\\   \\\\__//  ||  ||            \n\n"
           "\t\t                 One More Original Title 2011                \n"     
           "\t\t___________________________________________            \n\n\n");       
}    

//______________________________________________________________________________
// Pergunta se Quer Sair do Jogo
// Para mais explica��es sobre os menus do jogo veja a fun��o Menu()

void sair() {
          
int c;//� atribuido ao valor da tecla
int lugar = 0;//diz em qual op��o esta o cursor (ver final da fun��o).
system ("cls");
nome();
printf("\t\t\tVoce realmente deseja sair?\n\n");
printf("\t\t\t\t [  Sim  ]\n"
       "\t\t\t\t    Nao   \n\n" 

       "\t\t //]]]]]]                    \n"
       "\t\t ||     |                    \n"
       "\t\t ||    (oO)      __  ?          \n"
       "\t\t ||    /||\\     (##)           \n"
       "\t\t ||     ||     /|__|--|          \n"    
       "\t\t ||   ______    |  |  |            ");
                    
while (1) {
      
      if (kbhit()) {// kbhit = apertar tecla
         system ("cls");
         nome();
         printf("\t\t\tVoce realmente deseja sair?\n\n");          
         c = tecla();// c ser� atribuido ao valor inteiro da tecla.
         
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
     if(c == 75)//apertou para direita
             {
                lugar++;
                if (lugar>1) {
                   lugar = 0;
                }
             }
     if(c == 77)//apertou para esquerda
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
                       printf("\t\t\tObrigado por jogar Forca 1.01\n\n\n\n\n");
                       printf("\t\t //]]]]]]                    \n"
       "\t\t ||     |                        \n"
       "\t\t ||     |        __             \n"
       "\t\t ||    (xX)    \\(##)            \n"
       "\t\t ||    /||\\     |__|-\\          \n"    
       "\t\t ||  \\  ||  /   |  |  \\        \n"
       "\t\t      \\    /                     ");
       
        
                       sleep(5);
                       exit(0);
                       
             }
             else{
                  menu();
                  }
                  }
     if (lugar == 0) {//imprime as op��es
               
               printf("\t\t\t\t [  Sim  ]\n"
                      "\t\t\t\t    Nao   \n\n"
                      "\t\t //]]]]]]                    \n"
                      "\t\t ||     |                    \n"
                      "\t\t ||    (oO)      __  ?          \n"
                      "\t\t ||    /||\\     (##)           \n"
                      "\t\t ||     ||     /|__|--|          \n"    
                      "\t\t ||   ______    |  |  |            ");
                      
                      }
     if (lugar == 1) {
               printf("\t\t\t\t    Sim   \n"
                      "\t\t\t\t [  Nao  ]\n\n"
                      "\t\t //]]]]]]                    \n"
                      "\t\t ||     |                    \n"
                      "\t\t ||    (oO)      __  ?          \n"
                      "\t\t ||    /||\\     (##)           \n"
                      "\t\t ||     ||     /|__|--|          \n"    
                      "\t\t ||   ______    |  |  |            ");
                                                             
                      }
                          
}
}
}
//______________________________________________________________________________
// Exibe o Nome FORCA ( feito em: ASCII Art Generator )
void nome_enfeitado()
{
system("cls");
loading();
system("cls");

//______________________________________________________________________________

printf("\n     ..................................................................      \n"
"   ..?MMMMMMMMMMMMMM.....................  by One More Original Title inc. .   \n"
"  ...IMMMMMMMMMMMMMM.........................................................  \n"
" ....IMMMM.................................................................... \n"
" ....IMMM................=MMMMMM......MMMMMMMMMM.....MMMMMMM~.......MMMMMMM... \n"
" ....IMMMMMMMMMMMMM....,MMMMMMMMM....MMMMMMMMMMM....MMMMMMMMMM....MMMMMMMMMMM. \n"  
" ....IMMMMMMMMMMMMO...~MMMMM..MMMM...MMMMMM..MMM..,MMMM ...MM....MMMMM ..MMMD. \n"
" ....IMMM.............MMMM.....MMMO..MMMM....MMM .MMMM... ... ..MMMM ....MMM~. \n"
" ....IMMM.............MMM......MMMM..MMM.........$MMM...........MMMN.....MMM:. \n"
" ....IMMM............,MMM......MMM8..MMM.........MMMM...........MMMD.....MMM?. \n"
" ....IMMM.............MMMM....MMMM...MMM.........=MMM:..........MMMM... .MMMM. \n"  
" I...IMMM.............?MMMMMMMMMM~...MMM..........MMMMMMMMMMMM..:MMMMMMMMMMMM. \n"  
" N?..IMMM...............MMMMMMMM.....MMM...........~MMMMMMMMM.....MMMMMMMMMMMM \n"
" .NMD......................................................................... \n"         
" ...$?M7........ ..ZO?N?N?=+?+M7..............I7+M++M?+M??N?MZ7I.............. \n"          
" ......7?M??M+?M?$Z............I7?.......:???O...................7+?.......... \n"         
" ................................++...M+??...........................M?....... \n"       
" .................................I?$??................................$N,.... \n"     
" .... Autoria:     .................?I................................. M?.... \n"     
" ...  Italo Ayres   .................+?N...............................N?..... \n"     
" .... Joao Martins .................. .+?+=.........................$M?......  \n"       
"  ........................................?M?ON.................+??+........   \n"         
"     ......2011............................... M.8?M??????+N?DDMN.........     ");         
         
    
limpa_buffer();

menu();

}
//______________________________________________________________________________
// Exibe Anima��o e Nome Enfeitado
// Pra fazer uma anima��o dessa.. s� quem num tem o que fazer mesmo.

void apresentacao()
{

              
system("cls");
printf("\n\n\n\n\n\n"
"\t\t  ( o) \n"
"\t\t   |\\  \n"
"\t\t  /||\\ \n"
"\t\t  /  \\ \n"); 
sleep(2);

system("cls");
printf("\n\n\n\n\n\n"
"\t\t    ( o) \n"
"\t\t     ||  \n"
"\t\t     ||  \n"
"\t\t     ||  \n");

sleep(2);

system("cls");
printf("\n\n\n\n\n\n"
"\t\t     ( o) \n"
"\t\t      /|  \n"
"\t\t     /||\\ \n"
"\t\t     /  \\ \n");

sleep(2);

system("cls");
printf("\n\n\n\n\n\n"
"\t\t       ( o) \n"
"\t\t        ||  \n"
"\t\t        ||  \n"
"\t\t        ||  \n");
sleep(2);

system("cls");
printf("\n\n\n\n\n\n"
"\t\t        ( o) \n"
"\t\t         |\\  \n"
"\t\t        /||\\ \n"
"\t\t        /  \\ \n"); 
sleep(2);

system("cls");
printf("\n\n\n\n\n\n"
"\t\t          ( o) \n"
"\t\t           ||  \n"
"\t\t           ||  \n"
"\t\t           ||  \n");
sleep(2);

system("cls");
printf("\n\n\n\n\n\n"
"\t\t           ( o) \n"
"\t\t            /|  \n"
"\t\t           /||\\ \n"
"\t\t           /  \\ \n");
sleep(2);

system("cls");
printf("\n\n\n\n\n\n"
"\t\t            ( o) \n"
"\t\t             ||  \n"
"\t\t             ||  \n"
"\t\t             ||  \n");
sleep(2);

system("cls");
printf("\n\n\n\n\n\n"
"\t\t             ( o) \n"
"\t\t              |\\  \n"
"\t\t             /||\\ \n"
"\t\t             /  \\ \n"); 
sleep(2);

system("cls");
printf("\n\n\n\n\n\n"
"\t\t              ( o) \n"
"\t\t               ||  \n"
"\t\t               ||  \n"
"\t\t               ||  \n");
sleep(2);

system("cls");
printf("\n\n\n\n\n\n"
"\t\t               ( o) \n"
"\t\t                /|  \n"
"\t\t               /||\\ \n"
"\t\t               /  \\ \n");
sleep(2);

system("cls");
printf("\n\n\n\n\n\n"
"\t\t                 ( o) \n"
"\t\t                  ||  \n"
"\t\t                  ||  \n"
"\t\t                  ||  \n");
sleep(2);

system("cls");
printf("\n\n\n\n\n\n"
"\t\t                  ( o) \n"
"\t\t                   |\\  \n"
"\t\t                  /||\\ \n"
"\t\t                  /  \\ \n"); 
sleep(2);

system("cls");
printf("\n\n\n\n\n\n"
"\t\t                    ( o) \n"
"\t\t                     ||  \n"
"\t\t                     ||  \n"
"\t\t                     ||  \n");
sleep(2);

system("cls");
printf("\n\n\n\n\n\n"
"\t\t                     ( o) \n"
"\t\t                      /|  \n"
"\t\t                     /||\\ \n"
"\t\t                     /  \\ \n");
sleep(2);

system("cls");
printf("\n\n\n\n\n\n"
"\t\t                       ( o) \n"
"\t\t                        ||  \n"
"\t\t                        ||  \n"
"\t\t                        ||  \n");
sleep(2);

system("cls");
printf("\n\n\n\n\n\n"
"\t\t                        ( o) \n"
"\t\t                         |\\  \n"
"\t\t                        /||\\ \n"
"\t\t                        /  \\ \n"); 
sleep(2);

system("cls");
printf("\n\n\n\n\n\n"
"\t\t                         ( o) \n"
"\t\t                          ||  \n"
"\t\t                          ||  \n"
"\t\t                          ||  \n");
sleep(2);

system("cls");
printf("\n\n\n\n\n\n"
"\t\t                       ? ( o) ? \n"
"\t\t                      ?  \\||/  \n"
"\t\t                          ||  \n"
"\t\t                          ||  \n");
sleep(2);

system("cls");
printf(" .... Joao Martins .................. .+?+=.........................$M?......  \n"       
"  ........................................?M?ON.................+??+........   \n"         
"     ......2011............................... M.8?M??????+N?DDMN.........     \n" 
"\n\n\n"
"\t\t                       ? ( o) ? \n"
"\t\t                      ?  \\||/  \n"
"\t\t                          ||  \n"
"\t\t                          ||  \n");
sleep(2);

system("cls");
printf(" ......7?M??M+?M?$Z............I7?.......:???O...................7+?.......... \n"         
" ................................++...M+??...........................M?....... \n"       
" .................................I?$??................................$N,.... \n"     
" .... Autoria:     .................?I................................. M?.... \n"     
" ...  Italo Ayres   .................+?N...............................N?..... \n"     
" .... Joao Martins .................. .+?+=.........................$M?......  \n"       
"  ........................................?M?ON.................+??+........   \n"         
"     ......2011............................... M.8?M??????+N?DDMN.........     \n" 

"\t\t                      ?  \\/|/  \n"
"\t\t                          ||  \n"
"\t\t                          ||  \n");
sleep(2);

system("cls");
printf(" ....IMMM.............MMMM.....MMMO..MMMM....MMM .MMMM... ... ..MMMM ....MMM~. \n"
" ....IMMM.............MMM......MMMM..MMM.........$MMM...........MMMN.....MMM:. \n"
" ....IMMM............,MMM......MMM8..MMM.........MMMM...........MMMD.....MMM?. \n"
" ....IMMM.............MMMM....MMMM...MMM.........=MMM:..........MMMM... .MMMM. \n"  
" I...IMMM.............?MMMMMMMMMM~...MMM..........MMMMMMMMMMMM..:MMMMMMMMMMMM. \n"  
" N?..IMMM...............MMMMMMMM.....MMM...........~MMMMMMMMM.....MMMMMMMMMMMM \n"
" .NMD......................................................................... \n"         
" ...$?M7........ ..ZO?N?N?=+?+M7..............I7+M++M?+M??N?MZ7I.............. \n"          
" ......7?M??M+?M?$Z............I7?.......:???O...................7+?.......... \n"         
" ................................++...M+??...........................M?....... \n"       
" .................................I?$??................................$N,.... \n"     
" .... Autoria:     .................?I................................. M?.... \n"     
" ...  Italo Ayres   .................+?N...............................N?..... \n"     
" .... Joao Martins .................. .+?+=.........................$M?......  \n"       
"  ........................................?M?ON.................+??+........   \n"         
"     ......2011............................... M.8?M??????+N?DDMN.........     ");
sleep(2);

system("cls");
printf("\n     ..................................................................      \n"
"   ..?MMMMMMMMMMMMMM.....................  by One More Original Title inc. .   \n"
"  ...IMMMMMMMMMMMMMM.........................................................  \n"
" ....IMMMM.................................................................... \n"
" ....IMMM................=MMMMMM......MMMMMMMMMM.....MMMMMMM~.......MMMMMMM... \n"
" ....IMMMMMMMMMMMMM....,MMMMMMMMM....MMMMMMMMMMM....MMMMMMMMMM....MMMMMMMMMMM. \n"  
" ....IMMMMMMMMMMMMO...~MMMMM..MMMM...MMMMMM..MMM..,MMMM ...MM....MMMMM ..MMMD. \n"
" ....IMMM.............MMMM.....MMMO..MMMM....MMM .MMMM... ... ..MMMM ....MMM~. \n"
" ....IMMM.............MMM......MMMM..MMM.........$MMM...........MMMN.....MMM:. \n"
" ....IMMM............,MMM......MMM8..MMM.........MMMM...........MMMD.....MMM?. \n"
" ....IMMM.............MMMM....MMMM...MMM.........=MMM:..........MMMM... .MMMM. \n"  
" I...IMMM.............?MMMMMMMMMM~...MMM..........MMMMMMMMMMMM..:MMMMMMMMMMMM. \n"  
" N?..IMMM...............MMMMMMMM.....MMM...........~MMMMMMMMM.....MMMMMMMMMMMM \n"
" .NMD......................................................................... \n"         
" ...$?M7........ ..ZO?N?N?=+?+M7..............I7+M++M?+M??N?MZ7I.............. \n"          
" ......7?M??M+?M?$Z............I7?.......:???O...................7+?.......... \n"         
" ................................++...M+??...........................M?....... \n"       
" .................................I?$??................................$N,.... \n"     
" .... Autoria:     .................?I................................. M?.... \n"     
" ...  Italo Ayres   .................+?N...............................N?..... \n"     
" .... Joao Martins .................. .+?+=.........................$M?......  \n"       
"  ........................................?M?ON.................+??+........   \n"         
"     ......2011............................... M.8?M??????+N?DDMN.........     ");
limpa_buffer();
menu();
}

//
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
    printf("\t\t\t\t[  Mudar Cor  ]\n"
           "\t\t\t\t   Categoria\n"
           "\t\t\t\t  Efeitos 3-D\n" 
           "\t\t\t\t    Voltar");
 while (1) {
  if (kbhit()) {//80 = Baixo, 72 = Cima, 77 = esquerda, 75 = direita, 13 = enter
           
              system ("cls");
              nome();
              c = tecla();// atribui um valor inteiro a "c" chamando a fun��o "tecla()"
             
             
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
     if(c == 77)  {
                lugar++;
                if (lugar>3) {
                   lugar = 0;
                }
             }
     if(c == 75)  {
                lugar--;
                if (lugar<0) {
                   lugar = 3;
                             }
                             }
     if(c == 13)  {
             switch (lugar){
                    case 0://Mudar Cor
                         system("cls");
                         cor();
                         opcoes();
                    case 1://categorias
                         system("cls");
                         nome();
                         menu_categoria();
                         opcoes();
                    case 2://efeitos 3d 
                         system("cls");
                         nome();
                         printf("\n\n\t\tSua Placa de Video nao da suporte a essa configuracao.");
                         getchar();
                         opcoes();
                         
                    case 3:// Voltar    
                       
                         menu();
                         }
                         }             
             
      if (lugar == 0)
      {
           printf("\t\t\t\t[  Mudar Cor  ]\n"
                  "\t\t\t\t   Categoria   \n"
                  "\t\t\t\t  Efeitos 3-D   \n" 
                  "\t\t\t\t    Voltar");
      }
      else if (lugar == 1) 
      {
           printf("\t\t\t\t   Mudar Cor   \n"
                  "\t\t\t\t[  Categoria  ]\n"
                  "\t\t\t\t  Efeitos 3-D\n" 
                  "\t\t\t\t    Voltar");  
           
           
      }
      else if (lugar == 2) 
      {
           printf("\t\t\t\t   Mudar Cor   \n"
                  "\t\t\t\t   Categoria\n"
                  "\t\t\t\t[ Efeitos 3-D ]\n" 
                  "\t\t\t\t    Voltar");  
           
           
      }
      else if (lugar == 3) 
      {
           printf("\t\t\t\t   Mudar Cor   \n"
                  "\t\t\t\t   Categoria\n"
                  "\t\t\t\t  Efeitos 3-D\n" 
                  "\t\t\t\t[   Voltar    ]");  
                  
           }
          
                                                       
}//Fecha o If(1)
}//Fecha o While    
}//Fecha Fun��o      
    
    

//______________________________________________________________________________
// Ativa a Mudan�a de Cor Pelo Pressionamento das Teclas
// Para mais explica��es sobre os menus do jogo veja a fun��o Menu()

/* Essa foi particularmente dificil de entender pra mim, ja que peguei a �deia
dessa fun��o de um outro jogo que me serviu de inspira��o para come�ar esse projeto.

Para a fun��o de troca de cor, voce deve entender duas coisas essenciais.
* A troca de Cores se faz num matriz onde o termo [6] modifica a cor do fundo
e o termo [7] modifica a cor das letras.
* O registro das Cores est� em caracteres especificos que devem ser colocados
nos lugares certos dentro da matriz "cor".

Algumas Cores e Suas representa��es em caracteres:
'F' = Preto
'E' = branco
'D' = rosa
'C' = vermelho
'B' = Azul claro
'A' = verde
'9' = Azul escuro
'8' = cinza
'7' = cinza claro
'6' = amarelo mostarda
'5' = roxo
'4' = vinho
'3' = azulzinho
        
Para que a troca de cores seja efetuada completamente, a tela deve ser limpa
usando o system("cls"); e a chamada de fun��o system(cor);. Caso contrario
somente as proximos caracteres adicionados ganhar�o a nova cor. (isso, dependendo
do caso, tambem pode ser uma vantagem).
*/

void cor()
{
 char cor[10] = "Color 0f";
 int c, cor_l = 0,cor_f = 0, lugar=0;
 
 system("cls");
 nome();
 printf("\t\t         Use as Setas Direcionais para   \n"
            "\t\t          Alterar as Cores do Sistema  \n\n"
            "\t\t                   [ENTER]               \n"
            "\t\t             Para voltar ao Menu \n"
          "\n\t\t                 [  Letra  ]\n"
            "\t\t                    Fundo \n");      
 
 while(1){
 
 if (kbhit()) {
     
     c = tecla();        
          
     if(c == 75) {
                
                
              if (lugar == 0){  
                 cor_l++;
                 if (cor_l>5) {
                   cor_l = 0;
                   }
                   }
             if (lugar==1) {
                  cor_f++;
                if (cor_f>5) {
                   cor_f = 0;
                  }      
                  }         
             }
     if(c == 77) {
                if (lugar == 0){  
                    cor_l--;
                    if (cor_l<0) {
                       cor_l = 5;
                       }
                       }
            if (lugar==1) {
                  cor_f--;
                  if (cor_f<0) {
                   cor_f = 5;
                  }      
                  }         
             }
     if(c == 80)  {
                lugar++;
                if (lugar>1) {
                   lugar = 0;
                }
             }
     if(c == 72)  {
                lugar--;
                if (lugar<0) {
                   lugar = 1;
                             }
                             }
     if(c == 13)  {   
                  system("cls");
                  system(cor);
                  opcoes();
                  
                  
                  }
 
     switch (cor_l) {
            case 0:
                 cor[7] = '7';
                 break;
            case 1:     
                 cor[7] = 'C';
                 break;
            case 2:
                 cor[7] = 'A';
                 break;
            case 3:
                 cor[7] = '9';
                 break;     
            case 4:               
                 cor[7] = 'E';
                 break;
            case 5:
                 cor[7] = 'F';
                 break;     
                 
            } //fim do switch 1      
     switch (cor_f) {
            case 0:
                 cor[6] = '0';
                 break;
            case 1:     
                 cor[6] = 'C';
                 break;
            case 2:
                 cor[6] = 'A';
                 break;
            case 3:
                 cor[6] = '9';
                 break;     
            case 4:               
                 cor[6] = 'E';
                 break;
            case 5:               
                 cor[6] = 'F';
                 break;     
                 
            }//fim do switch 2              
           
            system("cls");
            system(cor);
            nome();
            
if (lugar == 0){
 
 printf("\t\t         Use as Setas Direcionais para   \n"
            "\t\t          Alterar as Cores do Sistema  \n\n"
            "\t\t                   [ENTER]               \n"
            "\t\t             Para voltar ao Menu \n"
          "\n\t\t                 [  Letra  ]\n"
            "\t\t                    Fundo \n");
}
else{
     
 printf("\t\t         Use as Setas Direcionais para   \n"
            "\t\t          Alterar as Cores do Sistema  \n\n"
            "\t\t                   [ENTER]               \n"
            "\t\t             Para voltar ao Menu \n"
          "\n\t\t                    Letra  \n"
            "\t\t                 [  Fundo  ]\n");                                      
}           
}
}//fim do while
}//fim da fun��o
//______________________________________________________________________________
// Limpa Qualquer Caractere que esteja na tela e funciona como system("pause")
// Aprovado por Ulysses de Oliveira

void limpa_buffer(){
char x;     
     
     
     do {
        x = getchar();
     }while ((x != '\n')&&(x != EOF));
     
}   
//______________________________________________________________________________
// Exibe os Cr�ditos

/* Perceba que tantos printf's poderiam ter sido evitados se eu usasse uma fun��o
apenas para imprimir as palavras e chamasse ela entre as diferentes imagem. */

void creditos() {
    
    system("cls");
          
    printf("\n\n\n\t\t\t\tForca 1.01      \n"
    "\t\t___________________________________________\n\n"
           "\t\tCriado por: Italo Ayres e Joao Martins\n\n" 
                      
           "\t\tBaixe Aqui o Codigo Fonte: http://db.tt/YBc1wZF\n\n"
           
           "\t\tSoftware de Distribuicao Livre\n"
           "\t\t              by One More Original Title. 2011\n\n");
           
           
printf("\t\t //]]]]]]                    \n"
       "\t\t ||     |                    \n"
       "\t\t ||              __             \n"
       "\t\t ||             (##)           \n"
       "\t\t ||            /|__|--|          \n"    
       "\t\t ||   ______    |  |  |            ");
  
    sleep(500);
    system("cls");
    
    printf("\n\n\n\t\t\t\tForca 1.01      \n"
    
  "\t\t___________________________________________\n\n"
           "\t\tCriado por: Italo Ayres e Joao Martins\n\n" 
                      
           "\t\tBaixe Aqui o Codigo Fonte: http://db.tt/YBc1wZF\n\n"
           
           "\t\tSoftware de Distribuicao Livre\n"
           "\t\t              by One More Original Title. 2011\n\n");
    
    printf("\t\t //]]]]]]                    \n"
       "\t\t ||     |                    \n"
       "\t\t ||    (oO)      __             \n"
       "\t\t ||             (##)           \n"
       "\t\t ||            /|__|--|          \n"    
       "\t\t ||   ______    |  |  |            ");
  
    sleep(500);
    system("cls");
    
    printf("\n\n\n\t\t\t\tForca 1.01      \n"
    "\t\t___________________________________________\n\n"
           "\t\tCriado por: Italo Ayres e Joao Martins\n\n" 
                      
           "\t\tBaixe Aqui o Codigo Fonte: http://db.tt/YBc1wZF\n\n"
           
           "\t\tSoftware de Distribuicao Livre\n"
           "\t\t              by One More Original Title. 2011\n\n");
    
    printf("\t\t //]]]]]]                    \n"
       "\t\t ||     |                    \n"
       "\t\t ||    (oO)      __             \n"
       "\t\t ||     ||      (##)           \n"
       "\t\t ||            /|__|--|          \n"    
       "\t\t ||   ______    |  |  |            ");
  
    sleep(500);
    system("cls");
    
    printf("\n\n\n\t\t\t\tForca 1.01      \n"
    "\t\t___________________________________________\n\n"
           "\t\tCriado por: Italo Ayres e Joao Martins\n\n" 
                      
           "\t\tBaixe Aqui o Codigo Fonte: http://db.tt/YBc1wZF\n\n"
           
           "\t\tSoftware de Distribuicao Livre\n"
           "\t\t              by One More Original Title. 2011\n\n");
    
    printf("\t\t //]]]]]]                    \n"
       "\t\t ||     |                    \n"
       "\t\t ||    (oO)      __             \n"
       "\t\t ||    /||\\     (##)           \n"
       "\t\t ||            /|__|--|          \n"    
       "\t\t ||   ______    |  |  |            ");
  
    sleep(500);
    system("cls");
    printf("\n\n\n\t\t\t\tForca 1.01      \n"
           "\t\t___________________________________________\n\n"
           "\t\tCriado por: Italo Ayres e Joao Martins\n\n" 
                      
           "\t\tBaixe Aqui o Codigo Fonte: http://db.tt/YBc1wZF\n\n"
           
           "\t\tSoftware de Distribuicao Livre\n"
           "\t\t              by One More Original Title. 2011\n\n");
    
    printf("\t\t //]]]]]]                    \n"
       "\t\t ||     |                    \n"
       "\t\t ||    (oO)      __             \n"
       "\t\t ||    /||\\     (##)           \n"
       "\t\t ||     ||     /|__|--|          \n"    
       "\t\t ||   ______    |  |  |            ");
  
    
    
       limpa_buffer();
       
  
    system("cls");
    printf("\n\n\n\t\t\t\tForca 1.01      \n"
           "\t\t___________________________________________\n\n"
           "\t\tCriado por: Italo Ayres e Joao Martins\n\n" 
                      
           "\t\tBaixe Aqui o Codigo Fonte: http://db.tt/YBc1wZF\n\n"
           
           "\t\tSoftware de Distribuicao Livre\n"
           "\t\t              by One More Original Title. 2011\n\n");
    
    printf("\t\t //]]]]]]                    \n"
       "\t\t ||     |                    \n"
       "\t\t ||    (oO)      __             \n"
       "\t\t ||    /||\\     (##)           \n"
       "\t\t ||     ||     /|__|-\\          \n"    
       "\t\t ||   ______    |  |  \\            ");
       
       sleep(2);
       system("cls");
    printf("\n\n\n\t\t\t\tForca 1.01      \n"
           "\t\t___________________________________________\n\n"
           "\t\tCriado por: Italo Ayres e Joao Martins\n\n" 
                      
           "\t\tBaixe Aqui o Codigo Fonte: http://db.tt/YBc1wZF\n\n"
           
           "\t\tSoftware de Distribuicao Livre\n"
           "\t\t              by One More Original Title. 2011\n\n");
            
    
    printf("\t\t //]]]]]]                    \n"
       "\t\t ||     |                        \n"
       "\t\t ||     |        __             \n"
       "\t\t ||    (xX)    \\(##)            \n"
       "\t\t ||    /||\\     |__|-\\          \n"    
       "\t\t ||  \\  ||  /   |  |  \\        \n"
       "\t\t      \\    /                      ");
       
       sleep(2);        
       menu();
       
}        


//______________________________________________________________________________
// Pede Para a pessoa apertar enter para continuar

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
    printf("\t\t    Em Forca, seu objetivo sera adivinhar a palavra\n"
           "\t\t oculta, dando palpites sobre as letras dessa palavra.\n"
           "\t\t    Para tentar uma letra, digite-a no seu teclado.\n"
           "\t\t Se existir a letra na palavra, esta aparecera, porem,\n"
           "\t\t se a palavra nao tiver a letra, uma parte do corpo\n"
           "\t\t do boneco sera adicionada a forca, indicando o erro.\n"
           "\t\t    Ao todo sao permitidos seis erros, e se ultrapassados\n"
           "\t\t o jogo estara terminado e voce sera direcionado ao Menu\n"
           "\t\t principal.\n\n"
           "\t\t\t Forca 2011 by One More Original Title.");
    
    limpa_buffer();
    menu();               


}
//______________________________________________________________________________
/* Como ler caracteres sem Enter (de Batalha Naval 3.17 por H.N. Softwares.)

         Essa fun��o deve ser definida quando se espera que o usu�rio digite uma
   tecla e faz com que ela seja lida como um numero do codigo ASCII.
         Como funciona:
                       O while(1) � definido para gerar um loop infinito, e nesse caso,
              serve para repetir a fun��o at� que seja reconhecido o pressionamento
              de uma tecla qualquer. O comando kbhit(), ou traduzindo: Key Board Hit, 
              � o meio utilizado para continuar apenas se uma tecla for pressionada.
                       Logo em Seguida, a variavel "vartecla" � atribuida ao inteiro
              que representa a tecla.( Para descobrir o valor de uma tecla adicione
              ao final da fun��o: printf("%d", vartecla); ). Como o retorno da fun��o
              � a vari�vel "vartecla", para chamar a fun��o mais tarde, basta atribui-la
              � uma vari�vel qualquer. (ex.: c = tecla() )
               
         
   
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
             //printf("tecla = %d\n", vartecla);
             //Usado para saber valor da tecla digitada
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
       "\t\t\t\t   Creditos  \n"
       "\t\t\t\t    Opcoes   \n"    
       "\t\t\t\t Apresentacao \n"
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
                if (lugar>5) {
                   lugar = 0;
                   }         
             }
     if(c == 72) {
                lugar--;
                if (lugar<0) {
                        lugar = 5;
                        }
             }
     if(c == 75)  {
                lugar--;
                if (lugar>5) {
                   lugar = 0;
                }
             }
     if(c == 77)  {
                lugar++;
                if (lugar<0) {
                   lugar = 5;
                             }
                             }
     if(c == 13)  {
             switch (lugar){
                    case 0://Jogar
                         jogar();
                    case 1://Instru��es
                         instrucoes();
                    case 2://Creditos 
                         creditos();
                    case 3://Op��es     
                         opcoes();     
                    case 4://apresentacao
                         apresentacao();
                    case 5://Sair          
                         sair();
                         }             
             }            
  
//______________________________________________________________________________
// Menu :Imprimir Menu:
                  //printf("lugar = %d, tecla = %d\n", lugar, c);
                  //Usado para saber valor da tecla digitada
                  
                  if (lugar == 0)
                  {
                       printf("\t\t\t\t[   Jogar    ]\n"
                              "\t\t\t\t  Instrucoes \n"
                              "\t\t\t\t   Creditos  \n"
                              "\t\t\t\t    Opcoes   \n"        
                              "\t\t\t\t Apresentacao \n"
                              "\t\t\t\t     Sair    \n");  
                       
                  }
                  else if (lugar == 1) 
                  {
                       printf("\t\t\t\t    Jogar \n"
                              "\t\t\t\t[ Instrucoes ]\n"
                              "\t\t\t\t   Creditos  \n"
                              "\t\t\t\t    Opcoes   \n"           
                              "\t\t\t\t Apresentacao \n"
                              "\t\t\t\t     Sair    \n");  
                       
                       
                  }
                  else if (lugar == 2) 
                  {
                       printf("\t\t\t\t    Jogar \n"
                              "\t\t\t\t  Instrucoes \n"
                              "\t\t\t\t[  Creditos  ]\n"
                              "\t\t\t\t    Opcoes   \n"           
                              "\t\t\t\t Apresentacao \n"
                              "\t\t\t\t     Sair    \n");  
                       
                       
                  }
                  else if (lugar == 3) 
                  {
                       printf("\t\t\t\t    Jogar \n"
                              "\t\t\t\t  Instrucoes \n"
                              "\t\t\t\t   Creditos  \n"
                              "\t\t\t\t[   Opcoes   ]\n"           
                              "\t\t\t\t Apresentacao \n"
                              "\t\t\t\t     Sair    \n");
                              }
                  
                  else if (lugar == 4) 
                  {
                       printf("\t\t\t\t    Jogar \n"
                              "\t\t\t\t  Instrucoes \n"
                              "\t\t\t\t   Creditos \n"
                              "\t\t\t\t    Opcoes \n"           
                              "\t\t\t\t[Apresentacao]\n"
                              "\t\t\t\t     Sair     \n");  
                              
                       }
                  
                  
                  else if (lugar == 5) 
                  {
                       printf("\t\t\t\t    Jogar \n"
                              "\t\t\t\t  Instrucoes \n"
                              "\t\t\t\t   Creditos \n"
                              "\t\t\t\t    Opcoes \n"           
                              "\t\t\t\t Apresentacao \n"
                              "\t\t\t\t[    Sair    ]\n");  
                              
                       }    
                                                         
}//Fecha o If(1)
}//Fecha o While    
}//Fecha Fun��o

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
                         Finalmente o Jogo Come�a !!                          

-------------------------------------
FUN��ES RELATIVAS AO JOGO EM SI:
-------------------------------------*/


//______________________________________________________________________________
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

void display(void) 
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
//Se errado, adiciona um � vari�vel erros*/             
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
            if(c == 75)//apertou para direita
            {
                lugar++;
                if (lugar>1) 
                   lugar = 0;
            }
            if(c == 77)//apertou para esquerda
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


/*                       Finalmente o Jogo Termina...
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */



//______________________________________________________________________________
//Inicio do Programa
     
int main()
{
// Vari�veis:

//______________________________________________________________________________     
// Chamada de Fun��es:     
                   
     loading();
     aperte_enter();
     menu();
         
}
     
//______________________________________________________________________________
// Exras
/*
* * Para um N�mero Randomico * * * * * * * * * * * * * * * * * * * * * * * * * *
     
     #include <time.h>
     srand ( time(NULL) );
     int num = rand()%9//Aqui entra o numero maximo;
     
 * * Para Capturar Tecla * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 
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
 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

Outros Coment�rios:
       
       Para esclarecer a divis�o de tarefa dos autores do jogo:
            
            Italo Ayres foi respons�vel pelos Menus do jogo e todas a fun��es
                        referentes a eles, como: mudan�a de cor, captura de
                        tecla, anima��es e efeitos tridimensionais.      
           
           Jo�o Martins idealizou e contruiu tudo que se refere ao jogo em si, 
                        onde inclui-se o sistema de letras, vidas, categorias, 
                        ramdomiza��o das palavras e o extenso database do jogo.
                         
     The One More Original Title trata-se na verdade de uma empresa totalmente
     fict�cia (noossa que surpresa), porem todos os direitos de copyright est�o
     reservados.. (anh?).
     
     
     "Faltou s� o bye bye para finalizar"
                ( Ulysses sobre o jogo forca )
     
     "Na Uni�o Sovietica a Forca mata VOCE"
                ( Reversal Russa sem sentido sobre a Forca)
                
     "Esse tipo de jogo n�o tem a menor gra�a..."                          
                ( Tiradentes sobre Forca )
      
     "Como assim minha placa de video n�o suporta acelera��o 3-D ?"
                ( Iury Rog�rio indignado com seu Sony Vaio Core i7 )               
*/
