/*robô de mesa miuly - oelL-55.linguagem utilizada c++
  
  versão: 2.3@

  criado por: Leonardo de Oliveira Prado
  Instagram: arduino2.0tecnologico

  Data de inicio do projeto 25/07/2023
  Data de término do projeto 12/09/2023

*/
//********************************INCLUSÃO DE BIBLIOTECAS
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//#include <DHT.h> //biblioteca sensor
//#include <DHT_U.h> //biblioteca sensor

//********************************INCLUSÃO DAS DEFINIÇÕES
#define pinBotao 3 // BOTÃO
#define luminosidade A0 // SENSOR DE LUZ
#define Buzzer 2 //buzzer

//********************************DEFINIÇÕES LCD
#define endereco  0x27 // Endereços comuns: 0x27, 0x3F
#define colunas   16
#define linhas    2
//********************************DEFINIÇÕES DO SENSOR DHT 22
//int SENSOR = 4; // pim 4 sensor
//int TEMPERATURA;
//int HUMIDADE;

//********************************INSTANCIANDO OBJETOS
//DHT dht (SENSOR, DHT22); // sensor dht22

//********************************INSTANCIANDO OBJETOS
LiquidCrystal_I2C lcd(endereco, colunas, linhas);

//***********************************************pixel art********************************************************************************


byte raiva[8]={ //RAIVA
B00000,
B00000,
B00000,
B01110,
B10001,
B10001,
B10001,
B10001,
};


byte ravaolho1[8]={ //RAIVA OLHO 1
B00000,
B00110,
B01100,
B11000,
B10110,
B00110,
B00000,
B00000,
};

byte raivaolho2[8]={ //RAIVA OLHO 2
B00000,
B01100,
B00110,
B00011,
B01101,
B01100,
B00000,
B00000,
};

byte bobo[8] ={ //BOBO
B01010,
B01010,
B11011,
B00000,
B00000,
B11011,
B01010,
B01010,
};



byte corasao[8] ={ //CORASÃO
B00000,
B00000,
B01010,
B11111,
B11111,
B01110,
B00100,
B00000,
};


byte energiafraca[8] ={ //ENERGIAFRACA
B00000,
B01110,
B11111,
B10001,
B10001,
B10001,
B11111,
B11111,
};



byte tedio[8] ={ // TEDIO
B01010,
B01010,
B01010,
B00010,
B00010,
B00010,
B00000,
B00000,
};

//********************************************************************************************************************************

//void botaoAcionado(); //INTERRUPÇÃOES //APERTAR O BOTÃO

void setup(){
//********************************LCD DISPLAY 
  lcd.init(); // INICIA A COMUNICAÇÃO COM O DISPLAY
  lcd.backlight(); // LIGA A ILUMINAÇÃO DO DISPLAY
  lcd.clear(); // LIMPA O DISPLAY
//********************************PINMODE DOS COMPONENTES
  pinMode(Buzzer, OUTPUT);
  pinMode(luminosidade, INPUT);
//pinMode(pinBotao, INPUT_PULLUP);

  //attachInterrupt(digitalPinToInterrupt(pinBotao), botaoAcionado, RISING);//INTERRUPÇÃOES //APERTAR O BOTÃO

  //dht.begin();                                  
  //Serial.println("Usando o Sensor DHT"); 
  //sensor_t sensor;

//********************************pixel art LCD PASSA O "NEME" PARA UM NUMERO
  lcd.createChar(1, bobo);
  lcd.createChar(2, corasao);
  lcd.createChar(3, energiafraca);
  lcd.createChar(4, tedio);
  lcd.createChar(5, raiva);
  lcd.createChar(6,  ravaolho1);
  lcd.createChar(7, raivaolho2);

//*******************************************LIGANDO O ROBÔ*********************************************************************************************88
  lcd.setCursor(5, 0);
  lcd.print("^ o ^"); 
  lcd.setCursor(0, 1);
  lcd.print("Bom dia !!");
  tone(Buzzer, 165, 1000); 
  delay(500); 
  noTone(Buzzer);
  delay(500); 
  tone(Buzzer, 165, 1000); 
  delay(500); 
  noTone(Buzzer);
  delay(1000);
  lcd.clear();
   lcd.setCursor(5, 0);
 lcd.print("^ 3 ^");
  lcd.setCursor(0, 1);
  lcd.print("oii, tudo bem?");
  tone(Buzzer, 92, 1000); 
  delay(100); 
  noTone(Buzzer);
  delay(100); 
  tone(Buzzer, 165, 1000); 
  delay(200); 
  noTone(Buzzer);
  delay(200); 
  tone(Buzzer, 165, 1000); 
  delay(200); 
  noTone(Buzzer);
  delay(200); 
  delay(2000); 
 lcd.clear();
}


void loop(){
  
//****************************************FONCIONAMENTO DO ROBÔ****************************************************************************************************
  if (analogRead(luminosidade) > 10) { //SE A LUMINOSIDADE FOR MAIR QUE 15 ROBO ACORDADO (LIGADO)
    if (random(1, 20 + 1) == 1) { // SORTEIA AS ANIMAÇÕES (BOBO)
      lcd.clear();
      lcd.setCursor(6, 0);
      lcd.print("> <");
      lcd.setCursor(0, 1);
      lcd.print("bobo!!");

      lcd.setCursor(4, 0);
      lcd.write(1);

      tone(Buzzer, 165, 1000); 
      delay(200); 
      noTone(Buzzer);
      delay(200); 
      tone(Buzzer, 165, 1000); 
      delay(200); 
      noTone(Buzzer);
      delay(3000); 
     
    }
    if (random(1, 20 + 1) == 2) {// SORTEIA AS ANIMAÇÕES (FELIZ)
      lcd.clear();
       lcd.setCursor(5, 0);
       lcd.print("^ w ^");
      lcd.setCursor(0, 1);
      lcd.print("feliz!!");
      delay(3000); 
      
    }
    if (random(1, 20 + 1) == 3) {// SORTEIA AS ANIMAÇÕES (MONEY)
      lcd.clear();
      lcd.setCursor(6, 0);
      lcd.print("$_$");
      lcd.setCursor(0, 1);
      lcd.print("money $$");
      delay(4000); 
     
    }
    if (random(1, 20 + 1) == 4) {// SORTEIA AS ANIMAÇÕES (VERGONHA)
      lcd.clear();
     lcd.setCursor(6, 0);
      lcd.print(">_<");
      lcd.setCursor(0, 1);
      lcd.print("vergonha");
      tone(Buzzer, 92, 3000); 
      delay(500); 
      noTone(Buzzer);
      delay(7000); 
     
    }
    if (random(1, 20 + 1) == 5) {// SORTEIA AS ANIMAÇÕES (TEDIO)
      lcd.clear();
      lcd.setCursor(6, 0);
      lcd.print("T_T");
      lcd.setCursor(0, 1);
      lcd.print("tedio!");

      lcd.setCursor(5, 0);
      lcd.write(4);
      lcd.setCursor(9, 0);
      lcd.write(4);

      tone(Buzzer, 92, 1000);
      delay(800); 
      noTone(Buzzer);
      delay(5000); 
      
    }
    if (random(1, 20 + 1) == 6) {// SORTEIA AS ANIMAÇÕES (ESPIRRO)
      lcd.clear();
      lcd.setCursor(6, 0);
      lcd.print(">.<");
      lcd.setCursor(0, 1);
      lcd.print("espirro!!!");
      tone(Buzzer, 22, 1000); 
      delay(800); 
      noTone(Buzzer);
      delay(5000); 
      
    }
    if (random(1, 20 + 1) == 7) {// SORTEIA AS ANIMAÇÕES (SONO)
      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print("^ o ^");
      lcd.setCursor(0, 1);
      lcd.print("sono");
      delay(4000); 
      
    }
    if (random(1, 20 + 1) == 8) {// SORTEIA AS ANIMAÇÕES (ENERGIA FRACA)
      lcd.clear();
      lcd.setCursor(6, 0);
      lcd.print("X_X");
      lcd.setCursor(0, 1);
      lcd.print("!energia fraca!");

      lcd.setCursor(2, 0);
      lcd.write(3);

      tone(Buzzer, 165, 1000); 
      delay(200); 
      noTone(Buzzer);
      delay(200); 
      tone(Buzzer, 165, 1000); 
      delay(200); 
      noTone(Buzzer);
      delay(4000); 
     
    }
    if (random(1, 20 + 1) == 9) {// SORTEIA AS ANIMAÇÕES (DESCONFIADO)
      lcd.clear();
      lcd.setCursor(6, 0);
      lcd.print("^_-");
      lcd.setCursor(0, 1);
      lcd.print("desconfiado ??");
      delay(4000); 
      
    }
    if (random(1, 20 + 1) == 10) {// SORTEIA AS ANIMAÇÕES (TENSO)
      lcd.clear();
      lcd.setCursor(6, 0);
      lcd.print("O_O");
      lcd.setCursor(0, 1);
      lcd.print("tenso!");
      delay(4000); 
      
    }
    if (random(1, 20 + 1) == 11) {// SORTEIA AS ANIMAÇÕES (GOSTEI)
      lcd.clear();
      lcd.setCursor(6, 0);
      lcd.print("<3");
      lcd.setCursor(0, 1);
      lcd.print("gostei!!");

      lcd.setCursor(8, 1);
      lcd.write(2);
      lcd.setCursor(9, 1);
      lcd.write(2);
      lcd.setCursor(10, 1);
      lcd.write(2);

      tone(Buzzer, 165, 1000); 
      delay(400); 
      noTone(Buzzer);
      delay(4000); 
     
    }
    if (random(1, 20 + 1) == 12) {// SORTEIA AS ANIMAÇÕES (ESUTOU FELIZ)
      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print("^ w ^");
      lcd.setCursor(0, 1);
      lcd.print("estou feliz!!");
      tone(Buzzer, 294, 1000); 
      delay(400); 
      noTone(Buzzer);
      delay(4000); 
      
    }
    if (random(1, 20 + 1) == 13) {// SORTEIA AS ANIMAÇÕES (FOFO)
      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print("> w <");
      lcd.setCursor(0, 1);
      lcd.print("fofo!!");

      lcd.setCursor(6, 1);
      lcd.write(2);

     tone(Buzzer, 165, 1000); 
      delay(100); 
      noTone(Buzzer);
      delay(100); 
      tone(Buzzer, 165, 1000); 
      delay(100); 
      noTone(Buzzer);
      delay(3000); 
     
    }
    if (random(1, 20 + 1) == 14) {// SORTEIA AS ANIMAÇÕES (RAIVA)
     lcd.clear();
      lcd.setCursor(5, 0);
      lcd.write(7);
       lcd.setCursor(7, 0);
        lcd.write(5);
        lcd.setCursor(9, 0);
        lcd.write(6);
      lcd.setCursor(0, 1);
      lcd.print("raiva!!");
      tone(Buzzer, 22, 4000); 
      delay(4000); 
      noTone(Buzzer);
      delay(2000); 
     
     
    }
    if (random(1, 20 + 1) == 15) {// SORTEIA AS ANIMAÇÕES (FELIZ)
      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print("^ w ^");
      lcd.setCursor(0, 1);
      lcd.print("feliz!!");
      delay(4000); 
      
    }
    if (random(1, 20 + 1) == 16) {// SORTEIA AS ANIMAÇÕES (FELIZ)
      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print("^ w ^");
      lcd.setCursor(0, 1);
      lcd.print("feliz!!");
      delay(4000); 
      
    }
    if (random(1, 20 + 1) == 17) {// SORTEIA AS ANIMAÇÕES (FELIZ)
      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print("^ w ^");
      lcd.setCursor(0, 1);
      lcd.print("feliz!!");
      delay(4000); 
     
    }
    if (random(1, 20 + 1) == 18) {// SORTEIA AS ANIMAÇÕES (FELIZ)
      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print("^ w ^");
      lcd.setCursor(0, 1);
      lcd.print("feliz!!");
      delay(4000); 
    }
    if (random(1, 20 + 1) == 19) {// SORTEIA AS ANIMAÇÕES (FELIZ)
      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print("^ w ^");
      lcd.setCursor(0, 1);
      lcd.print("feliz!!");
      delay(4000); 
      
    }
    if (random(1, 20 + 1) == 20) {// SORTEIA AS ANIMAÇÕES (FELIZ)
      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print("^ w ^");
      lcd.setCursor(0, 1);
      lcd.print("feliz!!");
      delay(4000); 
      
    }
     } else { //SE A LUMINOSIDADE FOR MENOR QUE 15 ROBÔ DORME
    lcd.clear();
    lcd.setCursor(6, 0);
    lcd.print("U_U");
    lcd.setCursor(0, 1);
    lcd.print("zzzzzzzzz");
    delay(2000); 
     }

}
  /*void botaoAcionado() {
static bool estado = LOW;
static unsigned long delayEstado;


   if ( (millis() - delayEstado) > 100 ) {
     estado = !estado;
     delayEstado = millis();
   }
     if (digitalRead(pinBotao) == estado ) { //BOTÃO
  TEMPERATURA = dht.readTemperature();
  HUMIDADE= dht.readHumidity();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("temperatura: ");
  lcd.setCursor(14,0);
  lcd.print("*C");
  lcd.setCursor(12, 0);
  lcd.print(TEMPERATURA);
   lcd.setCursor(0, 1);
  lcd.print("umidade: ");
  lcd.setCursor(14, 1);
  lcd.print("%");
   lcd.setCursor(12, 1);
  lcd.print(HUMIDADE);
  delay(5000);
  lcd.clear();
     }
}
*/