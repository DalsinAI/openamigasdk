/* Copyright (c) 2026 AmigaChrome Team. MIT licence (see OpenNDK/LICENSE). */
/* CheckRexxMsg and SetRexxVar: the Rexx variable interface helpers, over
 * rexxsyslib.library V45's SetRexxVarFromMsg. Both take rexxsyslib's base
 * from the message itself, so the caller needn't have opened the library. */
#include "alib.h"
#include <rexx/storage.h>
#include <rexx/rxslib.h>
#include <rexx/errors.h>
#include <proto/rexxsyslib.h>

#define REXX_MAX_STRING	65535	/* the longest ARexx string */

BOOL CheckRexxMsg(CONST struct RexxMsg *message)
{
	struct RxsLib *RexxSysBase;

	if (!message || !message->rm_TaskBlock || !message->rm_LibBase)
		return FALSE;
	RexxSysBase = (struct RxsLib *)message->rm_LibBase;
	return IsRexxMsg(message) ? TRUE : FALSE;
}

LONG SetRexxVar(struct RexxMsg *message, CONST_STRPTR varname, CONST_STRPTR value, LONG length)
{
	struct RxsLib *RexxSysBase;
	STRPTR copy;
	LONG i;
	LONG error;

	if (!CheckRexxMsg(message))
		return ERR10_010;
	RexxSysBase = (struct RxsLib *)message->rm_LibBase;
	if (RexxSysBase->rl_Node.lib_Version < 45)
		return ERR10_010;	/* no SetRexxVarFromMsg before V45 */
	if (length < 0 || length > REXX_MAX_STRING)
		return ERR10_009;
	/* SetRexxVarFromMsg takes a NUL-terminated value */
	copy = (STRPTR)AllocVec(length + 1, MEMF_ANY);
	if (!copy)
		return ERR10_003;
	for (i = 0; i < length; i++)
		copy[i] = value[i];
	copy[length] = 0;
	error = SetRexxVarFromMsg(varname, message, copy);
	FreeVec(copy);
	return error;
}
