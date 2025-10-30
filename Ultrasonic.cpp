#include "Ultrasonic.hpp"

/**
 * ## Ultrasonic Class Constructor
 * Default for setup ultrasonic.
 * @param trigPin Set trigger pin.
 * @param echoPin Set echo pin
 */
Ultrasonic::Ultrasonic(const unsigned int trigPin, const unsigned int echoPin): trigPin(trigPin), echoPin(echoPin)
{
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	this->distance = 0;
}

/**
 * ## Ultrasonic Copy Constructor
 * 
 * Construct by pass other Ultrasonic object into parameter.
 * @param obj Ultrasonic object to copy.
 */
Ultrasonic::Ultrasonic(const Ultrasonic& obj): trigPin(obj.trigPin), echoPin(obj.echoPin)
{
	pinMode(obj.trigPin, OUTPUT);
	pinMode(obj.echoPin, INPUT);
	this->distance = 0;
}

Ultrasonic::~Ultrasonic()
{
}

/**
 * @brief get distance in cm
 * @return distance (cm)
 */
long	Ultrasonic::getDistance() const
{
	long start;
	int	pulseWidth;
	
	start = micros();
	digitalWrite(this->trigPin, HIGH);
	while (micros() - start < 10);
	digitalWrite(this->trigPin, LOW);
	pulseWidth = pulseIn(this->echoPin, HIGH);
	return (pulseWidth / 29 / 2);
}

void	Ultrasonic::setEcho(unsigned int echoPin)
{
	this->echoPin = echoPin;
	pinMode(echoPin, INPUT);
}

void	Ultrasonic::setTrig(unsigned int trigPin)
{
	this->trigPin = trigPin;
	pinMode(trigPin, OUTPUT);
}
