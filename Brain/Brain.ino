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

void setup(){
  Serial.begin(9600);
  
  pinMode(azul, OUTPUT);
  pinMode(verm, OUTPUT);
  pinMode(ama, OUTPUT);

  pinMode(bot1, INPUT_PULLUP);
  pinMode(bot2, INPUT_PULLUP);
  pinMode(bot3, INPUT_PULLUP);
  pinMode(bot4, INPUT);

  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}

void loop(){
  
  if(digitalRead(bot4) == 1){
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
      delay(1000);
      if(digitalRead(bot1)!=esc1 || digitalRead(bot2) !=esc2 || digitalRead(bot3) !=esc3){
        while(aux <= 3){
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
        score = score+1;
      }
    }
    scores[player] = score;
    if (i == 1 && player>0){
    Serial.print("Jogador ");
    Serial.print(player);
    Serial.print(" marcou ");
    Serial.print(scores[player]);
    Serial.print(" Pontos\n");
    /*unidade = score%10;
    dezena = (score/10)%10;
    Serial.println(score);
    Serial.println(dezena);
    Serial.println(unidade);
    if(unidade == 0){
    digitalWrite(d2,0);
    digitalWrite(a, 1);
    digitalWrite(b, 1);
    digitalWrite(c, 1);
    digitalWrite(d, 1);
    digitalWrite(e, 1);
    digitalWrite(f, 1);
    digitalWrite(g, 0);
    }
    else if(unidade == 1){
    digitalWrite(d2,0);
    digitalWrite(a, 0);
    digitalWrite(b, 1);
    digitalWrite(c, 1);
    digitalWrite(d, 0);
    digitalWrite(e, 0);
    digitalWrite(f, 0);
    digitalWrite(g, 0);
    delay(1000);
  }
  else if(unidade == 2){
    digitalWrite(d2,0);
    digitalWrite(a, 1);
    digitalWrite(b, 1);
    digitalWrite(c, 0);
    digitalWrite(d, 1);
    digitalWrite(e, 1);
    digitalWrite(f, 0);
    digitalWrite(g, 1);
    delay(1000);
  }
  else if(unidade == 3){
    digitalWrite(d2,0);
    digitalWrite(a, 1);
    digitalWrite(b, 1);
    digitalWrite(c, 1);
    digitalWrite(d, 1);
    digitalWrite(e, 0);
    digitalWrite(f, 0);
    digitalWrite(g, 1);
     delay(1000);
  }
  else if(unidade == 4){
      digitalWrite(d2,0);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 0);
      digitalWrite(d, 0);
      digitalWrite(e, 0);
      digitalWrite(f, 1);
      digitalWrite(g, 1);
      delay(1000);
    }
  else if(unidade == 5){
      digitalWrite(d2,1);
      digitalWrite(a, 1);
      digitalWrite(b, 0);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 0);
      digitalWrite(f, 1);
      digitalWrite(g, 1); 
      delay(1000);
    }
    else if(unidade == 6){
      digitalWrite(d2,0);
      digitalWrite(a, 1);
      digitalWrite(b, 0);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(f, 1);
      digitalWrite(g, 1); 
      delay(1000);
    }
    else if(unidade == 7){
      digitalWrite(d2,0);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 0);
      digitalWrite(e, 0);
      digitalWrite(f, 0);
      digitalWrite(g, 0); 
      delay(1000);
    }
    else if(unidade == 8){
      digitalWrite(d2,0);
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 1);
      digitalWrite(f, 1);
      digitalWrite(g, 1); 
      delay(1000);
    }
    else if(unidade == 9){
      digitalWrite(d2,0);    
      digitalWrite(a, 1);
      digitalWrite(b, 1);
      digitalWrite(c, 1);
      digitalWrite(d, 1);
      digitalWrite(e, 0);
      digitalWrite(f, 1);
      digitalWrite(g, 1);
      delay(1000);
  }*/
    i = 0;
    }
}
