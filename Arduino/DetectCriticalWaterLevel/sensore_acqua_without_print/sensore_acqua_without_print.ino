/**
 * Author: Luca Alessandrini
 * Description ITA / ENG
 * Code comments: ITA
 * 
 * ENG: realization of a critical water level detector. When the water goes below a certain level, we have to turn on a LED. This is the version without print on terminal
 * ITA: realizzazione di un riconoscitore del livello critico dell'acqua. Quando l'acqua scende al di sotto di un certo livello, dobbiamo accendere un LED. Questa è la versione senza stampe a terminale
 */
 
//Quando il sensore è asciutto il valore letto è 0. Man mano che l'acqua sale, il valore letto aumenta.
//Dichiarazione del valore critico
const int valore_critico = 400;

void setup(){
  Serial.begin(9600);
  pinMode(12, OUTPUT);
}

void loop(){
  //Leggo il valore dal sensore
  int sensorValue = analogRead(A0);
  
  if (sensorValue <= valore_critico){
    digitalWrite(12,HIGH); //Accendi led
  }
  else{
    digitalWrite(12,LOW); //Spegni led
  }
  //Attendo un secondo
  delay(1000);
}
