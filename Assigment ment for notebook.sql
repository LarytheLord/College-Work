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

--Assignment 3
--1.	Add a new column PhoneNumber NUMBER(10) to the Students table.
ALTER TABLE Students
ADD PhoneNumber NUMBER(10);

--2.	Set it as UNIQUE.
ALTER TABLE Students
ADD CONSTRAINT unique_phone UNIQUE (PhoneNumber);

--3.	Add a NOT NULL constraint to CourseName in Courses (if not already present).
ALTER TABLE Courses
MODIFY CourseName VARCHAR2(50) NOT NULL;

--4.	Add a CHECK constraint to ensure PhoneNumber starts with 9.
ALTER TABLE Students
ADD CONSTRAINT chk_phone_start9 CHECK (SUBSTR(TO_CHAR(PhoneNumber), 1, 1) = '9');

--5.	Rename the PhoneNumber column in the Students table to ContactNumber.
ALTER TABLE Students
RENAME COLUMN PhoneNumber TO ContactNumber;

--6.	Delete the Credits column from the Courses table
ALTER TABLE Courses
DROP COLUMN Credits;

--7.	Delete the EnrollmentDate column from the Enrollments table.
ALTER TABLE Enrollments
DROP COLUMN EnrollmentDate;



