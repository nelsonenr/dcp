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

static void print_arr(register int *ptr, register unsigned size)
{
	/* assert(size != 0); */
	while (--size > 0)
		printf("%d ", *ptr++);
	printf("%d\n", *ptr);
}

/*
 * The array of integers `arr' is defined as
 * 	arr = [a_1, a_2, ..., a_(n-1), a_n]
 * for n >= 2. Let s and be array such that
 *
 * s = [1, a_1, a_1a_2, ..., a_1a_2...a_(n-1)]
 * t = [a_2a_3...a_n, ..., a_(n-1)a_n, a_n, 1]
 * 
 * new_arr[i] = s[i] * t[i]
 */

int *foo(const int arr[], unsigned size)
{
	int i, acc;
	int *new_arr = calloc(size, sizeof(int));

	for (i = 0; i < size; ++i)
		new_arr[i] = 1;

	acc = 1;
	for (i = 1; i < size; ++i) {
		acc *= arr[i - 1];
		new_arr[i] *= acc;
	}

	acc = 1;
	for (i = size - 2; i >= 0; --i) {
		acc *= arr[i + 1];
		new_arr[i] *= acc;
	}

	return new_arr;
}

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	unsigned size = sizeof(arr) / sizeof(int);
	int *new_arr = foo(arr, size);

	print_arr(new_arr, size);
	exit(0);
}
