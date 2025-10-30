#ifndef THERMISTOR_HPP
# define THERMISTOR_HPP

# include <Arduino.h>

/**
 * @brief The B-parameter value for the specific thermistor.
 * This is a typical value for a 10k NTC thermistor.
 */
# define B 3977

/**
 * @brief A class to read temperature from an NTC thermistor.
 * @details Uses the B-parameter equation to calculate temperature from
 * an analog voltage reading. Assumes a voltage divider circuit.
 *  * @warning The calculation in the .cpp file appears to be incorrect.
 * It uses the fixed resistor value instead of the thermistor's 
 * nominal resistance (R0) in the log calculation.
 */
class Thermistor
{

	private:

		unsigned int	inputPin;
		unsigned int	vcc;
		unsigned int	resistance; // This is the fixed resistor (R_fixed)

	public:

		Thermistor(unsigned int inputPin, unsigned int vcc, unsigned int resistance);
		Thermistor(const Thermistor& obj);
		~Thermistor();

		double	getTemperature() const;

		void	setinputPin(unsigned int inputPin);
		void	setVcc(unsigned int vcc);
		void	setResistance(unsigned int resistance);

};

#endif
