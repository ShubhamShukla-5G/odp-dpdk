/* Copyright (c) 2016-2018, Linaro Limited
 * Copyright (c) 2020, Nokia
 * All rights reserved.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 */

#ifndef ODP_CONFIG_INTERNAL_H_
#define ODP_CONFIG_INTERNAL_H_

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Maximum number of supported CPU identifiers. The maximum supported CPU ID is
 * CONFIG_NUM_CPU_IDS - 1. Note that the maximum number of ODP threads is
 * defined by ODP_THREAD_COUNT_MAX.
 */
#define CONFIG_NUM_CPU_IDS 256

/*
 * Maximum number of pools
 */
#define ODP_CONFIG_POOLS 256

/*
 * Queues reserved for ODP internal use
 */
#define CONFIG_INTERNAL_QUEUES 64

/*
 * Maximum number of plain ODP queues
 */
#define CONFIG_MAX_PLAIN_QUEUES 1024

/*
 * Maximum number of scheduled ODP queues
 *
 * Must be a power of two.
 */
#define CONFIG_MAX_SCHED_QUEUES 1024

/*
 * Maximum number of queues
 */
#define CONFIG_MAX_QUEUES (CONFIG_INTERNAL_QUEUES + \
			   CONFIG_MAX_PLAIN_QUEUES + \
			   CONFIG_MAX_SCHED_QUEUES)

/*
 * Maximum number of ordered locks per queue
 */
#define CONFIG_QUEUE_MAX_ORD_LOCKS 2

/*
 * Maximum number of packet IO resources
 */
#define ODP_CONFIG_PKTIO_ENTRIES 64

/*
 * Minimum buffer alignment
 *
 * This defines the minimum supported buffer alignment. Requests for values
 * below this will be rounded up to this value.
 */
#define ODP_CONFIG_BUFFER_ALIGN_MIN 16

/*
 * Maximum buffer alignment
 *
 * This defines the maximum supported buffer alignment. Requests for values
 * above this will fail.
 */
#define ODP_CONFIG_BUFFER_ALIGN_MAX (4 * 1024)

/*
 * Default packet headroom
 *
 * This defines the minimum number of headroom bytes that newly created packets
 * have by default. The default apply to both ODP packet input and user
 * allocated packets. Implementations may reserve a larger than minimum headroom
 * size e.g. due to HW or a protocol specific alignment requirement.
 *
 * @internal In odp-dpdk implementation:
 * The default value (128) allows a 1500-byte packet to be received into a
 * single segment with room for some header expansion.
 */
#define CONFIG_PACKET_HEADROOM 128

/*
 * Default packet tailroom
 *
 * This defines the minimum number of tailroom bytes that newly created packets
 * have by default. The default apply to both ODP packet input and user
 * allocated packets. Implementations are free to add to this as desired
 * without restriction. Note that most implementations will automatically
 * consider any unused portion of the last segment of a packet as tailroom
 */
#define CONFIG_PACKET_TAILROOM 0

/*
 * Maximum number of segments per packet
 */
#define CONFIG_PACKET_MAX_SEGS 60

/*
 * Minimum packet segment length
 *
 * This defines the minimum packet segment buffer length in bytes. The user
 * defined segment length (seg_len in odp_pool_param_t) will be rounded up into
 * this value.
 */
#define CONFIG_PACKET_SEG_LEN_MIN 1024

/*
 * Maximum packet segment length
 *
 * This defines the maximum packet segment buffer length in bytes. The user
 * defined segment length (seg_len in odp_pool_param_t) must not be larger than
 * this.
 */
#define CONFIG_PACKET_SEG_LEN_MAX (CONFIG_PACKET_MAX_SEGS * \
				   (CONFIG_PACKET_SEG_LEN_MIN - \
				    CONFIG_PACKET_HEADROOM - \
				    CONFIG_PACKET_TAILROOM))

/* Maximum number of shared memory blocks.
 *
 * This the the number of separate SHM areas that can be reserved concurrently
 */
#define ODP_CONFIG_SHM_BLOCKS (ODP_CONFIG_POOLS + 48)

/*
 * Maximum event burst size
 *
 * This controls the burst size on various enqueue, dequeue, etc calls. Large
 * burst size improves throughput, but may degrade QoS (increase latency).
 */
#define CONFIG_BURST_SIZE 32

/*
 * Maximum number of events in a pool. Power of two minus one results optimal
 * memory usage.
 */
#define CONFIG_POOL_MAX_NUM ((1024 * 1024) - 1)

/* Maximum packet vector size */
#define CONFIG_PACKET_VECTOR_MAX_SIZE 256

#ifdef __cplusplus
}
#endif

#endif
