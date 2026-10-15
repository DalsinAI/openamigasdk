#ifndef RESOURCES_BATTMEMBITSSHARED_H
#define RESOURCES_BATTMEMBITSSHARED_H
/*
 * OpenNDK: battery-backed memory bits shared by every OS on the machine.
 * Copyright (c) 2026 DalsinAI. MIT licence (see OpenNDK/LICENSE).
 */

/* Set means the bits below are not valid */
#define BATTMEM_SHARED_AMNESIA_ADDR	64
#define BATTMEM_SHARED_AMNESIA_LEN	1

/* The host adapter's SCSI ID, stored inverted */
#define BATTMEM_SCSI_HOST_ID_ADDR	65
#define BATTMEM_SCSI_HOST_ID_LEN	3

/* Set to allow synchronous transfers */
#define BATTMEM_SCSI_SYNC_XFER_ADDR	68
#define BATTMEM_SCSI_SYNC_XFER_LEN	1

/* Set to allow fast synchronous transfers */
#define BATTMEM_SCSI_FAST_SYNC_ADDR	69
#define BATTMEM_SCSI_FAST_SYNC_LEN	1

/* Set to allow tagged command queueing */
#define BATTMEM_SCSI_TAG_QUEUES_ADDR	70
#define BATTMEM_SCSI_TAG_QUEUES_LEN	1

#endif /* RESOURCES_BATTMEMBITSSHARED_H */
