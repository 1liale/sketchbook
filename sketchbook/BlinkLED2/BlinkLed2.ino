void blinkLed(int delayTime)
{
        digitalWrite(13, HIGH);
        delay(delayTime);
        digitalWrite(13, LOW);
        delay(delayTime);
}

void setup()
{
	pinMode(13, OUTPUT);
}

void loop()
{
	blinkLed(200);
}

