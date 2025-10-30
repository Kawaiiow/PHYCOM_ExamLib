#ifndef LED_HPP
# define LED_HPP

# include <Arduino.h>

/**
 * @brief A class to control a simple Light Emitting Diode (LED).
 * @details Manages the state (on/off) of an LED connected to a digital pin.
 */
class Led
{

	private:

		int		pin;
		int		state;

	public:

		Led(int pin);
		Led(const Led& obj);
		~Led();

		int		getPin() const;
		bool	getState() const;

		void	setPin(int pin);
		void	setState(int state);

		void	on();
		void	off();
		void	turn();

};

#endif
