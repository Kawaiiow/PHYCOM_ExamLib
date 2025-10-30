#ifndef TEMPERATURE_HPP
# define TEMPERATURE_HPP

# include <Arduino.h>

/**
 * @brief A class to read temperature from an analog sensor (like TMP36).
 * @details Reads a voltage from an analog pin and converts it to Celsius.
 * The conversion formula assumes a 10mV/°C scale with a 500mV offset.
 */
class Temperature
{

	private:

		unsigned int	inputPin;

	public:

		Temperature(unsigned int inputPin);
		Temperature(const Temperature& obj);
		~Temperature();

		double	getTemperature() const;

		void	setInputPin(unsigned int inputPin);

};

#endif
