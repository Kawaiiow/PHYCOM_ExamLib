#include "Potentiometer.hpp"

/**
 * @brief Constructs a new Potentiometer object.
 * @param pin The analog pin the potentiometer is connected to.
 * @param cap The maximum value to map the potentiometer's reading to.
 */
Potentiometer::Potentiometer(int pin, int cap)
{
	this->pin = pin;
	this->cap = cap;
	pinMode(pin, INPUT);
}

/**
 * @brief Destroys the Potentiometer object.
 */
Potentiometer::~Potentiometer(){}

/**
 * @brief Sets a new analog pin for the potentiometer.
 * @param pin The new analog pin number (must be an analog-capable pin).
 */
void	Potentiometer::setPin(int pin)
{
	this->pin = pin;
	pinMode(pin, INPUT);
}

/**
 * @brief Gets the raw analog value from the potentiometer.
 * @return The raw value (typically 0-1023).
 */
int	Potentiometer::getRawValue() const
{
	return (analogRead(this->pin));
}

/**
 * @brief Gets the scaled value from the potentiometer.
 * @return The analog value mapped to the range 0 to 'cap'.
 */
float	Potentiometer::getValue() const
{
	return (analogRead(this->pin) * this->cap / BIT_AVAL);
}
