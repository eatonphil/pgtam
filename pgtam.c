#include "postgres.h"
#include "fmgr.h" // For PG_GETARG_INT32
#include "executor/executor.h"
#include "access/tableam.h"

PG_MODULE_MAGIC;

/* by value */

static const TableAmRoutine memam_methods;

static const TupleTableSlotOps *
memam_slot_callbacks(Relation relation)
{
	return &TTSOpsBufferHeapTuple;
}

TableScanDesc mem_beginscan(
  Relation relation,
  Snapshot snapshot,
  int nkeys,
  struct ScanKeyData *key,
  ParallelTableScanDesc parallel_scan,
  uint32 flags) {}

void mem_rescan(
  TableScanDesc sscan,
  struct ScanKeyData *key,
  bool set_params,
  bool allow_strat,
  bool allow_sync,
  bool allow_pagemode) {}

void mem_endscan(TableScanDesc sscan) {}

bool mem_getnextslot(
  TableScanDesc sscan,
  ScanDirection direction,
  TupleTableSlot *slot
) {
  return true;
}


static const TableAmRoutine memam_methods = {
  .type = T_TableAmRoutine,

  .slot_callbacks = memam_slot_callbacks,

  .scan_begin = mem_beginscan,
  .scan_end = mem_endscan,
  .scan_rescan = mem_rescan,
  .scan_getnextslot = mem_getnextslot,
};

PG_FUNCTION_INFO_V1(mem_tableam_handler);

Datum
mem_tableam_handler(PG_FUNCTION_ARGS)
{
	PG_RETURN_POINTER(&memam_methods);
}
