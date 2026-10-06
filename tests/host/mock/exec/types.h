/* Host test stand-in for the NDK's exec/types.h: only what os4compat.h uses. */
#ifndef EXEC_TYPES_H
#define EXEC_TYPES_H
typedef void *APTR; typedef unsigned long ULONG; typedef long LONG;
typedef unsigned short UWORD; typedef short WORD; typedef unsigned char UBYTE; typedef signed char BYTE;
typedef short BOOL; typedef void VOID; typedef unsigned char *STRPTR; typedef const unsigned char *CONST_STRPTR;
typedef ULONG Tag; typedef long BPTR;
#define TRUE 1
#define FALSE 0
#ifndef NULL
#define NULL ((void *)0)
#endif
struct Node { struct Node *ln_Succ, *ln_Pred; UBYTE ln_Type; BYTE ln_Pri; char *ln_Name; };
struct MinNode { struct MinNode *mln_Succ, *mln_Pred; };
struct List { struct Node *lh_Head, *lh_Tail, *lh_TailPred; UBYTE lh_Type, l_pad; };
struct MinList { struct MinNode *mlh_Head, *mlh_Tail, *mlh_TailPred; };
struct Library { struct Node lib_Node; };
struct TagItem { Tag ti_Tag; ULONG ti_Data; };
#define TAG_USER (1UL << 31)
#define TAG_DONE 0
struct DateStamp { LONG ds_Days, ds_Minute, ds_Tick; };
#define BADDR(b) ((APTR)((ULONG)(b) << 2))
#define ST_ROOT 1
#define ST_USERDIR 2
#define ST_SOFTLINK 3
#define ST_LINKDIR 4
#define ST_FILE -3
#define ST_LINKFILE -4
#define ST_PIPEFILE -5
typedef ULONG Object; typedef struct { ULONG MethodID; } *Msg;
#define MEMF_ANY 0
#endif
