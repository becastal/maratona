#include <Servo.h>
Servo servo;

void setup()
{
	servo.attach(9, 500, 2500);
  	pinMode(A0, INPUT);
  	pinMode(A1, INPUT);
  	pinMode(A2, OUTPUT);
  	pinMode(A3, INPUT);
  	pinMode( 7, OUTPUT);
	pinMode( 8, OUTPUT);
	Serial.begin(9600);
}

void loop()
{
	int temperatura = analogRead(A0);
  	temperatura = map(temperatura, 0, 1023, 0, 100);

	int luminosidade = analogRead(A1);
  	luminosidade = map(luminosidade, 0, 1023, 0, 100);

	digitalWrite(A2, HIGH);
	int umidade = analogRead(A3);
  	umidade = map(umidade, 0, 1023, 0, 100);
	digitalWrite(A2, LOW);

	Serial.print("temperatura: ");
	Serial.print(temperatura);
	Serial.print(" | luminosidade: ");
	Serial.print(luminosidade);
	Serial.print(" | umidade: ");
	Serial.println(umidade);


	if (temperatura > 28 and luminosidade > 70) {
		servo.write(90);
	} else {
		servo.write(0);
	}

	if (temperatura > 45) {
		tone(8, 330);
	} else {
		noTone(8);	
	}

	if (umidade < 70) {
		digitalWrite(7, HIGH);
	} else {
		digitalWrite(7, LOW);
	}
}
