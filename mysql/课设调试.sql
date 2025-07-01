CALL GenerateStudentTranscript ('20230001');

CALL GenerateClassTimetable (1);

select * from student_transcripts;

select * from class_timetables;

select * from courses where course_id = "CS101";

update students set name = '÷‹÷‹' WHERE student_id = '20230007';