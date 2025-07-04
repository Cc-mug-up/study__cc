USE school_management;
-- 插入教师数据
INSERT INTO teachers VALUES
(1,'王立群', '教授', '计算机科学', '2010-08-15'),
(2,'李敏', '副教授', '数学', '2015-03-20'),
(3,'张建国', '讲师', '英语', '2018-09-01'),
(4,'赵芳', '教授', '物理', '2008-11-10'),
(5,'刘伟', '助教', '体育', '2020-02-25');
select * from teachers;
-- 插入班级数据
INSERT INTO classes (class_name, grade, head_teacher) VALUES
('计算机1班', 2023, 1),
('计算机2班', 2023, 1),
('数学1班', 2023, 2),
('英语1班', 2023, 3),
('物理1班', 2023, 4);

-- 插入学生数据
INSERT INTO students (student_id, name, gender, birthdate, contact, class_id) VALUES
('20230001', '张三', '男', '2005-03-15', '13800138001', 1),
('20230002', '李四', '女', '2004-11-22', '13800138002', 1),
('20230003', '王五', '男', '2005-07-08', '13800138003', 2),
('20230004', '赵六', '女', '2004-09-18', '13800138004', 2),
('20230005', '钱七', '男', '2005-01-30', '13800138005', 3),
('20230006', '孙八', '女', '2004-12-25', '13800138006', 4),
('20230007', '周九', '男', '2005-05-12', '13800138007', 5);

-- 插入课程数据
INSERT INTO courses (course_id, course_name, credit, teacher_id, description) VALUES
('CS101', '计算机基础', 4, 1, '计算机科学入门课程'),
('MATH01', '高等数学', 6, 2, '数学系基础课程'),
('ENG001', '大学英语', 3, 3, '英语阅读与写作'),
('PHY101', '普通物理', 4, 4, '物理学基本原理'),
('PE001', '体育', 1, 5, '体育与健康'),
('CS201', '数据结构', 4, 1, '计算机核心课程');

-- 插入选课数据
INSERT INTO enrollments (student_id, course_id, academic_year, semester, grade) VALUES
('20230001', 'CS101', 2023, '春', 85.5),
('20230001', 'MATH01', 2023, '春', 92.0),
('20230001', 'ENG001', 2023, '春', 78.0),
('20230002', 'CS101', 2023, '春', 91.5),
('20230002', 'PHY101', 2023, '春', 88.0),
('20230003', 'CS101', 2023, '春', 77.0),
('20230003', 'ENG001', 2023, '春', 85.0),
('20230004', 'MATH01', 2023, '春', 93.5),
('20230004', 'PE001', 2023, '春', 95.0),
('20230005', 'PHY101', 2023, '春', 81.0),
('20230005', 'MATH01', 2023, '春', 86.5),
('20230006', 'ENG001', 2023, '春', 90.0),
('20230007', 'PHY101', 2023, '春', 79.5),
('20230001', 'CS201', 2023, '秋', NULL);

-- 插入课程安排数据
INSERT INTO schedules (class_id, course_id, weekday, start_time, end_time, location) VALUES
(1, 'CS101', '一', '08:30:00', '10:00:00', '教学楼A201'),
(1, 'MATH01', '二', '10:10:00', '11:50:00', '教学楼B103'),
(1, 'ENG001', '三', '14:00:00', '15:40:00', '外语楼308'),
(2, 'CS101', '一', '14:00:00', '15:40:00', '实验楼504'),
(2, 'PHY101', '四', '08:30:00', '10:00:00', '物理楼101'),
(3, 'MATH01', '二', '08:30:00', '10:00:00', '数学楼203'),
(3, 'ENG001', '五', '10:10:00', '11:50:00', '外语楼208'),
(4, 'ENG001', '三', '10:10:00', '11:50:00', '外语楼305'),
(4, 'PE001', '五', '14:00:00', '15:40:00', '体育馆'),
(5, 'PHY101', '四', '14:00:00', '15:40:00', '物理实验室');