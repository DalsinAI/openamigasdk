# SFD files

One per library, device or resource: `<name>_lib.sfd`. The format is the
one the OS's tools read (sfdc, fd2sfd), so other tools accept these files
too. `tools/ndkgen.py` reads this subset:

| Line | Meaning |
| --- | --- |
| `==id ...` | a free-form identity line |
| `* text` | a comment (our own copyright line goes here) |
| `==base _Name` | the base variable the stubs and inlines use |
| `==basetype struct Library *` | its type |
| `==libname name.library` | the library's name |
| `==bias 30` | the first call's offset (6 for a resource, 42 for a device after BeginIO and AbortIO) |
| `==include <exec/types.h>` | a header the prototypes need |
| `==public`, `==private` | whether the calls that follow are public |
| `==version 36` | the version the calls that follow appeared in |
| `==reserve N` | skip N slots |
| `==varargs` | the next line is the varargs form of the call before it; it takes no slot |
| `==alias` | the next line is another name for the call before it |
| `==end` | the end |

A call is one line: `RETURN NAME(TYPE name, ...) (reg,reg)`. A `DOUBLE`
takes two registers. A private slot is `VOID <lib>Private<N>() ()`. A
call whose base is an argument (a resource's, in `a6`) lists `a6` among
its registers.
