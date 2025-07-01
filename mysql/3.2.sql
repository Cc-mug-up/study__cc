use test2;

select Sno, Sname from student;

select Sname, Sno, Smajor from student;

select * from student;

select Sname, (
        extract(
            year
            from current_date
        ) - extract(
            year
            from Sbirthdate
        )
    ) "年龄"
from student;

select Sname, "Date of Birth:", Sbirthdate, Smajor from student;

select distinct Sno from student;

select * from student;

select Sname from student where Smajor = "计算机科学与技术";

select Sname, Ssex, Sbirthdate
from student
where
    extract(
        year
        from Sbirthdate
    ) >= 2000;
--查询成绩及格的学生的学号
select distinct Sno from sc where Grade >= 60;
--查询年龄在20~30间的学生
select Sname, Sbirthdate, Smajor
from student
where (
        extract(
            year
            from current_date
        ) - extract(
            year
            from Sbirthdate
        ) not between 18 and 24
    );

select Sname, Ssex, Smajor
from student
where
    Smajor not in("计算机科学与技术", "信息安全");
--字符串匹配
select * from student where Sno = "20180003";

select * from student where Sno LIKE "20180003";

select * from student where Sno LIKE "2018000_";

select * from student where Sno LIKE "%2";

select Sname, Sno, Ssex from student where Sname like "王%";

select Sno, Sname from student where Sno LIKE "2018%";

select Cno, Cname from course where Cno like "81%6";

select Sname, Sno, Ssex from student where Sname not like "王%";
--转义字符将_  % 转换成真正意义
select * from sc where Grade is not null;

select *
from student
where
    Smajor not like "计算机科学与技术"
    and extract(
        year
        from Sbirthdate
    ) >= 2000;

select Sno, Grade from sc where Cno like "81003" order by Grade desc;

select Sno, Grade from sc where Cno like "81003" order by Grade asc;

select Cno, MAX(Grade) as highgrade
from sc
group by
    Cno
order by highgrade desc;

select count(*) from student;

select count(distinct Sno) from sc;

select avg(Grade) from sc where Cno = "81001";

select max(Grade) from sc where Cno = "81001";

select sum(Ccredit)
from sc, course
where
    sc.`Cno` = course.`Cno`
    and sc.`Sno` = "20180001";

select Cno, count(Sno) from sc group by Cno;

select Sno
from sc
where
    `Semester` = "20192"
group by
    `Sno`
having
    count(*) >= 1;

select * from sc where `Semester` = "20192";

select Sno, avg(Grade)
from sc
group by
    `Sno`
having
    avg(Grade) >= 75;
--having作用于组
select sno, Grade
from sc, course
where
    course.`Cname` = "数据库系统概论"
    and sc.`Cno` = course.`Cno`
order by Grade desc
limit 4;

select Sno, avg(Grade)
from sc
group by
    Sno
order by avg(Grade) DESC
limit 5
offset
    3;
--自然连接
select student.`Sno`, student.`Sname`, student.`Ssex`, student.`Sbirthdate`, sc.`Cno`, sc.`Grade`, sc.`Semester`
from student, sc
where
    student.Sno = sc.`Sno`;

select student.Sno, Sname, sc.`Cno`, sc.`Grade`
from sc, student
where
    sc.`Sno` = student.`Sno`
    and sc.`Cno` = "81002"
    and sc.`Grade` >= 90;

select first.Cno, Second.Cpno
from course first, course second
where
    first.`Cpno` = second.`Cno`
    and second.`Cpno` is not null;

select
    student.`Sno`,
    Sname,
    Ssex,
    Sbirthdate,
    Smajor,
    Cno,
    Grade
from student
    left outer join sc on (student.`Sno` = sc.`Sno`);

select student.`Sno`, student.Sname, course.Cname, sc.Grade
from student, sc, course
where
    student.`Sno` = sc.`Sno`
    and course.`Cno` = sc.`Cno`;

select Sname, sno
from student
where
    sno in (
        select Sno
        from sc
        where
            Cno = "81001"
    );

select Sno, Sname, Smajor
from student
where
    Smajor in (
        select Smajor
        from student
        where
            Sname = "刘晨"
    );

select Sno, Sname
from student
where
    Sno in (
        select Sno
        from sc
        where
            Cno in (
                select Cno
                from course
                where
                    Cname = "数据结构"
            )
    );

select Sno, Cno
from sc x
where
    Grade >= (
        select avg(Grade)
        from sc y
        where
            y.`Sno` = x.`Sno`
    );

select Sname, Sbirthdate, Smajor
from student
where
    Sbirthdate > any (
        select Sbirthdate
        from student
        where
            Smajor = "计算机科学与技术"
    )
    and Smajor <> "计算机科学与技术";

select Sname, Sbirthdate, Smajor
from student
where
    Sbirthdate > (
        select min(Sbirthdate)
        from student
        where
            Smajor = "计算机科学与技术"
    )
    and Smajor <> "计算机科学与技术";

select Sname, Sbirthdate, Smajor
from student
where
    Sbirthdate > all (
        select Sbirthdate
        from student
        where
            Smajor = "计算机科学与技术"
    )
    and Smajor <> "计算机科学与技术";

select Sname, Sbirthdate, Smajor
from student
where
    Sbirthdate > (
        select max(Sbirthdate)
        from student
        where
            Smajor = "计算机科学与技术"
    )
    and Smajor <> "计算机科学与技术";

select Sname
from student
where
    exists (
        select *
        from sc
        where
            sc.`Sno` = student.`Sno`
            and sc.`Cno` = "81001"
    );

select * from sc;

select Sname
from student
where
    not exists (
        select *
        from sc
        where
            sc.`Sno` = student.`Sno`
            and sc.`Cno` = "81001"
    );

select Sname
from student
where
    exists (
        select *
        from course
        where
            not exists (
                select *
                from sc
                where
                    sc.`Sno` = student.`Sno`
                    AND sc.`Cno` = course.`Cno`
            )
    );
select *
from student 
where Smajor="计算机科学与技术"
UNION
select *
from student 
where tIMESTAMPDIFF(YEAR, Sbirthdate, current_date)<=25;
select * 
from sc
where Semester='20201'and Cno='81001'
UNION
select * 
from sc
where Semester='20201'and Cno='81002';
select * from sc;
select *
from student 
where Smajor="计算机科学与技术"
intersect
select *
from student 
where tIMESTAMPDIFF(YEAR, Sbirthdate, current_date)<=26;
use test2;
select *
from student 
where tIMESTAMPDIFF(YEAR, Sbirthdate, current_date)<=25
except
select *
from student 
where Smajor="计算机科学与技术";
select Sno,Cno
from sc,(select Sno,avg(Grade)from sc group by Sno)
        AS avg_sc(avg_Sno,avg_Grade)
where sc.`Sno`=avg_sc.avg_Sno and sc.`Grade`>=avg_sc.avg_Grade;