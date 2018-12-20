#include "Keypad.h"

int speakerPin = 12; // speaker connected to digital pin 12

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char keys[ROWS][COLS] = {
{'a','b','c','d'},
{'e','f','g','h'},
{'i','j','k','l'},
{'m','n','o','p'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){

Serial.begin (9600);

pinMode(speakerPin, OUTPUT); // sets the speakerPin to be an output

}

void loop(){
char key = keypad.getKey();

if (key != NO_KEY){
Serial.println(key);

if (key== 'a'){ beep(speakerPin,2093,100);}
if (key== 'b'){ beep(speakerPin,2349,100);}
if (key== 'c'){ beep(speakerPin,2637,100);}
if (key=='d'){ beep(speakerPin,2793,100);}
if (key=='e'){ beep(speakerPin,3136,100);}
if (key=='f'){ beep(speakerPin,3520,100);}
if (key=='g'){ beep(speakerPin,3951,100);}
if (key=='h'){ beep(speakerPin,4186,100);}
///////////////////////////////////////////////
if (key=='i'){ beep(speakerPin,2093,100);}
if (key=='j'){ beep(speakerPin,2349,100);}
if (key=='k'){ beep(speakerPin,2637,100);}
if (key=='l'){ beep(speakerPin,2793,100);}
if (key=='m'){ beep(speakerPin,3136,100);}
if (key=='n'){ beep(speakerPin,3520,100);}
if (key=='o'){ beep(speakerPin,3951,100);}
if (key=='p'){ beep(speakerPin,4186,100);}
}
}

void beep (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds){ // the sound producing function
int x;
long delayAmount = (long)(1000000/frequencyInHertz);
long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
for (x=0;x<loopTime;x++)
{
digitalWrite(speakerPin,HIGH);
delayMicroseconds(delayAmount);
digitalWrite(speakerPin,LOW);
delayMicroseconds(delayAmount);
}
}
