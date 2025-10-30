#ifndef THERMISTOR_HPP
# define THERMISTOR_HPP

# include <Arduino.h>

# define B 3977

class Thermistor
{

	private:

		unsigned int	inputPin;
		unsigned int	vcc;
		unsigned int	resistance;

	public:

		Thermistor(unsigned int inputPin, unsigned int vcc, unsigned int resistance);
		Thermistor(const Thermistor& obj);
		~Thermistor();

		double	getTemperatue() const;

		void	setinputPin(unsigned int inputPin);
		void	setVcc(unsigned int vcc);
		void	setResistance(unsigned int resistance);

};

#endif
