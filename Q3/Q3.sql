/* Create table*/
CREATE SCHEMA Company;
USE Company;

CREATE TABLE Employee
(
	id VARCHAR(255),
	name VARCHAR(255),
    salary INT,
    departmentId VARCHAR(255)
);

INSERT INTO Employee
VALUES 
(1 , 'Alex' , 10000 , 1) , 
(2 , 'Bob' , 9795 , 1) , 
(3 , 'Jonh' , 9888 , 1) , 
(4 , 'Michael' , 11111 , 1) , 
(5 , 'William' , 10000 , 1) , 
(6 , 'David' , 10500 , 1) , 
(7 , 'Richard' , 11111 , 1) , 
(8 , 'Joseph' , 11111 , 1) , 
(9 , 'Thomas' , 22222 , 2) , 
(10 , 'Charles' , 21212 , 2);

CREATE TABLE Department
(
	id VARCHAR(255),
	name VARCHAR(255)
);

INSERT INTO Department
VALUES 
(1 , 'IT') , 
(2 , 'Marketing') , 
(3 , 'Finance');


SELECT DISTINCT
    department,
    employeeId,
    employeeName,
    salary
FROM (
SELECT 
    d.Name as department,
	e.id as employeeId,
    e.Name as employeeName,
    e.salary as salary,
    DENSE_RANK() OVER (PARTITION BY d.Name ORDER BY e.salary DESC) as rk
FROM employee as e
JOIN department as d
ON e.departmentId = d.id
    ) t1
WHERE rk <= 3;

