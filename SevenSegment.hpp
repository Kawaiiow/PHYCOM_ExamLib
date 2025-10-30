#ifndef SEVENSEGENT_H
# define SEVENSEGMENT_H

# include <Arduino.h>

/**
 * @brief A class to control a 7-segment display.
 * @details Maps 8 pins to the 7 segments (a-g) and a decimal point (dp)
 * to display digits 0-9.
 */
class SevenSegment
{
	private:

		int	pin[8];

	public:

		SevenSegment(int pin[8]);
		~SevenSegment();

		void	setPin(int pin[8]);
		
		void	displayNumber(unsigned int n) const;

};

#endif
