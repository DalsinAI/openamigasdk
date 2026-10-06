/* Host test: __USE_INLINE__ turns bare OS 4 names into interface calls. */
#define __USE_INLINE__
#include <stdio.h>
#include <proto/test.h>
LONG call_it(void) { return TestAdd(40, 2); }   /* becomes ITest->TestAdd(40, 2) */
