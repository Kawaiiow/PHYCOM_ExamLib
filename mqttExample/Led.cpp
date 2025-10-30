#include "Led.hpp"

/**
 * @brief Constructs a new Led object.
 * @param pin The Arduino digital pin number the LED is connected to.
 */
Led::Led(int pin)
{
	this->pin = pin;
	this->state = 0;
	pinMode(pin, OUTPUT);
}

/**
 * @brief Copy constructor for the Led class.
 * @param obj The Led object to copy.
 */
Led::Led(const Led& obj): pin(obj.pin), state(obj.state)
{
	pinMode(obj.pin, OUTPUT);
}

/**
 * @brief Destroys the Led object.
 */
Led::~Led(){}

/**
 * @brief Gets the pin number the LED is connected to.
 * @return The digital pin number.
 */
int	Led::getPin() const
{
	return (this->pin);
}

/**
 * @brief Gets the current state of the LED.
 * @return true (1) if the LED is on, false (0) if off.
 */
bool	Led::getState() const
{
	return (this->state);
}

/**
 * @brief Sets a new pin for the LED.
 * @param pin The new digital pin number.
 */
void	Led::setPin(int pin)
{
	this->pin = pin;
	pinMode(pin, OUTPUT);
}

/**
 * @brief Sets the state of the LED.
 * @param state The desired state (true/1 for on, false/0 for off).
 */
void	Led::setState(int state)
{
	this->state = state;
	digitalWrite(this->pin, state);
}

/**
 * @brief Turns the LED on (sets state to HIGH).
 */
void	Led::on()
{
	this->state = true;
	digitalWrite(this->pin, this->state);
}

/**
 * @brief Turns the LED off (sets state to LOW).
 */
void	Led::off()
{
	this->state = false;
	digitalWrite(this->pin, this->state);
}

/**
 * @brief Toggles the LED's state (on to off, or off to on).
 */
void	Led::turn()
{
	this->state = !this->state;
	digitalWrite(this->pin, this->state);
}
