#ifndef POTENTIOMETER_HPP
# define POTENTIOMETER_HPP

# include <Arduino.h>

# define BIT_AVAL 1024.0

/**
 * 
 * @brief A class to interface with a potentiometer.
 * @details Reads an analog value from a pin and can scale it.
 * @param pin The analog pin the potentiometer is connected to.
 * @param cap The upperbound of the mapped value (e.g., 255).
 * @image html rrrhttps://www.jotrin.de/Userfiles/editor/20240321/114802Dual-gang-potentiometer-pinout.jpg
 */
class Potentiometer
{

	private:

		int	pin;
		int	cap;

	public:

		Potentiometer(int pin, int cap);
		~Potentiometer();

		int		getRawValue() const;
		float	getValue() const;

		void	setPin(int pin);

};

#endif
