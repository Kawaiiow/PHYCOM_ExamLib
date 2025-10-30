#include "Thermistor.hpp"

/**
 * @brief Constructs a new Thermistor object.
 * @param inputPin The analog pin reading the voltage divider.
 * @param vcc The supply voltage (e.g., 5).
 * @param resistance The resistance of the *fixed* resistor in 
 * the voltage divider.
 */
Thermistor::Thermistor(unsigned int inputPin, unsigned int vcc, unsigned int resistance): inputPin(inputPin), vcc(vcc), resistance(resistance)
{
	pinMode(inputPin, INPUT);
}

/**
 * @brief Copy constructor for the Thermistor class.
 * @warning The .cpp implementation has a bug:
 * it copies obj.vcc into this->resistance.
 * @param obj The Thermistor object to copy.
 */
Thermistor::Thermistor(const Thermistor& obj): inputPin(obj.inputPin), vcc(obj.vcc), resistance(obj.resistance)
{
	pinMode(obj.inputPin, INPUT);
}

/**
 * @brief Destroys the Thermistor object.
 */
Thermistor::~Thermistor()
{
}

/**
 * @brief Gets the temperature in Celsius.
 * @note The name is misspelled as 'getTemperatue'.
 * @return Temperature in Celsius as a double.
 */
double	Thermistor::getTemperature() const
{
	double	sig;
	double	re;
	double	rt;
	double	ln;
	double	vr;
	double	temp;

	sig = analogRead(this->inputPin);
	re = (sig * (5.0 / 1023));
	vr = this->vcc - re;
	rt = re / (vr / this->resistance);
	ln = log(rt / this->resistance);
	temp = (1 / ((ln / B) + (1 / (25 + 273.15))));
	temp -= 273.15;
	return (temp);
}

/**
 * @brief Sets a new analog input pin.
 * @note Typo in .cpp: should be setInputPin for camelCase.
 * @param inputPin The new analog pin.
 */
void	Thermistor::setinputPin(unsigned int inputPin)
{
	this->inputPin = inputPin;
	pinMode(inputPin, INPUT);
}

/**
 * @brief Sets the supply voltage.
 * @param vcc The new supply voltage.
 */
void	Thermistor::setVcc(unsigned int vcc)
{
	this->vcc = vcc;
}

/**
 * @brief Sets the fixed resistor value.
 * @param resistance The new fixed resistor value.
 */
void	Thermistor::setResistance(unsigned int resistance)
{
	this->resistance = resistance;
}
