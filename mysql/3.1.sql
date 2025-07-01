USE test2;

select * from sc;

select * from student;

select * from course;

select sno from student;

select student.sno, course.cno
from course, student, sc
where
    course.cno = sc.cno
    and student.sno = sc.sno;

drop SCHEMA text;

create schema test3;

use test1;

use test2;

use test3;

create table animal (
    col1 int,
    col2 char(20),
    col3 numeric(10, 3)
);

drop table animal;

drop table animal cascade;

drop schema test3;

create table student (
    sno char(8) primary key,
    sname varchar(20) unique,
    ssex char(6),
    sbirthday Date,
    smajor varchar(40)
);

create table course (
    cno char(5) primary key,
    cname varchar(40) not null,
    ccredit smallint,
    cpno char(5),
    foreign key (cpno) references course (cno)
);

create table sc (
    sno char(8),
    cno char(5),
    grade smallint,
    semester char(5),
    teachingclass char(8),
    primary key (sno, cno),
    Foreign Key (sno) REFERENCES student (sno),
    Foreign Key (cno) REFERENCES course (cno)
);

alter table student add semail varchar(30);

alter table student modify semail char(20);

alter table student modify semail varchar(20);

alter table course add unique (cname);

drop table student;

create view cs_student AS
select
    Sno,
    Sname,
    Ssex,
    Sbirthdate,
    Smajor
from student
where
    Smajor = '计算机科学与技术';

select * from cs_student;

create unique index Idx_StuSname on student (Sname);

create unique index Idx_CouCname on course (Cname);

create unique index Idx_SCCno on sc (Sno asc, Cno desc);

ALTER TABLE sc DROP INDEX Idx_SCCno;

ALTER TABLE sc ADD INDEX Idx_SCCno (Sno asc, Cno desc);

SELECT DATABASE();

SELECT *
FROM information_schema.COLUMNS
WHERE
    TABLE_NAME = 'student';

alter table animal ADD col4 char(20);