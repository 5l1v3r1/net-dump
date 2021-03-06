#ifndef __DB_FILTER_H__
#define __DB_FILTER_H__

#include "db_entry.h"
#include "flags.h"

// A db_filter specifies various restrictions on a database's entries.
typedef struct {
  // clientMAC is the string representation of a client's MAC.
  // Valid values are 17 characters long (e.g. "aa:bb:cc:dd:ee").
  // If this filter should not check client MACs, set this field to "".
  char clientMAC[18];

  // startTime is an epoch time indicating the first allowed timestamp.
  // If this is 0, no lower bound is used.
  unsigned long long startTime;

  // endTime is an epoch time indicating the last allowed timestamp.
  // If this is 0, no upper bound is used.
  unsigned long long endTime;

  // dayMask decides which days of the week (Sunday=0 - Saturday=6) are allowed.
  // If a day d is allowed, then (dayMask & (1 << d)) != 0.
  int dayMask;
} db_filter;

db_filter db_filter_from_flags(cmd_flags * flags);

// db_filter_matches returns 1 if the entry matches the filter, or 0 otherwise.
int db_filter_matches(db_filter f, db_entry * e);

#endif
