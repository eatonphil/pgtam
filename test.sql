drop extension pgtam cascade;
create extension pgtam;
create table x(a int) using mem;
select a from x;
