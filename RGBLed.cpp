#include "RGBLed.hpp"

/**
 * @brief Constructs a new RGBLed object.
 * @param RPin The digital pin (PWM-capable) for the Red component.
 * @param GPin The digital pin (PWM-capable) for the Green component.
 * @param BPin The digital pin (PWM-capable) for the Blue component.
 */
RGBLed::RGBLed(int RPin, int GPin, int BPin)
{
	this->RPin = RPin;
	this->GPin = GPin;
	this->BPin = BPin;
	pinMode(RPin, OUTPUT);
	pinMode(GPin, OUTPUT);
	pinMode(BPin, OUTPUT);
	this->RValue = 0;
	this->GValue = 0;
	this->BValue = 0;
}

/**
 * @brief Copy constructor for the RGBLed class.
 * @param obj The RGBLed object to copy.
 */
RGBLed::RGBLed(const RGBLed& obj)
{
	this->RPin = obj.RPin;
	this->GPin = obj.GPin;
	this->BPin = obj.BPin;
	pinMode(RPin, OUTPUT);
	pinMode(GPin, OUTPUT);
	pinMode(BPin, OUTPUT);
	this->RValue = 0;
	this->GValue = 0;
	this->BValue = 0;
}

/**
 * @brief Destroys the RGBLed object.
 */
RGBLed::~RGBLed(){}

/**
 * @brief Gets the currently stored Red value.
 * @return The Red value (0-255).
 */
int	RGBLed::getR() const
{
	return (this->RValue);
}

/**
 * @brief Gets the currently stored Green value.
 * @return The Green value (0-255).
 */
int	RGBLed::getG() const
{
	return (this->GValue);
}

/**
 * @brief Gets the currently stored Blue value.
 * @return The Blue value (0-255).
 */
int	RGBLed::getB() const
{
	return (this->BValue);
}

/**
 * @brief Sets new pins for the RGB LED.
 * @param RPin The new Red pin.
 * @param GPin The new Green pin.
 * @param BPin The new Blue pin.
 */
void	RGBLed::setPin(int RPin, int GPin, int BPin)
{
	this->RPin = RPin;
	this->GPin = GPin;
	this->BPin = BPin;
	pinMode(RPin, OUTPUT);
	pinMode(GPin, OUTPUT);
	pinMode(BPin, OUTPUT);
}

/**
 * @brief Sets the internal color values.
 * @note This method only updates the internal state; 
 * it does not write the value to the pins via analogWrite.
 * @param RValue The Red value (0-255).
 * @param GValue The Green value (0-255).
 * @param BValue The Blue value (0-255).
 */
void	RGBLed::setValue(int RValue, int GValue, int BValue)
{
	this->RValue = RValue;
	this->GValue = GValue;
	this->BValue = BValue;
	analogWrite(RPin, RValue);
	analogWrite(GPin, GValue);
	analogWrite(BPin, BValue);
}
