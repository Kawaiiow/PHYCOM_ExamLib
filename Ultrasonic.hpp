#ifndef ULTRASONIC_HPP
# define ULTRASONIC_HPP

#include <Arduino.h>

class Ultrasonic
{
	private:

		long	distance;
		unsigned int	trigPin;
		unsigned int	echoPin;

	public:

		Ultrasonic(const unsigned int trigPing, const unsigned int echoPin);
		Ultrasonic(const Ultrasonic& obj);
		~Ultrasonic();

		long	getDistance() const;

		void	setTrig(unsigned int trigPin);
		void	setEcho(unsigned int echoPin);

};

#endif
