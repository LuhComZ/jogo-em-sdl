#include "dnd.h"

int Dnd::rollDice()
{
	return getRandomNumber(1, 20); // D20
}

int Dnd::rollDice(int size)
{
	return getRandomNumber(1, size);
}

int* Dnd::rollDice(int size, int times)
{
	int arr[times];

	for (int i = 0; i < times; i++)
	{
		arr[i] = getRandomNumber(1, size);
	};

	return arr;
}

int getRandomNumber(int min, int max)
{
	return (rand() % (max)) + min;
}