//Sens horaire
#define IR1 A2
#define IR2 A3
#define IR3 A4
#define IR4 A5
#define IR5 A6
#define IR6 A7
#define IR7 A0
#define IR8 A1
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

float tOut;
float tCm;
float tVolt;
int myOutput[8];
float myCm[8];
String IRtoSend;

void loop() {
  // put your main code here, to run repeatedly:
  tOut = analogRead(IR2);
  tVolt = tOut*5/1023;
  Serial.print(tOut);Serial.print("/");Serial.println(tVolt);
  //myOutput[0] = analogRead(IR1);myOutput[1] = analogRead(IR2);myOutput[2] = analogRead(IR3);myOutput[3] = analogRead(IR4);
  //myOutput[4] = analogRead(IR5);myOutput[5] = analogRead(IR6);myOutput[6] = analogRead(IR7);myOutput[7] = analogRead(IR8);
  /*
  IRtoSend="IR,";
  for(int i = 0 ; i < 8;i++)
  {
    myCm[i] = outputToCm(myOutput[i]);
    IRtoSend.concat(myCm[i]);
    IRtoSend = IRtoSend+",";  
  }
  IRtoSend.remove(IRtoSend.length()-1);
  Serial.println(IRtoSend);
  */
  delay(2000);
}

//courbes: https://www.generationrobots.com/fr/400808-capteur-de-distance-dms-80-robotis.html
float outputToCm(int myOutput)
{
  float myVolt = myOutput * 5 / 1023;
  float myCm = 29.988*pow(myVolt,-1.173);
  return myCm;
}
