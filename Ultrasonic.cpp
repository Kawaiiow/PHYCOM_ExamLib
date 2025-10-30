#include "Ultrasonic.hpp"

/**
 * @brief Constructs a new Ultrasonic object.
 * @param trigPin The digital pin connected to the sensor's TRIG pin.
 * @param echoPin The digital pin connected to the sensor's ECHO pin.
 */
Ultrasonic::Ultrasonic(const unsigned int trigPin, const unsigned int echoPin): trigPin(trigPin), echoPin(echoPin)
{
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	this->distance = 0;
}

/**
 * @brief Copy constructor for the Ultrasonic class.
 * @param obj The Ultrasonic object to copy.
 */
Ultrasonic::Ultrasonic(const Ultrasonic& obj): trigPin(obj.trigPin), echoPin(obj.echoPin)
{
	pinMode(obj.trigPin, OUTPUT);
	pinMode(obj.echoPin, INPUT);
	this->distance = 0;
}

/**
 * @brief Destroys the Ultrasonic object.
 */
Ultrasonic::~Ultrasonic()
{
}

/**
 * @brief Measures and returns the distance in centimeters.
 * @details Sends a 10-microsecond trigger pulse, then measures the
 * duration of the echo pulse (pulseIn) and converts it to cm.
 * @return The calculated distance in centimeters (long).
 */
long	Ultrasonic::getDistance() const
{
	long start;
	int	pulseWidth;
	
	start = micros();
	digitalWrite(this->trigPin, HIGH);
	while (micros() - start < 10);
	digitalWrite(this->trigPin, LOW);
	pulseWidth = pulseIn(this->echoPin, HIGH, 50000);
	return (pulseWidth / 29 / 2);
}

/**
 * @brief Sets a new echo pin.
 * @param echoPin The new digital pin for the ECHO signal.
 */
void	Ultrasonic::setEcho(unsigned int echoPin)
{
	this->echoPin = echoPin;
	pinMode(echoPin, INPUT);
}

/**
 * @brief Sets a new trigger pin.
 * @param trigPin The new digital pin for the TRIG signal.
 */
void	Ultrasonic::setTrig(unsigned int trigPin)
{
	this->trigPin = trigPin;
	pinMode(trigPin, OUTPUT);
}
