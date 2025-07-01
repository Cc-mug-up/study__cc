-- 创建数据库
CREATE DATABASE IF NOT EXISTS school_management;
USE school_management;

-- 1. 教师表
CREATE TABLE IF NOT EXISTS teachers (
    teacher_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(50) NOT NULL,
    title VARCHAR(20) NOT NULL,
    department VARCHAR(50) NOT NULL,
    hire_date DATE NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- 2. 班级表
CREATE TABLE IF NOT EXISTS classes (
    class_id INT PRIMARY KEY AUTO_INCREMENT,
    class_name VARCHAR(50) NOT NULL UNIQUE,
    grade TINYINT NOT NULL,
    head_teacher INT,
    FOREIGN KEY (head_teacher) REFERENCES teachers(teacher_id)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- 3. 学生表（学号唯一约束）
CREATE TABLE IF NOT EXISTS students (
    student_id CHAR(10) PRIMARY KEY, -- 格式如：202301001
    name VARCHAR(50) NOT NULL,
    gender ENUM('男','女','其他') NOT NULL,
    birthdate DATE NOT NULL,
    contact VARCHAR(50),
    class_id INT NOT NULL,
    UNIQUE KEY (student_id),
    FOREIGN KEY (class_id) REFERENCES classes(class_id)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- 4. 课程表
CREATE TABLE IF NOT EXISTS courses (
    course_id CHAR(6) PRIMARY KEY, -- 格式如：CS101
    course_name VARCHAR(100) NOT NULL,
    credit TINYINT NOT NULL CHECK (credit BETWEEN 1 AND 6),
    teacher_id INT NOT NULL,
    description TEXT,
    FOREIGN KEY (teacher_id) REFERENCES teachers(teacher_id)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- 5. 选课表（学生-课程多对多关系）
CREATE TABLE IF NOT EXISTS enrollments (
    enrollment_id INT PRIMARY KEY AUTO_INCREMENT,
    student_id CHAR(10) NOT NULL,
    course_id CHAR(6) NOT NULL,
    academic_year YEAR NOT NULL,
    semester ENUM('春','秋') NOT NULL,
    grade DECIMAL(4,1) CHECK (grade >= 0 AND grade <= 100), -- 成绩范围检查
    UNIQUE KEY (student_id, course_id, academic_year, semester),
    FOREIGN KEY (student_id) REFERENCES students(student_id),
    FOREIGN KEY (course_id) REFERENCES courses(course_id)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- 6. 课程安排表（班级课程时间表）
CREATE TABLE IF NOT EXISTS schedules (
    schedule_id INT PRIMARY KEY AUTO_INCREMENT,
    class_id INT NOT NULL,
    course_id CHAR(6) NOT NULL,
    weekday ENUM('一','二','三','四','五','六','日') NOT NULL,
    start_time TIME NOT NULL,
    end_time TIME NOT NULL,
    location VARCHAR(50) NOT NULL,
    UNIQUE KEY (class_id, weekday, start_time),
    FOREIGN KEY (class_id) REFERENCES classes(class_id),
    FOREIGN KEY (course_id) REFERENCES courses(course_id)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- 7. 报表功能（学生成绩单视图）
CREATE VIEW student_transcripts AS
SELECT 
    s.student_id,
    s.name AS student_name,
    c.class_name,
    e.course_id,
    co.course_name,
    e.academic_year,
    e.semester,
    e.grade,
    co.credit
FROM students s
JOIN enrollments e ON s.student_id = e.student_id
JOIN courses co ON e.course_id = co.course_id
JOIN classes c ON s.class_id = c.class_id;

-- 8. 报表功能（班级课程表视图）
CREATE VIEW class_timetables AS
SELECT 
    cl.class_id,
    cl.class_name,
    s.weekday,
    TIME_FORMAT(s.start_time, '%H:%i') AS start_time,
    TIME_FORMAT(s.end_time, '%H:%i') AS end_time,
    co.course_id,
    co.course_name,
    t.name AS teacher,
    s.location
FROM schedules s
JOIN classes cl ON s.class_id = cl.class_id
JOIN courses co ON s.course_id = co.course_id
JOIN teachers t ON co.teacher_id = t.teacher_id
ORDER BY 
    cl.class_id,
    FIELD(s.weekday, '一','二','三','四','五','六','日'),
    s.start_time;

-- 9. 获取学生成绩单的存储过程
DELIMITER $$
CREATE PROCEDURE GenerateStudentTranscript(IN studentID CHAR(10))
BEGIN
    SELECT * 
    FROM student_transcripts 
    WHERE student_id = studentID 
    ORDER BY academic_year DESC, 
            FIELD(semester, '秋','春');
END
$$
DELIMITER ;

-- 10. 获取班级课表的存储过程
DELIMITER $$
CREATE PROCEDURE GenerateClassTimetable(IN classID INT)
BEGIN
    SELECT *
    FROM class_timetables
    WHERE class_id = classID;
END
$$
DELIMITER ;

-- 11. 索引优化
CREATE INDEX idx_student_name ON students(name);
CREATE INDEX idx_course_name ON courses(course_name);
CREATE INDEX idx_teacher_name ON teachers(name);
create table users (
    type int NOT null,
    name char(15) not null,
    password char(15) not null
);
insert into users values(1,'cc','12345');

insert into users values(0,'xx','12345');

insert into users values(0,'yy','12345');