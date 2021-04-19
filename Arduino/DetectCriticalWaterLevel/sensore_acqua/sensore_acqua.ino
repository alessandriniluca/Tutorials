/**
 * Author: Luca Alessandrini
 * Description ITA / ENG
 * Code comments: ITA
 * 
 * ENG: realization of a critical water level detector. When the water goes below a certain level, we have to turn on a LED
 * ITA: realizzazione di un riconoscitore del livello critico dell'acqua. Quando l'acqua scende al di sotto di un certo livello, dobbiamo accendere un LED
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
    Serial.print("Sono nell'IF...\n");
    Serial.print("Valore attuale: ");
    Serial.print(sensorValue); //stampo il valore letto a terminale
    Serial.print(", Valore critico:");
    Serial.print(valore_critico); //stampo il valore critico a terminale
    Serial.print("\n Accendo il led...\n");
    digitalWrite(12,HIGH); //Accendi led
    Serial.print("Led acceso\n");
  }
  else{
    Serial.print("Sono nell'ELSE\n");
    Serial.print("Valore attuale: ");
    Serial.print(sensorValue); //stampo il valore letto a terminale
    Serial.print(", Valore critico:");
    Serial.print(valore_critico); //stampo il valore critico a terminale
    Serial.print("\n Spengo il led...\n");
    digitalWrite(12,LOW); //Spegni led
    Serial.print("Led spento.\n");
  }
  //Attendo un secondo
  delay(1000);
}
