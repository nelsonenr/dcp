/* See LICENSE file for copyright and license details.
 *
 * Given a string of round, curly, and square open and closing brackets,
 * return whether the brackets are balanced (well-formed).
 *
 * For example, given the string "([])[]({})", you should return true.
 *
 * Given the string "([)]" or "((()", you return false.
 */
#include <stdio.h>

#define IS_OPEN(c) ((c) == '(' || (c) == '{' || (c) == '[')

static int match(register char o, register char c)
{
	return (o == '(' && c == ')')
		|| (o == '{' && c == '}')
		|| (o == '[' && c == ']');
}

int foo(const char *s)
{
	const char *l, *r;

	for (; IS_OPEN(*s); s = r) {
		l = s;
		r = s + 1;
		while (IS_OPEN(*r)) {
			++l;
			++r;
		}
		do {
			if (!match(*l--, *r++))
				return 0;
		} while (l >= s);
	}

	return !*s;
}

int main(void)
{
	int i;
	const char *arr[] = {
		"([])[]({})", "([)]", "((()"
	};

	for (i = 0; i < 3; ++i)
		printf("%s: %d\n", arr[i], foo(arr[i]));

	return 0;
}
