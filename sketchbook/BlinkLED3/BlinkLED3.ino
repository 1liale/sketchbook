const int LED1 = 13;
const int LED2 = 9;

void blinkLed(int delayTime, int led)
{
        digitalWrite(led, HIGH);
        delay(delayTime);
        digitalWrite(led,LOW);
        delay(delayTime);
}

void setup()
{
	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
}

void loop()
{
	blinkLed(100, LED1);
	blinkLed(100, LED1);
	blinkLed(100, LED1);
	blinkLed(300, LED2);
	blinkLed(300, LED2);
}

