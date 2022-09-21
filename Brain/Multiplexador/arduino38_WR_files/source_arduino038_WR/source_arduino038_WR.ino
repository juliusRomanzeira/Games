/*
   Curso de Arduino e AVR WR Kits Channel
   
   Aula 38 - Displays de 7 segmentos multiplexados
   
   Autor: Eng. Wagner Rambo  Data: Outubro de 2015
   
   www.wrkits.com.br | facebook.com/wrkits | youtube.com/user/canalwrkits
   
     _______
    |   a   |
    | f   b |
    |_______|
    |   g   |
    | e   c |
    |_______|
        d
*/

// --- Mapeamento de Hardware ---
#define disp1   9                            //Display mais significativo no digital 9
#define disp2  10                            //Display menos significativo no digital 10
#define mais   11                            //Botão para incremento no digital 11
#define menos  12                            //Botão para decremento no digital 12


// --- Protótipo das Funções Auxiliares ---
int display7seg(int number);                 //Retorna o dado para o barramento do display
void multiplex(int value);                   //Faz a multiplexação do display
void changeCounter();                        //Modifica o valor do contador através dos botões


// --- Variáveis Globais ---
int dez,                                     //Armazena o valor da dezena
    uni,                                     //Armazena o valor da unidade
    counter = 96;                          //Variável para contagem
    
boolean flagMais, 
        flagMenos;


// --- Configurações Iniciais ---
void setup()
{
   for(char i= 0; i< 7; i++)  pinMode(i,       OUTPUT); //Saídas (barramento do display no PORTD)
   for(char j= 9; j<11; j++)  pinMode(j,       OUTPUT); //Saídas (controle do display)
   for(char k=11; k<13; k++)  pinMode(k, INPUT_PULLUP); //Entrada botões
   
   digitalWrite(disp1, LOW);
   digitalWrite(disp2, LOW);
   
   flagMais  = 0x00; 
   flagMenos = 0x00;


} //end setup


// --- Loop Infinito ---
void loop()
{
   
   
   changeCounter();
   
   multiplex(counter);



} //end loop


// --- Desenvolvimento das Funções Auxiliares ---
int display7seg(int number)
{
  int catodo;                                  //Variável que receberá o número indexado ao vetor
  
  //Declaração e inicialização do vetor segmento
  int segmento[10] = {0x3f,                    //Dado referente ao BCD '0'
                      0x06,                    //Dado referente ao BCD '1'
                      0x5b,                    //Dado referente ao BCD '2'
                      0x4f,                    //Dado referente ao BCD '3'
                      0x66,                    //Dado referente ao BCD '4'
                      0x6d,                    //Dado referente ao BCD '5'
                      0x7d,                    //Dado referente ao BCD '6'
                      0x07,                    //Dado referente ao BCD '7'
                      0x7f,                    //Dado referente ao BCD '8'
                      0x67};                   //Dado referente ao BCD '9'
  
  catodo = segmento[number];  
  
  return(catodo);

} //end display7seg


void multiplex(int value)
{
   dez = value/10;
   PORTD = display7seg(dez);
   digitalWrite(disp1, HIGH);
   delay(1);
   digitalWrite(disp1, LOW);
   
   uni = value%10;
   PORTD = display7seg(uni);
   digitalWrite(disp2, HIGH);
   delay(1);
   digitalWrite(disp2,  LOW);

} //end multiplex


void changeCounter()
{

   
   if(!digitalRead( mais)) flagMais  = 0x01;
   if(!digitalRead(menos)) flagMenos = 0x01;
   
   if(digitalRead(mais) && flagMais)
   {
      flagMais = 0x00;
      counter++;
      
      if(counter == 100) counter = 0x00;
   }
   
   if(digitalRead(menos) && flagMenos)
   {
      flagMenos = 0x00;
      counter--;
      
      if(counter == 0) counter = 100;
   }


} //end changeCounter












