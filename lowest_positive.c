/* See LICENSE file for copyright and license details.
 *
 * Given an array of integers, find the first missing positive integer in
 * linear time and constant space. In other words, find the lowest
 * positive integer that does not exist in the array. The array can contain
 * duplicates and negative numbers as well.
 *
 * For example, the input [3, 4, -1, 1] should give 2. The
 * input [1, 2, 0] should give 3.
 *
 * You can modify the input array in-place.
 */
#include <stdio.h>

static void swap(register int *a, register int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

int foo(int arr[], unsigned size)
{
	unsigned i;
	int min = 0;

	for (i = 0; i < size; ++i) {
		if (arr[i] > 0) {
			min = arr[i];
			break;
		}
	}

	for (++i; i < size; ++i) {
		if (arr[i] > 0 && arr[i] < min)
			min = arr[i];
	}

	if (min != 1)
		return 1;

	for (i = 0; i < size; ++i) {
		while (0 < arr[i] && arr[i] <= size && 
				arr[arr[i] - 1] != arr[i])
			swap(arr + (arr[i] - 1), arr + i);
	}

	for (i = 0; i < size && arr[i] - 1 == i; ++i)
		;

	return arr[i - 1] + 1;
}

int main(void)
{
	int a[] = {3, 4, -1, 1};
	int b[] = {1, 2, 0};

	printf("[3, 4, -1, 1]\t-> %d\n", foo(a, 4));
	printf("[1, 2, 0]\t-> %d\n", foo(b, 3));

	return 0;
}
