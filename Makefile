MODULES = pgtam
EXTENSION = pgtam
DATA = pgtam--0.0.1.sql

PG_LDFLAGS = -L/usr/lib64  -lunwind
PG_CONFIG = /usr/local/pgsql/bin/pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)

test:
	./test.sh
