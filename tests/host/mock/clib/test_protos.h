#include <exec/types.h>
#include <utility/tagitem.h>
VOID TestNothing(void); APTR TestTagsA(ULONG kind, struct TagItem *tags);
LONG TestVPrint(CONST_STRPTR fmt, APTR args); LONG TestHook(LONG (*func)(LONG), LONG v);
