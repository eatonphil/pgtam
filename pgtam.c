#include "postgres.h"
#include "fmgr.h" // For PG_GETARG_INT32
#include "access/tableam.h"
#include "access/heapam.h"
#include "nodes/execnodes.h"
#include "catalog/index.h"
#include "commands/vacuum.h"

PG_MODULE_MAGIC;

static const TableAmRoutine memam_methods;

static const TupleTableSlotOps* memam_slot_callbacks(
  Relation relation
) {
  return NULL;
}

static TableScanDesc mem_beginscan(
  Relation relation,
  Snapshot snapshot,
  int nkeys,
  struct ScanKeyData *key,
  ParallelTableScanDesc parallel_scan,
  uint32 flags
) {}

static void mem_rescan(
  TableScanDesc sscan,
  struct ScanKeyData *key,
  bool set_params,
  bool allow_strat,
  bool allow_sync,
  bool allow_pagemode
) {}

static void mem_endscan(TableScanDesc sscan) {}

static bool mem_getnextslot(
  TableScanDesc sscan,
  ScanDirection direction,
  TupleTableSlot *slot
) {
  return false;
}

static void mem_set_tidrange(
  TableScanDesc sscan,
  ItemPointer mintid,
  ItemPointer maxtid
) {}

static bool mem_getnextslot_tidrange(
  TableScanDesc sscan,
  ScanDirection direction,
  TupleTableSlot *slot
) {
  return false;
}

/* static Size table_block_parallelscan_estimate(Relation rel) { */
/*   return 0; */
/* } */

/* static Size table_block_parallelscan_initialize( */
/*   Relation rel, */
/*   ParallelTableScanDesc pscan */
/* ) { */
/*   return 0; */
/* } */

/* static void table_block_parallelscan_reinitialize( */
/*   Relation rel, */
/*   ParallelTableScanDesc pscan */
/* ) {} */

static IndexFetchTableData* mem_index_fetch_begin(Relation rel) {
  return NULL;
}

static void mem_index_fetch_reset(IndexFetchTableData *scan) {}

static void mem_index_fetch_end(IndexFetchTableData *scan) {}

static bool mem_index_fetch_tuple(
  struct IndexFetchTableData *scan,
  ItemPointer tid,
  Snapshot snapshot,
  TupleTableSlot *slot,
  bool *call_again,
  bool *all_dead
) {}

static void mem_tuple_insert(
  Relation relation,
  TupleTableSlot *slot,
  CommandId cid,
  int options,
  BulkInsertState bistate
) {}

static void mem_tuple_insert_speculative(
  Relation relation,
  TupleTableSlot *slot,
  CommandId cid,
  int options,
  BulkInsertState bistate,
  uint32 specToken) {}

static void mem_tuple_complete_speculative(
  Relation relation,
  TupleTableSlot *slot,
  uint32 specToken,
  bool succeeded) {}

static void mem_multi_insert(
  Relation relation,
  TupleTableSlot **slots,
  int ntuples,
  CommandId cid,
  int options,
  BulkInsertState bistate
) {}

static TM_Result mem_tuple_delete(
  Relation relation,
  ItemPointer tid,
  CommandId cid,
  Snapshot snapshot,
  Snapshot crosscheck,
  bool wait,
  TM_FailureData *tmfd,
  bool changingPart
) {
  TM_Result result;
  return result;
}

static TM_Result mem_tuple_update(
  Relation relation,
  ItemPointer otid,
  TupleTableSlot *slot,
  CommandId cid,
  Snapshot snapshot,
  Snapshot crosscheck,
  bool wait,
  TM_FailureData *tmfd,
  LockTupleMode *lockmode,
  TU_UpdateIndexes *update_indexes
) {
  TM_Result result;
  return result;
}

static TM_Result mem_tuple_lock(
  Relation relation,
  ItemPointer tid,
  Snapshot snapshot,
  TupleTableSlot *slot,
  CommandId cid,
  LockTupleMode mode,
  LockWaitPolicy wait_policy,
  uint8 flags,
  TM_FailureData *tmfd)
{
  TM_Result result;
  return result;
}

static bool mem_fetch_row_version(
  Relation relation,
  ItemPointer tid,
  Snapshot snapshot,
  TupleTableSlot *slot
) {
  return false;
}

static void mem_get_latest_tid(
  TableScanDesc sscan,
  ItemPointer tid
) {}

static bool mem_tuple_tid_valid(TableScanDesc scan, ItemPointer tid) {
  return false;
}

static bool mem_tuple_satisfies_snapshot(
  Relation rel,
  TupleTableSlot *slot,
  Snapshot snapshot
) {
  return false;
}

static TransactionId mem_index_delete_tuples(
  Relation rel,
  TM_IndexDeleteOp *delstate
) {
  TransactionId id;
  return id;
}

static void mem_relation_set_new_filelocator(
  Relation rel,
  const RelFileLocator *newrlocator,
  char persistence,
  TransactionId *freezeXid,
  MultiXactId *minmulti
) {}

static void mem_relation_nontransactional_truncate(
  Relation rel
) {}

static void mem_relation_copy_data(
  Relation rel,
  const RelFileLocator *newrlocator
) {}

static void mem_relation_copy_for_cluster(
  Relation OldHeap,
  Relation NewHeap,
  Relation OldIndex,
  bool use_sort,
  TransactionId OldestXmin,
  TransactionId *xid_cutoff,
  MultiXactId *multi_cutoff,
  double *num_tuples,
  double *tups_vacuumed,
  double *tups_recently_dead
) {}

static void mem_vacuum_rel(
  Relation rel,
  VacuumParams *params,
  BufferAccessStrategy bstrategy
) {}

static bool mem_scan_analyze_next_block(
  TableScanDesc scan,
  BlockNumber blockno,
  BufferAccessStrategy bstrategy
) {
  return false;
}

static bool mem_scan_analyze_next_tuple(
  TableScanDesc scan,
  TransactionId OldestXmin,
  double *liverows,
  double *deadrows,
  TupleTableSlot *slot
) {
  return false;
}

static double mem_index_build_range_scan(
  Relation heapRelation,
  Relation indexRelation,
  IndexInfo *indexInfo,
  bool allow_sync,
  bool anyvisible,
  bool progress,
  BlockNumber start_blockno,
  BlockNumber numblocks,
  IndexBuildCallback callback,
  void *callback_state,
  TableScanDesc scan
) {
  return 0;
}

static void mem_index_validate_scan(
  Relation heapRelation,
  Relation indexRelation,
  IndexInfo *indexInfo,
  Snapshot snapshot,
  ValidateIndexState *state
) {}

/* static uint64 table_block_relation_size( */
/*   Relation rel, */
/*   ForkNumber forkNumber */
/* ) { */
/*   return 0; */
/* } */

static bool mem_relation_needs_toast_table(Relation rel) {
  return false;
}

static Oid mem_relation_toast_am(Relation rel) {
  Oid oid;
  return oid;
}

static void mem_fetch_toast_slice(
  Relation toastrel,
  Oid valueid,
  int32 attrsize,
  int32 sliceoffset,
  int32 slicelength,
  struct varlena *result
) {}

static void mem_estimate_rel_size(
  Relation rel,
  int32 *attr_widths,
  BlockNumber *pages,
  double *tuples,
  double *allvisfrac
) {}

static bool mem_scan_bitmap_next_block(
  TableScanDesc scan,
  TBMIterateResult *tbmres
) {
  return false;
}

static bool mem_scan_bitmap_next_tuple(
  TableScanDesc scan,
  TBMIterateResult *tbmres,
  TupleTableSlot *slot
) {
  return false;
}

static bool mem_scan_sample_next_block(
  TableScanDesc scan, SampleScanState *scanstate
) {
  return false;
}

static bool mem_scan_sample_next_tuple(
  TableScanDesc scan,
  SampleScanState *scanstate,
  TupleTableSlot *slot
) {
  return false;
}

static const TableAmRoutine memam_methods = {
  .type = T_TableAmRoutine,

  .slot_callbacks = memam_slot_callbacks,

  .scan_begin = mem_beginscan,
  .scan_end = mem_endscan,
  .scan_rescan = mem_rescan,
  .scan_getnextslot = mem_getnextslot,

  .scan_set_tidrange = mem_set_tidrange,
  .scan_getnextslot_tidrange = mem_getnextslot_tidrange,

  .parallelscan_estimate = table_block_parallelscan_estimate,
  .parallelscan_initialize = table_block_parallelscan_initialize,
  .parallelscan_reinitialize = table_block_parallelscan_reinitialize,

  .index_fetch_begin = mem_index_fetch_begin,
  .index_fetch_reset = mem_index_fetch_reset,
  .index_fetch_end = mem_index_fetch_end,
  .index_fetch_tuple = mem_index_fetch_tuple,

  .tuple_insert = mem_tuple_insert,
  .tuple_insert_speculative = mem_tuple_insert_speculative,
  .tuple_complete_speculative = mem_tuple_complete_speculative,
  .multi_insert = mem_multi_insert,
  .tuple_delete = mem_tuple_delete,
  .tuple_update = mem_tuple_update,
  .tuple_lock = mem_tuple_lock,

  .tuple_fetch_row_version = mem_fetch_row_version,
  .tuple_get_latest_tid = mem_get_latest_tid,
  .tuple_tid_valid = mem_tuple_tid_valid,
  .tuple_satisfies_snapshot = mem_tuple_satisfies_snapshot,
  .index_delete_tuples = mem_index_delete_tuples,

  .relation_set_new_filelocator = mem_relation_set_new_filelocator,
  .relation_nontransactional_truncate = mem_relation_nontransactional_truncate,
  .relation_copy_data = mem_relation_copy_data,
  .relation_copy_for_cluster = mem_relation_copy_for_cluster,
  .relation_vacuum = mem_vacuum_rel,
  .scan_analyze_next_block = mem_scan_analyze_next_block,
  .scan_analyze_next_tuple = mem_scan_analyze_next_tuple,
  .index_build_range_scan = mem_index_build_range_scan,
  .index_validate_scan = mem_index_validate_scan,

  .relation_size = table_block_relation_size,
  .relation_needs_toast_table = mem_relation_needs_toast_table,
  .relation_toast_am = mem_relation_toast_am,
  .relation_fetch_toast_slice = mem_fetch_toast_slice,

  .relation_estimate_size = mem_estimate_rel_size,

  .scan_bitmap_next_block = mem_scan_bitmap_next_block,
  .scan_bitmap_next_tuple = mem_scan_bitmap_next_tuple,
  .scan_sample_next_block = mem_scan_sample_next_block,
  .scan_sample_next_tuple = mem_scan_sample_next_tuple
};

PG_FUNCTION_INFO_V1(mem_tableam_handler);

Datum mem_tableam_handler(PG_FUNCTION_ARGS) {
  PG_RETURN_POINTER(&memam_methods);
}
