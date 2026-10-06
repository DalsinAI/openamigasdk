/* Host test: the kit's SNPrintf and Strlcpy against the C library's. */
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <os4compat/os4compat.h>

static int fails;
static void same(const char *what, const char *mine, const char *libc)
{
	if (strcmp(mine, libc)) { printf("FAIL %s: [%s] want [%s]\n", what, mine, libc); fails++; }
}
#define T(...) do { char a[128], b[128]; LONG n = os4c_SNPrintf((STRPTR)a, sizeof a, (CONST_STRPTR)__VA_ARGS__); \
	int m = snprintf(b, sizeof b, __VA_ARGS__); same(#__VA_ARGS__, a, b); \
	if (n != m) { printf("FAIL length %s: %ld want %d\n", #__VA_ARGS__, (long)n, m); fails++; } } while (0)

int main(void)
{
	char s[8];
	T("plain"); T("%d|%i", 42, -42); T("%5d|%-5d|%05d", 7, 7, -7); T("%+d % d", 3, 3);
	T("%u %lu %llu", 3000000000u, 4000000000ul, 18000000000000000000ull);
	T("%ld %lld", -2147483647L - 1, -9223372036854775807LL - 1);
	T("%jd %ju", (intmax_t)-9000000000LL, (uintmax_t)18000000000000000000ull);
	T("%x %X %#x %08x %lx %#x", 255, 255, 255, 0xbeef, 0xdeadbeeful, 0); T("%o %#o", 8, 8);
	T("%s|%10s|%-10s|%.3s|%*s|%-*.*s|", "abc", "abc", "abc", "abcdef", 6, "ab", 6, 2, "xyz");
	T("%c%c%3c", 'o', 'k', '!'); T("100%%"); T("%.0d|%.3d", 0, 7); T("%p", (void *)0x1234);
	/* truncation keeps the would-be length */
	{ LONG n = os4c_SNPrintf((STRPTR)s, sizeof s, (CONST_STRPTR)"%s", "0123456789");
	  same("truncate", s, "0123456"); if (n != 10) { printf("FAIL truncate length %ld\n", (long)n); fails++; } }
	{ LONG n = os4c_SNPrintf(NULL, 0, (CONST_STRPTR)"%d", 12345); if (n != 5) { printf("FAIL count %ld\n", (long)n); fails++; } }
	/* BSTR */
	{ static unsigned char bs[8] __attribute__((aligned(4))) = { 3, 'b', 's', 't' }; char o[16];
	  os4c_SNPrintf((STRPTR)o, sizeof o, (CONST_STRPTR)"<%b>", (BPTR)((unsigned long)bs >> 2)); same("bstr", o, "<bst>"); }
	/* Strlcpy / Strlcat */
	if (os4c_Strlcpy((STRPTR)s, (CONST_STRPTR)"hello world", sizeof s) != 11) { puts("FAIL Strlcpy length"); fails++; }
	same("Strlcpy", s, "hello w");
	os4c_Strlcpy((STRPTR)s, (CONST_STRPTR)"ab", sizeof s);
	if (os4c_Strlcat((STRPTR)s, (CONST_STRPTR)"cdefghij", sizeof s) != 10) { puts("FAIL Strlcat length"); fails++; }
	same("Strlcat", s, "abcdefg");
	printf("%s: %d failures\n", __FILE__, fails);
	return fails != 0;
}
