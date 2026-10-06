/* Host test stand-in for an NDK proto header. Like the real inlines, each
 * call names its base through TEST_BASE_NAME. */
#ifndef PROTO_TEST_H
#define PROTO_TEST_H
#include <exec/types.h>
#include <utility/tagitem.h>
extern struct Library *TestBase;
#ifndef TEST_BASE_NAME
#define TEST_BASE_NAME TestBase
#endif
LONG TestAdd_(void *base, LONG a, LONG b);
#define TestAdd(a, b) TestAdd_(TEST_BASE_NAME, a, b)
VOID TestNothing(void); APTR TestTagsA(ULONG kind, struct TagItem *tags);
LONG TestVPrint(CONST_STRPTR fmt, APTR args); LONG TestHook(LONG (*func)(LONG), LONG v);
#endif
