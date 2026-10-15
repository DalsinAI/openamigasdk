#ifndef LIBRARIES_LOWLEVEL_H
#define LIBRARIES_LOWLEVEL_H
/*
 * OpenNDK: lowlevel.library's structures, tags and answers.
 * Copyright (c) 2026 DalsinAI. MIT licence (see OpenNDK/LICENSE).
 */

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/* One entry of QueryKeys()'s array */
struct KeyQuery {
	UWORD	kq_KeyCode;
	BOOL	kq_Pressed;
};

/* ReadJoyPort(): what is plugged in, in the top four bits */
#define JP_TYPE_NOTAVAIL	(00<<28)
#define JP_TYPE_GAMECTLR	(01<<28)
#define JP_TYPE_MOUSE		(02<<28)
#define JP_TYPE_JOYSTK		(03<<28)
#define JP_TYPE_UNKNOWN		(04<<28)
#define JP_TYPE_MASK		(15<<28)

/* ReadJoyPort(): buttons */
#define JPB_BUTTON_BLUE		23
#define JPB_BUTTON_RED		22
#define JPB_BUTTON_YELLOW	21
#define JPB_BUTTON_GREEN	20
#define JPB_BUTTON_FORWARD	19
#define JPB_BUTTON_REVERSE	18
#define JPB_BUTTON_PLAY		17

#define JPF_BUTTON_BLUE		(1<<JPB_BUTTON_BLUE)
#define JPF_BUTTON_RED		(1<<JPB_BUTTON_RED)
#define JPF_BUTTON_YELLOW	(1<<JPB_BUTTON_YELLOW)
#define JPF_BUTTON_GREEN	(1<<JPB_BUTTON_GREEN)
#define JPF_BUTTON_FORWARD	(1<<JPB_BUTTON_FORWARD)
#define JPF_BUTTON_REVERSE	(1<<JPB_BUTTON_REVERSE)
#define JPF_BUTTON_PLAY		(1<<JPB_BUTTON_PLAY)
#define JP_BUTTON_MASK		(JPF_BUTTON_BLUE|JPF_BUTTON_RED|JPF_BUTTON_YELLOW|JPF_BUTTON_GREEN|\
				 JPF_BUTTON_FORWARD|JPF_BUTTON_REVERSE|JPF_BUTTON_PLAY)

/* ReadJoyPort(): directions, for a joystick or game controller */
#define JPB_JOY_UP	3
#define JPB_JOY_DOWN	2
#define JPB_JOY_LEFT	1
#define JPB_JOY_RIGHT	0

#define JPF_JOY_UP	(1<<JPB_JOY_UP)
#define JPF_JOY_DOWN	(1<<JPB_JOY_DOWN)
#define JPF_JOY_LEFT	(1<<JPB_JOY_LEFT)
#define JPF_JOY_RIGHT	(1<<JPB_JOY_RIGHT)
#define JP_DIRECTION_MASK	(JPF_JOY_UP|JPF_JOY_DOWN|JPF_JOY_LEFT|JPF_JOY_RIGHT)

/* ReadJoyPort(): a mouse's counters */
#define JP_MHORZ_MASK	(255<<0)
#define JP_MVERT_MASK	(255<<8)
#define JP_MOUSE_MASK	(JP_MHORZ_MASK|JP_MVERT_MASK)

/* GetKey(): the qualifiers, above the key code */
#define LLKB_LSHIFT	16
#define LLKB_RSHIFT	17
#define LLKB_CAPSLOCK	18
#define LLKB_CONTROL	19
#define LLKB_LALT	20
#define LLKB_RALT	21
#define LLKB_LAMIGA	22
#define LLKB_RAMIGA	23

#define LLKF_LSHIFT	(1<<LLKB_LSHIFT)
#define LLKF_RSHIFT	(1<<LLKB_RSHIFT)
#define LLKF_CAPSLOCK	(1<<LLKB_CAPSLOCK)
#define LLKF_CONTROL	(1<<LLKB_CONTROL)
#define LLKF_LALT	(1<<LLKB_LALT)
#define LLKF_RALT	(1<<LLKB_RALT)
#define LLKF_LAMIGA	(1<<LLKB_LAMIGA)
#define LLKF_RAMIGA	(1<<LLKB_RAMIGA)

/* SystemControlA() tags */
#define SCON_TagBase		(TAG_USER + 0x00C00000)
#define SCON_TakeOverSys	(SCON_TagBase+0)
#define SCON_KillReq		(SCON_TagBase+1)
#define SCON_CDReboot		(SCON_TagBase+2)
#define SCON_StopInput		(SCON_TagBase+3)
#define SCON_AddCreateKeys	(SCON_TagBase+4)
#define SCON_RemCreateKeys	(SCON_TagBase+5)

/* SCON_CDReboot's values */
#define CDReboot_On		1
#define CDReboot_Off		0
#define CDReboot_Default	2

/* SetJoyPortAttrsA() tags */
#define SJA_TagBase		(TAG_USER + 0x00C00100)
#define SJA_Type		(SJA_TagBase+1)
#define SJA_Reinitialize	(SJA_TagBase+2)

/* SJA_Type's values */
#define SJA_TYPE_AUTOSENSE	0
#define SJA_TYPE_GAMECTLR	1
#define SJA_TYPE_MOUSE		2
#define SJA_TYPE_JOYSTK		3

/* GetLanguageSelection() */
#define LANG_UNKNOWN	0
#define LANG_AMERICAN	1
#define LANG_ENGLISH	2
#define LANG_GERMAN	3
#define LANG_FRENCH	4
#define LANG_SPANISH	5
#define LANG_ITALIAN	6
#define LANG_PORTUGUESE	7
#define LANG_DANISH	8
#define LANG_DUTCH	9
#define LANG_NORWEGIAN	10
#define LANG_FINNISH	11
#define LANG_SWEDISH	12
#define LANG_JAPANESE	13
#define LANG_CHINESE	14
#define LANG_ARABIC	15
#define LANG_GREEK	16
#define LANG_HEBREW	17
#define LANG_KOREAN	18

#endif /* LIBRARIES_LOWLEVEL_H */
