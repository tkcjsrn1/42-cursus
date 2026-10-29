/* libft vs libc 대조 테스트 (검증용, 원본 코드 아님) */
#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdlib.h>
#include <bsd/string.h>

static int g_fail = 0;
static int g_pass = 0;
#define CHECK(name, cond) do { if (cond) g_pass++; else { g_fail++; printf("FAIL %s (line %d)\n", name, __LINE__); } } while (0)
static int sgn(int x) { return (x > 0) - (x < 0); }

int main(void)
{
	int c;
	c = -1;
	while (c <= 255)
	{
		CHECK("isalpha", !!ft_isalpha(c) == !!isalpha(c));
		CHECK("isdigit", !!ft_isdigit(c) == !!isdigit(c));
		CHECK("isalnum", !!ft_isalnum(c) == !!isalnum(c));
		CHECK("isascii", !!ft_isascii(c) == !!isascii(c));
		CHECK("isprint", !!ft_isprint(c) == !!isprint(c));
		CHECK("toupper", ft_toupper(c) == toupper(c));
		CHECK("tolower", ft_tolower(c) == tolower(c));
		c++;
	}
	const char *strs[] = {"", "a", "hello world", "abc\200def", "  -42", "+17x", "2147483647", "-2147483648", "\t\n\v\f\r 99", "--5", "0", NULL};
	int i = 0;
	while (strs[i])
	{
		const char *s = strs[i];
		CHECK("strlen", ft_strlen(s) == strlen(s));
		CHECK("atoi", ft_atoi(s) == atoi(s));
		CHECK("strchr", ft_strchr(s, 'o') == strchr(s, 'o'));
		CHECK("strchr0", ft_strchr(s, '\0') == strchr(s, '\0'));
		CHECK("strchr+256", ft_strchr(s, 'a' + 256) == strchr(s, 'a' + 256));
		CHECK("strrchr", ft_strrchr(s, 'l') == strrchr(s, 'l'));
		CHECK("strrchr0", ft_strrchr(s, '\0') == strrchr(s, '\0'));
		CHECK("strncmp", sgn(ft_strncmp(s, "hello", 5)) == sgn(strncmp(s, "hello", 5)));
		CHECK("strncmp200", sgn(ft_strncmp(s, "abc\001", 5)) == sgn(strncmp(s, "abc\001", 5)));
		CHECK("memchr", ft_memchr(s, 'l', strlen(s)) == memchr(s, 'l', strlen(s)));
		CHECK("memcmp", sgn(ft_memcmp(s, "abc\377", 4 < strlen(s)+1 ? 4 : strlen(s)+1)) == sgn(memcmp(s, "abc\377", 4 < strlen(s)+1 ? 4 : strlen(s)+1)));
		char *d1 = ft_strdup(s); CHECK("strdup", d1 && strcmp(d1, s) == 0); free(d1);
		size_t k = 0;
		while (k < 8)
		{
			char a[16]; char b[16];
			memset(a, 'Z', 16); memset(b, 'Z', 16);
			CHECK("strlcpy ret", ft_strlcpy(a, s, k) == strlcpy(b, s, k));
			CHECK("strlcpy buf", memcmp(a, b, 16) == 0);
			strcpy(a, "xy"); strcpy(b, "xy");
			CHECK("strlcat ret", ft_strlcat(a, s, k + 1) == strlcat(b, s, k + 1));
			CHECK("strlcat buf", memcmp(a, b, 16) == 0);
			CHECK("strnstr", ft_strnstr(s, "lo", k) == strnstr(s, "lo", k));
			k++;
		}
		CHECK("strnstr empty", ft_strnstr(s, "", 3) == strnstr(s, "", 3));
		i++;
	}
	char m1[32]; char m2[32];
	strcpy(m1, "0123456789abcdef"); strcpy(m2, "0123456789abcdef");
	ft_memmove(m1 + 2, m1, 10); memmove(m2 + 2, m2, 10); CHECK("memmove fwd", memcmp(m1, m2, 32) == 0);
	ft_memmove(m1, m1 + 3, 10); memmove(m2, m2 + 3, 10); CHECK("memmove back", memcmp(m1, m2, 32) == 0);
	ft_memset(m1, 'q', 5); memset(m2, 'q', 5); CHECK("memset", memcmp(m1, m2, 32) == 0);
	ft_bzero(m1, 3); bzero(m2, 3); CHECK("bzero", memcmp(m1, m2, 32) == 0);
	ft_memcpy(m1, "XYZ", 3); memcpy(m2, "XYZ", 3); CHECK("memcpy", memcmp(m1, m2, 32) == 0);
	int *z = ft_calloc(10, sizeof(int)); int ok = z != NULL; for (int q = 0; ok && q < 10; q++) ok = z[q] == 0; CHECK("calloc", ok); free(z);
	z = ft_calloc((size_t)-1, 16); CHECK("calloc overflow -> NULL", z == NULL); free(z);
	char *r;
	r = ft_substr("hello", 1, 3); CHECK("substr", r && !strcmp(r, "ell")); free(r);
	r = ft_substr("hello", 10, 3); CHECK("substr start>len", r && !strcmp(r, "")); free(r);
	r = ft_substr("hello", 2, 100); CHECK("substr len>rest", r && !strcmp(r, "llo")); free(r);
	r = ft_strjoin("ab", "cd"); CHECK("strjoin", r && !strcmp(r, "abcd")); free(r);
	r = ft_strtrim("  xx hi xx  ", " x"); CHECK("strtrim", r && !strcmp(r, "hi")); free(r);
	r = ft_strtrim("xxxx", "x"); CHECK("strtrim all", r && !strcmp(r, "")); free(r);
	r = ft_itoa(0); CHECK("itoa 0", r && !strcmp(r, "0")); free(r);
	r = ft_itoa(-2147483647 - 1); CHECK("itoa INT_MIN", r && !strcmp(r, "-2147483648")); free(r);
	r = ft_itoa(2147483647); CHECK("itoa INT_MAX", r && !strcmp(r, "2147483647")); free(r);
	r = ft_itoa(-42); CHECK("itoa -42", r && !strcmp(r, "-42")); free(r);
	char **sp = ft_split("  a bb  ccc ", ' ');
	CHECK("split", sp && !strcmp(sp[0], "a") && !strcmp(sp[1], "bb") && !strcmp(sp[2], "ccc") && sp[3] == NULL);
	for (int q = 0; sp && sp[q]; q++) free(sp[q]); free(sp);
	sp = ft_split("", ' '); CHECK("split empty", sp && sp[0] == NULL); free(sp);
	sp = ft_split("abc", '\0'); CHECK("split sep0", sp && !strcmp(sp[0], "abc") && sp[1] == NULL);
	for (int q = 0; sp && sp[q]; q++) free(sp[q]); free(sp);
	printf("libft: %d passed, %d failed\n", g_pass, g_fail);
	return (g_fail != 0);
}
