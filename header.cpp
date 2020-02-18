#include "Header.h"


bool moveRight(int index, int size)
{
	int checkNum = size - 1;
	for (int i = 0; i < size; i++)
	{
		if (index == checkNum)
		{
			return false;
		}
		checkNum = checkNum + size;
	}
	return true;
}

bool moveDown(int index, int size)
{
	int checkNum = (size * size) - size;
	for (int i = 0; i < size; i++)
	{
		if (index == checkNum)
		{
			return false;
		}
		checkNum = checkNum + 1;
	}
	return true;
}

bool moveUp(int index, int size)
{
	int checkNum = 0;
	for (int i = 0; i < size; i++)
	{
		if (index == checkNum)
		{
			return false;
		}
		checkNum = checkNum + 1;
	}
	return true;
}

bool moveLeft(int index, int size)
{
	int checkNum = 0;
	for (int i = 0; i < size; i++)
	{
		if (index == checkNum)
		{
			return false;
		}
		checkNum = checkNum + size;
	}
	return true;
}

int checkXY(int indexNew, int&x, int&y)
{

	if (indexNew == 0)
	{
		x = 0;
		y = 0;
	}
	else if (indexNew == 1)
	{
		x = 1;
		y = 0;
	}
	else if (indexNew == 2)
	{
		x = 2;
		y = 0;
		}
		else if (indexNew == 3)
		{
			x = 0;
			y = 1;
		}
		else if (indexNew == 4)
		{
			x = 1;
			y = 1;
		}
		else if (indexNew == 5)
		{
			x = 2;
			y = 1;
		}
		else if (indexNew == 6)
		{
			x = 0;
			y = 2;
		}
		else if (indexNew == 7)
		{
			x = 1;
			y = 2;
		}
		else if (indexNew == 8)
		{
			x = 2;
			y = 2;
		}
	return 0;
}