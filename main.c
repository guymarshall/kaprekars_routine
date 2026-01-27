#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t digit_count(int32_t input)
{
	int32_t count = 0;

	while (input > 0)
	{
		count++;
		input /= 10;
	}

	return count;
}

#define INPUT_NUMBER 9218
#define DIGIT_COUNT digit_count(INPUT_NUMBER)

int32_t all_digits_same(int32_t input)
{
	int32_t last = input % 10;
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

int32_t reverse_digits(int32_t input)
{
	int32_t reversed = 0;

	while (input > 0)
	{
		reversed = reversed * 10 + (input % 10);
		input /= 10;
	}

	return reversed;
}

int32_t sort_digits(int32_t input)
{
	int32_t *digits = (int32_t *)malloc(sizeof(*digits) * DIGIT_COUNT);

	for (int32_t i = 0; i < DIGIT_COUNT; i++)
	{
		digits[i] = input % 10;
		input /= 10;
	}

	for (int32_t i = 0; i < DIGIT_COUNT - 1; i++)
	{
		for (int32_t j = 0; j < DIGIT_COUNT - 1 - i; j++)
		{
			if (digits[j] > digits[j + 1])
			{
				int32_t temp = digits[j];
				digits[j] = digits[j + 1];
				digits[j + 1] = temp;
			}
		}
	}

	int32_t sorted_number = 0;

	int32_t multiplier = 1;
	for (int32_t i = DIGIT_COUNT - 1; i >= 0; i--)
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

	const int32_t MAGIC_NUMBER = 6174;
	int32_t number = INPUT_NUMBER;

	while (number != MAGIC_NUMBER)
	{
		int32_t sorted = sort_digits(number);
		int32_t reversed = reverse_digits(sorted);
		number = reversed - sorted;
		printf("number: %d\n", number);
	}

	return 0;
}