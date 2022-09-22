int const azul = A5;
int const verm = A4;
int const ama = A3;

int const bot1 = 2;
int const bot2 = 3;
int const bot3 = 4;
int const bot4 = 12;

int const d1 = A1;
int const d2 = A2;

int const a = 5;
int const b = 6;
int const c = 7;
int const d = 8;
int const e = 9;
int const f = 10;
int const g = 11;

int dif[4] = {1000,500,400};
int aux = 1;
int i = 1;
int esc1;
int esc2;
int esc3;
int score = 0;
int scores[8]; 

int unidade;
int dezena;

int player = 0;

int estado =0;
int iniciar = 0;


void setup(){
  Serial.begin(9600);
  
  pinMode(azul, OUTPUT);
  pinMode(verm, OUTPUT);
  pinMode(ama, OUTPUT);

  pinMode(bot1, INPUT_PULLUP);
  pinMode(bot2, INPUT_PULLUP);
  pinMode(bot3, INPUT_PULLUP);
  pinMode(bot4, INPUT);
}

void loop() {
  while(!iniciar){
    
  if(digitalRead(bot4)){
    
    estado++;
    delay(400);
    
    if(estado==1){
      digitalWrite(azul, 1);
    }
    else if(estado==2){
      digitalWrite(azul, 1);
      digitalWrite(verm, 1);
    }
    else if(estado==3){
      digitalWrite(azul, 1);
      digitalWrite(verm, 1);
      digitalWrite(ama, 1);
    }
    else if(estado==4){
      digitalWrite(azul, 1);
      digitalWrite(verm, 0);
      digitalWrite(ama, 0);
      estado = 1;
    }
    
    Serial.println(estado);
  }
  else if(digitalRead(bot1) && estado > 0){
    iniciar = 1;
    break;
  }
       
  }
  if(iniciar == 1){
  Serial.print("Você selecionou a Dificuldade ");
  Serial.println(estado);
  Serial.println("Aperte o Botão 4 para iniciar no nível desejado");
  iniciar = 2;
  delay(400);
  }
  else if(digitalRead(bot4)){
    digitalWrite(azul, 0);
  digitalWrite(verm, 0);
  digitalWrite(ama, 0);
    iniciar = 3;
    delay(400);
  }
  else if(iniciar == 3){
    if(player >= 8){
      player = 0;
    }
    player++;
    i = 1;
    score = 0;
    while(1){
      delay(2000);
      esc1 = random(0,2);
      esc2 = random(0,2);
      esc3 = random(0,2);
      
      digitalWrite(azul, esc1);
      digitalWrite(verm, esc2);
      digitalWrite(ama, esc3);
      delay(dif[estado-1]);
      if(digitalRead(bot1)!=esc1 || digitalRead(bot2) !=esc2 || digitalRead(bot3) !=esc3){
        while(aux <= 5){
          digitalWrite(azul, 1);
          digitalWrite(verm, 1);
          digitalWrite(ama, 1);
          delay(500);
          digitalWrite(azul, 0);
          digitalWrite(verm, 0);
          digitalWrite(ama, 0);
          delay(500);
          aux++;
        }
        aux=0;
        break;
        }
        score = score+100;
      }
    }
    scores[player] = score;
    if (i == 1 && player>0){
    Serial.print("\nJogador ");
    Serial.print(player);
    Serial.print(" marcou ");
    Serial.print(scores[player]);
    Serial.print(" Pontos\n");
    i = 0;
    iniciar = 0;
    }
  }
