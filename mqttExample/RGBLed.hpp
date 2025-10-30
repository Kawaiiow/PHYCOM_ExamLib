#ifndef RGBLED_HPP
# define RGBLED_HPP

# include <Arduino.h>

/**
 * @brief A class to control a 3-pin (common cathode/anode) RGB LED.
 * @details Manages the color values for Red, Green, and Blue.
 */
class RGBLed
{
	private:

		int		RPin;
		int		GPin;
		int		BPin;
		int		RValue;
		int		GValue;
		int		BValue;

	public:

		RGBLed(int RPin, int GPin, int BPin);
		RGBLed(const RGBLed& obj);
		~RGBLed();

		int		getR() const;
		int		getG() const;
		int		getB() const;

		void	setPin(int RPin, int GPin, int BPin);
		void	setValue(int RValue, int GValue, int BValue);

};

#endif
