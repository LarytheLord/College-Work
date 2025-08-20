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

//unclear from here on 

give indian names with variety
ChatGPT said:

Sure! Here's a version of the INSERT statements using a variety of Indian names (covering different regions and genders) for students and courses:

✅ Step 1: Insert 5 Students (with Indian Names)
INSERT INTO Students (StudentID, Name, Email, Age, ContactNumber)
VALUES (1001, 'Aarav Mehta', 'aarav.mehta@example.com', 19, 9123456789);

INSERT INTO Students (StudentID, Name, Email, Age, ContactNumber)
VALUES (1002, 'Neha Sharma', 'neha.sharma@example.com', 20, 9234567890);

INSERT INTO Students (StudentID, Name, Email, Age, ContactNumber)
VALUES (1003, 'Rahul Reddy', 'rahul.reddy@example.com', 21, 9345678901);

INSERT INTO Students (StudentID, Name, Email, Age, ContactNumber)
VALUES (1004, 'Priya Iyer', 'priya.iyer@example.com', 22, 9456789012);

INSERT INTO Students (StudentID, Name, Email, Age, ContactNumber)
VALUES (1005, 'Tanvi Patel', 'tanvi.patel@example.com', 23, 9567890123);


✅ Includes names from North, South, and West India for diversity.

✅ Step 2: Insert 3 Courses (with practical-sounding Indian context)
INSERT INTO Courses (CourseID, CourseName)
VALUES ('CS101', 'Intro to Programming');

INSERT INTO Courses (CourseID, CourseName)
VALUES ('MTH102', 'Applied Mathematics');

INSERT INTO Courses (CourseID, CourseName)
VALUES ('ENG103', 'English Communication Skills');

✅ Step 3: Enroll each student in at least one course
INSERT INTO Enrollments (StudentID, CourseID)
VALUES (1001, 'CS101');

INSERT INTO Enrollments (StudentID, CourseID)
VALUES (1002, 'MTH102');

INSERT INTO Enrollments (StudentID, CourseID)
VALUES (1003, 'ENG103');

INSERT INTO Enrollments (StudentID, CourseID)
VALUES (1004, 'CS101');

INSERT INTO Enrollments (StudentID, CourseID)
VALUES (1005, 'MTH102');

✅ Step 4: Update one student's email
UPDATE Students
SET Email = 'aarav.newmail@example.com'
WHERE StudentID = 1001;


Let me know if you want to add more students/courses, or if you'd like to simulate batch insert scripts or generate randomized data for larger testing.

You said:
CONSTRAINT chk_phone_start9 CHECK (SUBSTR(TO_CHAR(PhoneNumber), 1, 1) = '9'); what does contrain means here 
ChatGPT said:

Great question!

🔍 What does CONSTRAINT mean in SQL?

The CONSTRAINT keyword in SQL is used to name a rule that you apply to a column or table. It helps define how data is validated when being inserted or updated.

📌 In your example:
CONSTRAINT chk_phone_start9 CHECK (SUBSTR(TO_CHAR(PhoneNumber), 1, 1) = '9');


Let’s break this down:

CONSTRAINT chk_phone_start9
→ You're naming the constraint.
The name chk_phone_start9 is arbitrary, but useful for:

Error messages

Dropping/modifying the constraint later

CHECK (SUBSTR(TO_CHAR(PhoneNumber), 1, 1) = '9')
→ This is the rule:
It ensures that the first digit of PhoneNumber is 9.

TO_CHAR(PhoneNumber) converts the number to a string

SUBSTR(..., 1, 1) gets the first character

= '9' checks that it's equal to '9'

🛠 Example in context:
ALTER TABLE Students
ADD CONSTRAINT chk_phone_start9
CHECK (SUBSTR(TO_CHAR(ContactNumber), 1, 1) = '9');


This ensures any phone number entered in ContactNumber must start with 9, or Oracle will throw an error.

✅ Why use CONSTRAINT?

Naming constraints gives better control and easier debugging.

You can drop it later using its name:

ALTER TABLE Students DROP CONSTRAINT chk_phone_start9;


Let me know if you’d like help creating a trigger instead (in case Oracle 10g has issues with TO_CHAR in CHECK).

You said:
Practical 5 – Deleting Data
Task:
1.	Delete one enrollment record from Enrollments.
2.	Delete a course (make sure to handle foreign key constraint first).
3.	Delete one student.
ChatGPT said:

Here’s how you can handle Practical 5 – Deleting Data in Oracle 10g with proper respect to foreign key constraints:

✅ Step 1: Delete one enrollment record from Enrollments

Let's say you want to delete the enrollment of student with StudentID = 1001 in course CS101:

DELETE FROM Enrollments
WHERE StudentID = 1001 AND CourseID = 'CS101';

✅ Step 2: Delete a course (handle FK constraints first)

Since Enrollments references Courses via foreign key, you must delete any enrollments for that course before deleting the course.

Assume you want to delete course 'CS101':

Option A: Delete enrollments for course 'CS101' first
DELETE FROM Enrollments
WHERE CourseID = 'CS101';

Then delete the course itself:
DELETE FROM Courses
WHERE CourseID = 'CS101';

✅ Step 3: Delete one student

Again, since Enrollments references Students, delete enrollments for that student first.

For student with StudentID = 1002:

Delete enrollments of the student first:
DELETE FROM Enrollments
WHERE StudentID = 1002;

Then delete the student:
DELETE FROM Students
WHERE StudentID = 1002;

⚠️ Important notes:

If your foreign keys are created without ON DELETE CASCADE, you must manually delete dependent records first as above.

If you want deletions to cascade automatically, the foreign keys must be defined with ON DELETE CASCADE (not shown in your assignment).

If you'd like, I can help you write the commands to add ON DELETE CASCADE constraints to make deletions easier in the future!



