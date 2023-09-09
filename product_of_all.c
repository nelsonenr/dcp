/* See LICENSE file for copyright and license details.
 *
 * Given an array of integers, return a new array such that each
 * element at index i of the new array is the product of all the
 * numbers in the original array except the one at i.
 *
 * For example, if our input was [1, 2, 3, 4, 5], the expected
 * output would be [120, 60, 40, 30, 24]. If our input was
 * [3, 2, 1], the expected output would be [2, 3, 6].
 *
 * Follow-up: what if you can't use division?
 */
#include <stdio.h>
#include <stdlib.h>

int *foo(const int arr[], unsigned size)
{
	int i, acc = 1;
	int *new_arr = calloc(size, sizeof(int));

	for (i = 0; i < size; ++i)
		new_arr[i] = 1;

	for (i = 1; i < size; ++i)
		new_arr[i] = new_arr[i - 1] * arr[i - 1];

	for (i = size - 2; i >= 0; --i) {
		acc = acc * arr[i + 1];
		new_arr[i] = new_arr[i] * acc;
	}

	return new_arr;
}

int main(void)
{
	int i, arr[] = {1, 2, 3, 4, 5};
	unsigned size = sizeof(arr) / sizeof(int);
	int *new_arr = foo(arr, size);

	for (i = 0; i < size - 1; ++i)
		printf("%d ", new_arr[i]);
	printf("%d\n", new_arr[size - 1]);

	exit(0);
}
