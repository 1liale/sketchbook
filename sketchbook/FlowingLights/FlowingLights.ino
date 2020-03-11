const int leds[] = {13,12,11,10,9,8,7,6};
int delayTime;
int direction = 1;
int curLED = 0;

int ledNum = 8;
unsigned long changeTime;
const int potPin = A0;

void changeLED()
{
	for(int i : leds)
        {
                digitalWrite(i, LOW);
        }

	digitalWrite(leds[curLED], HIGH);
	curLED += direction; 
	
	if(curLED == ledNum-1)
	{
		direction = -1;
	}
	if(curLED == 0)
	{
		direction = 1;
	}
}

void setup()
{
	Serial.begin(9600);
	Serial.println("Initializing Flowing Lights");
	for(int i : leds)
	{
		pinMode(i, OUTPUT);
	}

	changeTime = millis();
}

void loop()
{
	delayTime = analogRead(potPin);
	if((millis() - changeTime) > delayTime){
		changeLED();
		changeTime = millis();	
	}
}

