#include <stdio.h>
#include <stdlib.h>

int digit_count(int input)
{
	int count = 0;

	while (input > 0)
	{
		count++;
		input /= 10;
	}

	return count;
}

#define INPUT_NUMBER 9218
#define DIGIT_COUNT digit_count(INPUT_NUMBER)

int all_digits_same(int input)
{
	int last = input % 10;
	while (input > 0)
	{
		if (input % 10 != last)
		{
			return 0;
		}
		input /= 10;
	}
	return 1;
}

int reverse_digits(int input)
{
	int reversed = 0;

	while (input > 0)
	{
		reversed = reversed * 10 + (input % 10);
		input /= 10;
	}

	return reversed;
}

int sort_digits(int input)
{
	int *digits = (int *)malloc(sizeof(*digits) * DIGIT_COUNT);

	for (int i = 0; i < DIGIT_COUNT; i++)
	{
		digits[i] = input % 10;
		input /= 10;
	}

	for (int i = 0; i < DIGIT_COUNT - 1; i++)
	{
		for (int j = 0; j < DIGIT_COUNT - 1 - i; j++)
		{
			if (digits[j] > digits[j + 1])
			{
				int temp = digits[j];
				digits[j] = digits[j + 1];
				digits[j + 1] = temp;
			}
		}
	}

	int sorted_number = 0;

	int multiplier = 1;
	for (int i = DIGIT_COUNT - 1; i >= 0; i--)
	{
		sorted_number += (digits[i] * multiplier);
		multiplier *= 10;
	}

	free(digits);

	return sorted_number;
}

int main(void)
{
	printf("DIGIT_COUNT: %d, INPUT_NUMBER: %d\n", DIGIT_COUNT, INPUT_NUMBER);

	if (all_digits_same(INPUT_NUMBER))
	{
		fprintf(stderr, "Digits cannot all be the same.\n");

		return 1;
	}

	const int MAGIC_NUMBER = 6174;
	int number = INPUT_NUMBER;

	while (number != MAGIC_NUMBER)
	{
		int sorted = sort_digits(number);
		int reversed = reverse_digits(sorted);
		number = reversed - sorted;
		printf("number: %d\n", number);
	}

	return 0;
}