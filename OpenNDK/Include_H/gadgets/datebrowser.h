#ifndef GADGETS_DATEBROWSER_H
#define GADGETS_DATEBROWSER_H
/*
 * OpenNDK: datebrowser.gadget, a month's calendar to pick days from.
 * Copyright (c) 2026 DalsinAI. MIT licence (see OpenNDK/LICENSE).
 */

#ifndef REACTION_REACTION_H
#include <reaction/reaction.h>
#endif
#ifndef INTUITION_GADGETCLASS_H
#include <intuition/gadgetclass.h>
#endif

#define DATEBROWSER_Dummy		(REACTION_Dummy + 0x58000)

#define DATEBROWSER_Day			(DATEBROWSER_Dummy + 1)
#define DATEBROWSER_Month		(DATEBROWSER_Dummy + 2)
#define DATEBROWSER_Year		(DATEBROWSER_Dummy + 3)
#define DATEBROWSER_SelectedDays	(DATEBROWSER_Dummy + 4)	/* ULONG: one bit a day */
#define DATEBROWSER_WeekDay		(DATEBROWSER_Dummy + 5)
#define DATEBROWSER_FirstWDay		(DATEBROWSER_Dummy + 6)	/* the month's first weekday */
#define DATEBROWSER_NumDays		(DATEBROWSER_Dummy + 7)	/* days in the month */
#define DATEBROWSER_ShowTitle		(DATEBROWSER_Dummy + 8)	/* BOOL: day names on top */
#define DATEBROWSER_MultiSelect		(DATEBROWSER_Dummy + 9)
#define DATEBROWSER_DayTitles		(DATEBROWSER_Dummy + 10)	/* STRPTR *: seven names */
#define DATEBROWSER_JulianDate		(DATEBROWSER_Dummy + 11)

#endif /* GADGETS_DATEBROWSER_H */
