SQL> SELECT * FROM DEPOSITA02;

ACTNO CNAME              BNAME                  AMOUNT ADATE
----- ------------------ ------------------ ---------- ---------
100   ANIL               VRCE                     1000 01-MAR-95
101   SUNIL              AJNI                     5000 04-JAN-96
102   MEHUL              KAROLBAGH                3500 17-NOV-95
104   MADHURI            CHANDI                   1200 17-DEC-95
105   PRMOD              MG ROAD                  3000 27-MAR-96
106   SANDIP             ANDHERI                  2000 31-MAR-96
107   SHIVANI            VIRAR                    1000 05-SEP-95
108   KRANTI             NEHRU PLACE              5000 02-JUL-95
109   MINU               POWAI                    7000 10-AUG-95

9 rows selected.

SQL> SELECT AVG(AMOUNT) FROM DEPOSITA02;

AVG(AMOUNT)
-----------
 3188.88889

SQL> SELECT SUM(AMOUNT) FROM BORROWA02;

SUM(AMOUNT)
-----------
      25000

SQL> SELECT max(AMOUNT) FROM BORROWA02;

MAX(AMOUNT)
-----------
       5000

SQL> SELECT * FROM customera02;

CNAME               CITY
------------------- ------------------
ANIL                CALCUTTA
SUNIL               BARODA
MEHUL               BARODA
MANDAR              PATNA
MADHURI             NAGPUR
PRAMOD              NAGPUR
SANDIP              SURAT
SHIVANI             BOMBAY
KRANTI              BOMBAY
NAREN               BOMBAY

10 rows selected.

SQL> SELECT count(city) FROM customera02;

COUNT(CITY)
-----------
         10

SQL> SELECT SUM(AMOUNT) AS Total_Loan
  2  FROM BORROW
  3  WHERE BNAME = 'KAROLBAGH';
WHERE BNAME = 'KAROLBAGH'
      *
ERROR at line 3:
ORA-00904: "BNAME": invalid identifier


SQL> SELECT SUM(AMOUNT) AS Total_Loan
  2  FROM BORROW
  3  WHERE BNAME = 'KAROLBAGH';
WHERE BNAME = 'KAROLBAGH'
      *
ERROR at line 3:
ORA-00904: "BNAME": invalid identifier


SQL> SELECT SUM(AMOUNT) FROM BORROW WHERE BNAME = 'KAROLBAGH';
SELECT SUM(AMOUNT) FROM BORROW WHERE BNAME = 'KAROLBAGH'
                                     *
ERROR at line 1:
ORA-00904: "BNAME": invalid identifier


SQL> SELECT * FROM BORROWA02;

LOANN CNAME              BNAME                  AMOUNT
----- ------------------ ------------------ ----------
201   ANIL               VRCE                     5000
206   MEHUL              AJNI                     5000
311   SUNIL              DHARAMPETH               5000
321   MADHURI            ANDHERI                  5000
327   PRAMOD             VIRAR                    5000

SQL> SELECT SUM(AMOUNT) FROM BORROW WHERE BNAME = 'KAROLBAGH';
SELECT SUM(AMOUNT) FROM BORROW WHERE BNAME = 'KAROLBAGH'
                                     *
ERROR at line 1:
ORA-00904: "BNAME": invalid identifier


SQL> SELECT MAX(AMOUNT) AS Max_Loan
  2  FROM BORROW
  3  WHERE BNAME = 'VRCE';
WHERE BNAME = 'VRCE'
      *
ERROR at line 3:
ORA-00904: "BNAME": invalid identifier


SQL> SELECT * FROM BORROWA02;

LOANN CNAME              BNAME                  AMOUNT
----- ------------------ ------------------ ----------
201   ANIL               VRCE                     5000
206   MEHUL              AJNI                     5000
311   SUNIL              DHARAMPETH               5000
321   MADHURI            ANDHERI                  5000
327   PRAMOD             VIRAR                    5000

SQL> SELECT SUM(AMOUNT) FROM BORROWA02 WHERE BNAME = 'KAROLBAGH';

SUM(AMOUNT)
-----------


SQL> SELECT SUM(AMOUNT) FROM BORROWA02 WHERE BNAME = 'KAROLBAGH';

SUM(AMOUNT)
-----------


SQL> SELECT MAX(AMOUNT) AS Max_Loan
  2  FROM BORROWA02
  3  WHERE BNAME = 'VRCE';

  MAX_LOAN
----------
      5000

SQL> SELECT COUNT(DISTINCT CITY) AS Total_Customer_Cities
  2  FROM CUSTOMERSA02;
FROM CUSTOMERSA02
     *
ERROR at line 2:
ORA-00942: table or view does not exist


SQL> SELECT COUNT(DISTINCT CITY) AS Total_Customer_Cities FROM CUSTOMERA02;

TOTAL_CUSTOMER_CITIES
---------------------
                    6

SQL> SELECT
  2    ABS(-25) AS Abs1,
  3    ABS(25) AS Abs2,
  4    ABS(-50) AS Abs3,
  5    ABS(50) AS Abs4
  6  FROM DUAL;

      ABS1       ABS2       ABS3       ABS4
---------- ---------- ---------- ----------
        25         25         50         50

SQL> SELECT
  2    MOD(5, 2) AS Remainder_5_2,
  3    MOD(5, 3) AS Remainder_5_3
  4  FROM DUAL;

REMAINDER_5_2 REMAINDER_5_3
------------- -------------
            1             2

SQL> SELECT
  2    POWER(3, 2) AS Power_3_2,
  3    POWER(4, 3) AS Power_4_3
  4  FROM DUAL;

 POWER_3_2  POWER_4_3
---------- ----------
         9         64

SQL> SELECT
  2    SQRT(25) AS Root_25,
  3    SQRT(30) AS Root_30,
  4    SQRT(50) AS Root_50
  5  FROM DUAL;

   ROOT_25    ROOT_30    ROOT_50
---------- ---------- ----------
         5 5.47722558 7.07106781

SQL> SELECT
  2    ROUND(157.732, 2) AS Round_2,
  3    ROUND(157.732, 0) AS Round_0,
  4    ROUND(157.732, -2) AS Round_neg2
  5  FROM DUAL;

   ROUND_2    ROUND_0 ROUND_NEG2
---------- ---------- ----------
    157.73        158        200

SQL> SELECT
  2    CEIL(25.2) AS Ceil_25_2,
  3    CEIL(25.7) AS Ceil_25_7,
  4    CEIL(-25.2) AS Ceil_neg25_2
  5  FROM DUAL;

 CEIL_25_2  CEIL_25_7 CEIL_NEG25_2
---------- ---------- ------------
        26         26          -25

SQL> SELECT
  2    FLOOR(25.2) AS Floor_25_2,
  3    FLOOR(25.7) AS Floor_25_7,
  4    FLOOR(-25.2) AS Floor_neg25_2
  5  FROM DUAL;

FLOOR_25_2 FLOOR_25_7 FLOOR_NEG25_2
---------- ---------- -------------
        25         25           -26

SQL> SELECT
  2    CNAME,
  3    BNAME,
  4    LENGTH(CNAME) AS CNAME_Length,
  5    LENGTH(BNAME) AS BNAME_Length
  6  FROM DEPOSITA02;

CNAME              BNAME              CNAME_LENGTH BNAME_LENGTH
------------------ ------------------ ------------ ------------
ANIL               VRCE                          4            4
SUNIL              AJNI                          5            4
MEHUL              KAROLBAGH                     5            9
MADHURI            CHANDI                        7            6
PRMOD              MG ROAD                       5            7
SANDIP             ANDHERI                       6            7
SHIVANI            VIRAR                         7            5
KRANTI             NEHRU PLACE                   6           11
MINU               POWAI                         4            5

9 rows selected.

SQL> SELECT
  2    LOWER(BNAME) AS BNAME_Lower,
  3    LOWER(CITY) AS CITY_Lower
  4  FROM BRANCHA02;

BNAME_LOWER        CITY_LOWER
------------------ ------------------
vrce               nagpur
ajni               nagpur
karolbagh          delhi
chandi             delhi
dharampeth         nagpur
m.g.road           banglore
andheri            bombay
virar              bombay
nehru place        delhi
powai              bombay

10 rows selected.

SQL> SELECT
  2    INITCAP(CNAME) AS Customer_Name,
  3    INITCAP(CITY) AS City
  4  FROM CUSTOMERSA02;
FROM CUSTOMERSA02
     *
ERROR at line 4:
ORA-00942: table or view does not exist


SQL> SELECT INITCAP(CNAME) AS CUSTOMER-NAME, INITCAP(CITY) AS CITYFROM CUSTOMERA02;
SELECT INITCAP(CNAME) AS CUSTOMER-NAME, INITCAP(CITY) AS CITYFROM CUSTOMERA02
                                 *
ERROR at line 1:
ORA-00923: FROM keyword not found where expected


SQL> SELECT INITCAP(CNAME) AS CUSTOMER_NAME, INITCAP(CITY) AS CITYFROM CUSTOMERA02;
SELECT INITCAP(CNAME) AS CUSTOMER_NAME, INITCAP(CITY) AS CITYFROM CUSTOMERA02
                                                                  *
ERROR at line 1:
ORA-00923: FROM keyword not found where expected


SQL> SELECT INITCAP(CNAME) AS CUSTOMER_NAME, INITCAP(CITY) AS CITY FROM CUSTOMERA02;

CUSTOMER_NAME       CITY
------------------- ------------------
Anil                Calcutta
Sunil               Baroda
Mehul               Baroda
Mandar              Patna
Madhuri             Nagpur
Pramod              Nagpur
Sandip              Surat
Shivani             Bombay
Kranti              Bombay
Naren               Bombay

10 rows selected.

SQL> SELECT TO_NUMBER('1234.56') AS Number_Converted FROM DUAL;

NUMBER_CONVERTED
----------------
         1234.56

SQL> SELECT TO_CHARACTER(123456) AS nO_TO_CHAR FROM DUAL;
SELECT TO_CHARACTER(123456) AS nO_TO_CHAR FROM DUAL
       *
ERROR at line 1:
ORA-00904: "TO_CHARACTER": invalid identifier


SQL> SELECT TO_CHAR(123456) AS nO_TO_CHAR FROM DUAL;

NO_TO_
------
123456

SQL> SELECT EXTRACT(TIME FROM SYSDATE) "dATE" FROM DUAL;
SELECT EXTRACT(TIME FROM SYSDATE) "dATE" FROM DUAL
                    *
ERROR at line 1:
ORA-00907: missing right parenthesis


SQL> SELECT EXTRACT(DATE FROM SYSDATE) "dATE" FROM DUAL;
SELECT EXTRACT(DATE FROM SYSDATE) "dATE" FROM DUAL
               *
ERROR at line 1:
ORA-00936: missing expression


SQL> SELECT EXTRACT (year,month,day,hour,minute, second FROM SYSDATE) "dATE" FROM DUAL;
SELECT EXTRACT (year,month,day,hour,minute, second FROM SYSDATE) "dATE" FROM DUAL
                                                   *
ERROR at line 1:
ORA-00907: missing right parenthesis


SQL> SELECT EXTRACT(YEAR FROM SYSDATE) "dATE" FROM DUAL;

      dATE
----------
      2025

SQL> SELECT EXTRACT(YEAR, MONTH FROM SYSDATE) "dATE" FROM DUAL;
SELECT EXTRACT(YEAR, MONTH FROM SYSDATE) "dATE" FROM DUAL
                           *
ERROR at line 1:
ORA-00907: missing right parenthesis


SQL> SELECT EXTRACT(MONTH FROM SYSDATE) "dATE" FROM DUAL;

      dATE
----------
         9

SQL> SELECT EXTRACT(DAY FROM SYSDATE) "dATE" FROM DUAL;

      dATE
----------
         9

SQL> SELECT EXTRACT(TIME FROM SYSDATE) "dATE" FROM DUAL;
SELECT EXTRACT(TIME FROM SYSDATE) "dATE" FROM DUAL
                    *
ERROR at line 1:
ORA-00907: missing right parenthesis


SQL> SELECT
  2    MONTHS_BETWEEN(
  3      TO_DATE('25-DEC-25','DD-MON-YY'),
  4      TO_DATE('14-JUL-25','DD-MON-YY')
  5    ) AS Months_Diff
  6  FROM DUAL;

MONTHS_DIFF
-----------
 5.35483871
