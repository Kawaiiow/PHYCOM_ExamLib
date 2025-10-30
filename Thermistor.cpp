#include "Thermistor.hpp"

/**
 * ## Thermistor Class Constructor
 * Default for setup Thermistor.
 * @param inputPin Set pin to read voltage from sensor.
 * @param vcc Set voltage value.
 * @param resistance Set resistance value of resistor.
 */
Thermistor::Thermistor(unsigned int inputPin, unsigned int vcc, unsigned int resistance): inputPin(inputPin), vcc(vcc), resistance(resistance)
{
	pinMode(inputPin, INPUT);
}

/**
 * ## Thermistor Copy Constructor
 * 
 * Construct by pass other Thermistor object into parameter.
 * @param obj Thermistor object to copy.
 */
Thermistor::Thermistor(const Thermistor& obj): inputPin(obj.inputPin), vcc(obj.vcc), resistance(obj.vcc)
{
	pinMode(obj.inputPin, INPUT);
}

Thermistor::~Thermistor()
{
}

/**
 * get temperature in Celsius.
 * @return temperature in Celsius in double.
 */
double	Thermistor::getTemperatue() const
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

void	Thermistor::setinputPin(unsigned int inputPin)
{
	this->inputPin = inputPin;
	pinMode(inputPin, INPUT);
}

void	Thermistor::setVcc(unsigned int vcc)
{
	this->vcc = vcc;
}

void	Thermistor::setResistance(unsigned int resistance)
{
	this->resistance = resistance;
}
