/**
	Purpose: Analogue selection program for LEDs
	Made By: Alex Li
	Made On: March 5, 2020
	Modified On: March 10, 2020
*/

// Declares variables 
const int leds[] = {13,12,11,10,9,8,7,6};
const int potPin = A0;
int curLED = 0;
int endLED = 7;
int curMode = -1;

// sets mode 1 (lights move in to center then out) 
void mode1()
{
	// lights LED on and off moving inward from outside
	for(int i = 0; i< 4; i++)
	{
		digitalWrite(leds[endLED], HIGH);
		digitalWrite(leds[curLED], HIGH);
		delay(400);
		digitalWrite(leds[endLED], LOW);
		digitalWrite(leds[curLED], LOW);
		delay(1);
	 	++curLED;
		--endLED;
	}	
	
	// lights LED on and off moving outward from the center
	for(int i = 0; i < 4; i++)
	{
		digitalWrite(leds[endLED], HIGH);
		digitalWrite(leds[curLED], HIGH);
		delay(400);
		digitalWrite(leds[curLED], LOW);
		digitalWrite(leds[endLED], LOW);
		delay(1);
		--curLED;
		++endLED;
	}
}

// sets mode 2 (randomizes LED and delay time)
void mode2()
{
	// initialize variables for random delatTime and randomLED
	int delayTime = random(100, 500);
	int randomLED = random(0,7);

	// sets selected LED as HIGH for the duration of delayTime 
	digitalWrite(leds[randomLED],HIGH);
	delay(delayTime);
	digitalWrite(leds[randomLED], LOW);
	delay(delayTime);		
}

// sets mode 3 (maps the pin selection to the analog input)
void mode3(int selectedPin)
{
	// sets all LEDs to low
	for(int i: leds)
        {
        	digitalWrite(i, LOW);
        }	

	// turns the selected LED on
	digitalWrite(selectedPin, HIGH);
}

// sets mode 4 (turns on all even then odd LEDs)
void mode4()
{
	for(int i = 0; i < 8; i++)
	{
		// lights up all even number leds for 500ms
		if(i % 2 == 0)
		{
			digitalWrite(leds[i], HIGH);
			delay(500);
			digitalWrite(leds[i], LOW);
			delay(1);
		}
	}

	for(int i = 0; i < 8; i++)
        {
		// lights up all odd number LEDs for 500ms
                if(i % 2 != 0)
                {
                        digitalWrite(leds[i], HIGH);
                        delay(500);
			digitalWrite(leds[i], LOW);
			delay(1);
                }
        }       

}

// setup function initializes settings for program and serial monitor
void setup()
{
	Serial.begin(9600);
	Serial.println("Initializing Flowing Lights");

	// sets all LED pins to output
	for(int i : leds)
	{
		pinMode(i, OUTPUT);
	}

}

// loop function contains the main program to be repeatedly run
void loop()
{
	// stores input from potentiometer then maps it into four zones
	int analogInfo = analogRead(potPin);
	int modeSelection = map(analogInfo,0, 1023, 0, 3);
	
	// prints out current mode selection
	if(curMode != modeSelection)
	{	
		Serial.println(modeSelection);
		curMode = modeSelection;
		
	}

	// selects each mode based on analog input from the potentiometer
	switch(modeSelection)
	{
		case 0:
			mode1();
			break;
		case 1:
			mode2();
			break;
		case 2:
			mode3(map(analogInfo,2*256,3*256-1,0,7));
			break;
		case 3:
			mode4();
			break;
			
	}
	
}

