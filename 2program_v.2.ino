  #include <LiquidCrystal_I2C.h>
  LiquidCrystal_I2C lcd(0x27, 16,2);
  int sumaMuestra;
  float promedio ; 
  int cantMuestra = 1000; 
  int muestraActual;
  int bucle;
  const int buzzer = 12; 
  const int ledV = 4;
  const int ledA = 5;
  const int ledR = 3;
  String   

void setup(){
  Serial.begin(9600);  
  pinMode(ledV, OUTPUT);//declaro ledV como salida 
  pinMode(ledA, OUTPUT);//declaro ledA como salida 
  pinMode(ledR, OUTPUT);//declaro ledR como salida 

    lcd.begin(16, 2);
    lcd.init();
    lcd.backlight();                       
    lcd.setCursor(2,0);
    lcd.print("  CO2Sense   ");
    lcd.setCursor (0,0);
    delay(1000);
    lcd.clear();
    lcd.setCursor (1,0);
    lcd.print("Calentando");

  for(int i =0;i<=100;i++){
    lcd.setCursor(12,0);
    if (i<100) lcd.print(" ");  //?¿
    if (i<10) lcd.print(" ");   //?¿
    //delay(1000);
    lcd.print(i);
    lcd.print("%");
    delay(700);
  
  }
   lcd.clear();
 }



void loop(){

  bucle = 0;
  sumaMuestra = 0;
    while(bucle <=cantMuestra ){
      muestraActual = analogRead(A1);
      sumaMuestra = muestraActual + sumaMuestra ;  
      bucle++;  
   }
   promedio = sumaMuestra/cantMuestra;
 
   Serial.println(muestraActual );
   delay(200); 
    
//BUZZER 
   if(muestraActual >= 30 ){
    tone(buzzer, 440); 
    delay(1000);                 //delay??
  }else{
    noTone(buzzer);
  }
    
 
//LEDS
//LED VERDE AIRE PURO CAMBIAR A ELSE IF 
     if(muestraActual <= 20){  //LED AMARILLO AIRE MEDIO
      digitalWrite(ledV, HIGH);
      lcd.setCursor(1,1);
      lcd.print("VERDE <= 20 PPM ");
    }else if(muestraActual >=21 && muestraActual < 30){//hacer eso del buclfor en el lcd
      digitalWrite(ledA, HIGH);
      lcd.setCursor(1,1);
      lcd.print("AMARILLO >= 21 PPM/< 30 PPM ");
    }else if(muestraActual >= 30){
      digitalWrite(ledR, HIGH);
      lcd.setCursor(1,1);
      lcd.print("ROJO >= 30 PPM ");
    }else{// hacer los else del lcd
      digitalWrite(ledR, LOW);
      digitalWrite(ledA, LOW);
      digitalWrite(ledV, LOW);  
     

   
//LED ROJO AIRE ALERTA
   
      
    }
    


  lcd.setCursor(0, 0);
  lcd.print("CO2: ");
  lcd.setCursor(0,6);
  lcd.print(muestraActual);

  

   
     

}
