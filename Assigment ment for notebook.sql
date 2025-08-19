--assigment 1
CREATE TABLE Students (
    StudentID      NUMBER(12) PRIMARY KEY,
    Name           VARCHAR2(50) NOT NULL,
    Email          VARCHAR2(50) UNIQUE,
    Age            NUMBER(2) CHECK (Age >= 18)
);

--assignement 2
--table 1 courses
CREATE TABLE Courses (
    CourseID       VARCHAR2(10) PRIMARY KEY,
    CourseName     VARCHAR2(50) NOT NULL,
    Credits        NUMBER(2) CHECK (Credits BETWEEN 1 AND 5)
);

--table 2
CREATE TABLE Enrollments (
    StudentID       NUMBER(12),
    CourseID        VARCHAR2(10),
    EnrollmentDate  DATE NOT NULL,
    CONSTRAINT fk_student FOREIGN KEY (StudentID) REFERENCES Students(StudentID),
    CONSTRAINT fk_course FOREIGN KEY (CourseID) REFERENCES Courses(CourseID),
    CONSTRAINT pk_enrollments PRIMARY KEY (StudentID, CourseID)
);

