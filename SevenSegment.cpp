#include "SevenSegment.hpp"

const int num_array[10][8] = 	{
								{ 1,1,1,1,1,1,0,0 },    // 0
								{ 0,1,1,0,0,0,0,0 },    // 1
								{ 1,1,0,1,1,0,1,0 },    // 2
								{ 1,1,1,1,0,0,1,0 },    // 3
								{ 0,1,1,0,0,1,1,0 },    // 4
								{ 1,0,1,1,0,1,1,0 },    // 5
								{ 1,0,1,1,1,1,1,0 },    // 6
								{ 1,1,1,0,0,0,0,0 },    // 7
								{ 1,1,1,1,1,1,1,0 },    // 8
								{ 1,1,1,1,0,1,1,0 }};   // 9

/**
 * @brief Constructs a new SevenSegment object.
 * @param pin An array of 8 pin numbers corresponding to the segments
 * (a, b, c, d, e, f, g, dp).
 */
SevenSegment::SevenSegment(int pin[8])
{
	for (int i = 0; i < 8; i++)
	{
		this->pin[i] = pin[i];
		pinMode(pin[i], OUTPUT);
	}
}

/**
 * @brief Destroys the SevenSegment object.
 */
SevenSegment::~SevenSegment(){}

/**
 * @brief Sets new pins for the 7-segment display.
 * @param pin An array of 8 pin numbers.
 */
void	SevenSegment::setPin(int pin[8])
{
	for (int i = 0; i < 8; i++)
	{
		this->pin[i] = pin[i];
		pinMode(pin[i], OUTPUT);
	}
}

/**
 * @brief Displays a single digit (0-9) on the display.
 * @param n The number to display. Must be between 0 and 9.
 */
void	SevenSegment::displayNumber(unsigned int n) const
{
	if (n > 9)
		return ;
	for (int i = 0; i < 8; i++)
	{
		digitalWrite(pin[i], num_array[n][i]);
	}
}
