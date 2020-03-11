const int sensor = A0;
int range = 0;

int sensorRange()
{
	int sensorValue = analogRead(sensor);
	sensorValue = map(sensorValue, 0, 1023, 0, 3);
	return sensorValue;
}

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	range = sensorRange();
	Serial.println(range);

	switch(range)
	{
		case 0:
			Serial.println("In range zero");
			break;
		case 1:
			Serial.println("In range one");
			break;
		case 2: 
			Serial.println("In range two");
			break;
		case 3:
			Serial.println("In range three");
			break;
	}
	delay(500);
}

