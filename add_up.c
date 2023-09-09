/* See LICENSE file for copyright and license details.
 *
 * Given a list of numbers and a number k, return  whether
 * any two numbers from the list add up to k.
 *
 * For example, given [10, 15, 3, 7] and k of 17, return
 * true since 10 + 7 is 17.
 *
 * Bonus: Can you do this in one pass?
 */
#include <stdio.h>
#include <stdlib.h>

#define N 4

typedef struct node node;
typedef node **hashtable;

struct node {
	int value;
	node *next;
};

static __inline__ unsigned hash(int x)
{
	return x % N;
}

static node *search(hashtable ht, int x)
{
	unsigned i = hash(x);
	node *n;

	for (n = ht[i]; n; n = n->next) {
		if (n->value == x)
			return n;
	}

	return NULL;
}

static void insert(hashtable ht, int x)
{
	unsigned i = hash(x);
	node *n;

	if (search(ht, x))
		return;

	n = malloc(sizeof(node));
	n->value = x;
	n->next = ht[i];
	ht[i] = n;
}

int foo(int l[N], int k)
{
	int i;
	hashtable ht = calloc(N, sizeof(node *));

	for (i = 0; i < N; ++i) {
		if (search(ht, k - l[i]))
			return i;
		insert(ht, l[i]);
	}

	return 0;
}

int main(void)
{
	int l[N] = {10, 5, 3, 7};

	printf("%d\n", !!(foo(l, 17)));

	exit(0);
}
