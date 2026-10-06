/* Host test: an OS 4 style program calling a generated interface. */
#include <stdio.h>
#include <string.h>
#include <proto/test.h>   /* the generated override: ITest, struct TestIFace */

struct Library *TestBase;
static int fails;
#define CHECK(c) do { if (!(c)) { printf("FAIL %s:%d %s\n", __FILE__, __LINE__, #c); fails++; } } while (0)

/* what the "library" does */
static struct Library fake = { { 0, 0, 0, 0, (char *)"test.library" } };
static struct Library *seen_base;
LONG TestAdd_(void *base, LONG a, LONG b) { seen_base = base; return a + b; }
VOID TestNothing(void) { }
static ULONG last_tag;
APTR TestTagsA(ULONG kind, struct TagItem *tags) { last_tag = tags[0].ti_Tag; return (APTR)(unsigned long)kind; }
static CONST_STRPTR last_fmt;
LONG TestVPrint(CONST_STRPTR fmt, APTR args) { (void)args; last_fmt = fmt; return 7; }
static LONG twice(LONG v) { return v * 2; }
LONG TestHook(LONG (*func)(LONG), LONG v) { return func(v); }

/* the kit's side, cut down for the host */
struct Library *os4c_OpenBase(struct Interface *i) { i->Data.LibBase = &fake; return &fake; }
ULONG os4c_IfaceObtain(void) { return 1; }
ULONG os4c_IfaceRelease(void) { return 0; }
VOID os4c_IfaceExpunge(void) { }
struct Interface *os4c_IfaceClone(void) { return 0; }

int main(void)
{
	CHECK(ITest != 0);
	CHECK(ITest->TestAdd(2, 3) == 5);
	CHECK(seen_base == &fake);                       /* opened on first use */
	CHECK(ITest->Data.LibBase == &fake);
	ITest->TestNothing();
	CHECK(ITest->TestTags(9, 0x80001234UL, 1, 0) == (APTR)9);
	CHECK(last_tag == 0x80001234UL);
	CHECK(ITest->TestPrint((CONST_STRPTR)"x%ld", 1L) == 7);
	CHECK(last_fmt && strcmp((const char *)last_fmt, "x%ld") == 0);
	CHECK(ITest->TestHook(twice, 21) == 42);
	CHECK(os4c_registry[0] == (struct Interface *)ITest && os4c_registry[1] == 0);
	CHECK(strcmp((const char *)ITest->Data.LibName, "test.library") == 0);
	printf("%s: %d failures\n", __FILE__, fails);
	return fails != 0;
}
