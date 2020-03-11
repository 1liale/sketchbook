const int led1 = 8;
const int led2 = 9;
const int sensor = A0;
int range = 0;

void blinkLED(int time, int pin)
{
	digitalWrite(pin, HIGH);
	delay(time);
	digitalWrite(pin, LOW);
	delay(time);
}

int sensorRange()
{
	int sensorValue = analogRead(sensor);
	sensorValue = map(sensorValue, 0, 1023, 0, 3);
	return sensorValue;
}

void setup()
{
	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);
	Serial.begin(9600);
}

void loop()
{
	range = sensorRange();
	Serial.println(range);

	switch(range)
	{
		case 0:
			blinkLED(1, led1);
			break;
		case 1:
			blinkLED(200, led2);
			break;
		case 2: 
			blinkLED(300, led1);
			break;
		case 3:
			blinkLED(400, led2);
			break;
	}
	delay(1);
}

