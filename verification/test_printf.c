/* ft_printf vs printf 대조 테스트 (검증용, 원본 코드 아님) */
#include "../ft_printf/ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static int g_pass = 0, g_fail = 0;
static char outA[4096], outB[4096];

static int capture(char *buf, int (*fn)(void))
{
	int fds[2]; int saved; int ret; ssize_t n;
	fflush(stdout); pipe(fds); saved = dup(1); dup2(fds[1], 1); close(fds[1]);
	ret = fn(); fflush(stdout);
	dup2(saved, 1); close(saved);
	n = read(fds[0], buf, 4095); buf[n < 0 ? 0 : n] = 0; close(fds[0]);
	return ret;
}
#define T(name, ...) \
	static int ft_##name(void) { return ft_printf(__VA_ARGS__); } \
	static int lc_##name(void) { return printf(__VA_ARGS__); }
#define RUN(name) do { int a = capture(outA, ft_##name); int b = capture(outB, lc_##name); \
	if (a == b && strcmp(outA, outB) == 0) g_pass++; else { g_fail++; printf("FAIL %-14s ft=[%s](%d) libc=[%s](%d)\n", #name, outA, a, outB, b); } } while (0)

T(chars, "%c%c%c", 'a', '0', 'Z')
T(char0, "x%cy", 0)
T(str, "[%s]", "hello")
T(strnull, "[%s]", (char *)NULL)
T(strempty, "[%s]", "")
T(ptr, "%p", (void *)0x7ffe1234abcd)
T(ptrnull, "%p", (void *)0)
T(ptrmax, "%p", (void *)ULONG_MAX)
T(dint, "%d %i", 42, -42)
T(intmin, "%d", INT_MIN)
T(intmax, "%i", INT_MAX)
T(zero, "%d %u %x %X", 0, 0, 0, 0)
T(uns, "%u", 4294967295u)
T(hex, "%x %X", 0xdeadbeef, 0xdeadbeef)
T(pct, "100%%")
T(mixed, "%s=%d (%x) %c%%", "val", 255, 255, '!')
T(trailing, "end%")
T(plain, "no conversions\n")

int main(void)
{
	RUN(chars); RUN(char0); RUN(str); RUN(strnull); RUN(strempty); RUN(ptr); RUN(ptrnull); RUN(ptrmax);
	RUN(dint); RUN(intmin); RUN(intmax); RUN(zero); RUN(uns); RUN(hex); RUN(pct); RUN(mixed); RUN(trailing); RUN(plain);
	printf("ft_printf: %d passed, %d failed\n", g_pass, g_fail);
	return g_fail != 0;
}
