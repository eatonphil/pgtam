drop extension pgtam cascade;
create extension pgtam;
create table x(a int) using mem;
select 1 from x;
