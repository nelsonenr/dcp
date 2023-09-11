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
#include <limits.h>

int foo(int arr[], unsigned size)
{
	int i;

	for (i = 0; i < size; ++i) {
		if (arr[i] <= 0)
			arr[i] = INT_MAX;
	}

	for (i = size - 2; i >= 0; --i) {
		if (arr[i] > arr[i + 1])
			arr[i] = arr[i + 1];
	}

	if (arr[0] > 1)
		return 1;

	for (i = 1; i < size; ++i) {
		if (arr[i] - arr[i - 1] > 1)
			break;
	}

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
