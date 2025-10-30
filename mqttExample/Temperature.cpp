#include "Temperature.hpp"

/**
 * @brief Constructs a new Temperature object.
 * @param inputPin The analog pin to read the sensor's voltage from.
 */
Temperature::Temperature(unsigned int inputPin): inputPin(inputPin)
{
	pinMode(inputPin, INPUT);
}

/**
 * @brief Copy constructor for the Temperature class.
 * @param obj The Temperature object to copy.
 */
Temperature::Temperature(const Temperature& obj): inputPin(obj.inputPin)
{
	pinMode(obj.inputPin, INPUT);
}

/**
 * @brief Destroys the Temperature object.
 */
Temperature::~Temperature()
{
}

/**
 * @brief Gets the temperature in Celsius.
 * @return Temperature in Celsius as a double.
 */
double	Temperature::getTemperature() const
{
	return (((analogRead(inputPin) * 5.0 / 1023) - 0.5 ) / 0.01 );
}

/**
 * @brief Sets a new analog input pin for the sensor.
 * @param inputPin The new analog pin number.
 */
void	Temperature::setInputPin(unsigned int inputPin)
{
	this->inputPin = inputPin;
	pinMode(inputPin, INPUT);
}
