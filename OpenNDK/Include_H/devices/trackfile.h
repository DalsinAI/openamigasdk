#ifndef DEVICES_TRACKFILE_H
#define DEVICES_TRACKFILE_H
/*
 * OpenNDK: trackfile.device, which presents disk image files as floppy drives.
 * Copyright (c) 2026 AmigaChrome Team. MIT licence (see OpenNDK/LICENSE).
 */

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_IO_H
#include <exec/io.h>
#endif
#ifndef DOS_DOS_H
#include <dos/dos.h>
#endif
#ifndef UTILITY_TAGITEM_H
#include <utility/tagitem.h>
#endif

/* A unit's checksum, 64 bits */
struct TrackFileChecksum
{
	ULONG	tfc_high;
	ULONG	tfc_low;
};

/* What the device says about one unit */
struct TrackFileUnitData
{
	struct TrackFileUnitData *tfud_Next;
	ULONG	tfud_Size;		/* of this structure */
	ULONG	tfud_UnitNumber;
	ULONG	tfud_DriveType;		/* DRIVE3_5 and so on */
	STRPTR	tfud_DeviceName;
	STRPTR	tfud_FileName;		/* the image file, NULL if none */
	BOOL	tfud_IsActive;
	BOOL	tfud_IsWritable;
	BOOL	tfud_MediumIsPresent;
	BOOL	tfud_IsBusy;
	BOOL	tfud_ChecksumsEnabled;
	struct TrackFileChecksum tfud_Checksum;
	BOOL	tfud_VolumeValid;	/* the next two are set */
	TEXT	tfud_VolumeName[32];
	struct DateStamp tfud_VolumeDate;
	ULONG	tfud_FileSysSignature;	/* the boot block's DOS type */
	ULONG	tfud_BootBlockChecksum;
	BOOL	tfud_CacheEnabled;
	ULONG	tfud_CacheAccesses;
	ULONG	tfud_CacheMisses;
};

/* More names from the 3.2 interface */
#define TF_Dummy		0xA0200400UL
#define TFEFS_Unsupported	(-1)
#define TFERROR_Aborted		0xFFFCEABFUL
#define TFERROR_AlreadyInUse	0xFFFCEAC4UL
#define TFERROR_Denied		0xFFFCEAB7UL
#define TFERROR_DuplicateDisk	0xFFFCEAB9UL
#define TFERROR_DuplicateVolume	0xFFFCEAB8UL
#define TFERROR_InvalidDriveType	0xFFFCEABEUL
#define TFERROR_InvalidFile	0xFFFCEAC2UL
#define TFERROR_InvalidFileSize	0xFFFCEAC1UL
#define TFERROR_NoFileGiven	0xFFFCEAC0UL
#define TFERROR_NoMediumPresent	0xFFFCEABCUL
#define TFERROR_NotSupported	0xFFFCEAB6UL
#define TFERROR_OutOfMemory	0xFFFCEAC6UL
#define TFERROR_ProcessFailed	0xFFFCEABDUL
#define TFERROR_ReadOnlyFile	0xFFFCEABAUL
#define TFERROR_ReadOnlyVolume	0xFFFCEABBUL
#define TFERROR_UnitBusy	0xFFFCEAC7UL
#define TFERROR_UnitNotActive	0xFFFCEAC3UL
#define TFERROR_UnitNotFound	0xFFFCEAC5UL
#define TFGUD_AllUnits		(-1)
#define TFSU_NextAvailableUnit	(-1)
#define TFUNIT_CONTROL		(-1)
#define TF_DriveType		(TF_Dummy + 4)
#define TF_EnableChecksums	(TF_Dummy + 6)
#define TF_EnableUnitCache	(TF_Dummy + 9)
#define TF_ImageFileHandle	(TF_Dummy + 2)
#define TF_ImageFileName	(TF_Dummy + 1)
#define TF_MINIMUM_CACHE_SIZE	0xB3B0
#define TF_MaxCacheMemory	(TF_Dummy + 8)
#define TF_PrefillUnitCache	(TF_Dummy + 10)
#define TF_TagItemFailed	(TF_Dummy + 7)
#define TF_Timeout		(TF_Dummy + 5)
#define TF_WriteProtected	(TF_Dummy + 3)

#endif /* DEVICES_TRACKFILE_H */
