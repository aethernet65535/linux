/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM perf_ibs

#if !defined(_TRACE_PERF_IBS_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_PERF_IBS_H

#include <linux/tracepoint.h>

TRACE_EVENT(ibs_nmi_rescue,

	TP_PROTO(u64 msr, u64 ctl, u64 rescued),

	TP_ARGS(msr, ctl, rescued),

	TP_STRUCT__entry(
		__field(u64, msr)
		__field(u64, ctl)
		__field(u64, rescued)
	),

	TP_fast_assign(
		__entry->msr = msr;
		__entry->ctl = ctl;
		__entry->rescued = rescued;
	),

	TP_printk("msr 0x%llx ctl 0x%llx rescued %llu",
		  (unsigned long long)__entry->msr,
		  (unsigned long long)__entry->ctl,
		  (unsigned long long)__entry->rescued)
);

#endif /* _TRACE_PERF_IBS_H */

/* This part must be outside protection */
#include <trace/define_trace.h>
