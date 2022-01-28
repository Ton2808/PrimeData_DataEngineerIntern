/* Create table*/
CREATE SCHEMA Store;
USE Store;

CREATE TABLE Customers
(
	id VARCHAR(255),
	name VARCHAR(255)
);

INSERT INTO Customers
VALUES 
(1 , 'Alex') , 
(2 , 'Bob') , 
(3 , 'Jonh') , 
(4 , 'Michael') , 
(5 , 'William') , 
(6 , 'David') , 
(7 , 'Richard') , 
(8 , 'Joseph') , 
(9 , 'Thomas') , 
(10 , 'Charles');

CREATE TABLE Orders
(
	id VARCHAR(255),
	customerId VARCHAR(255)
);

INSERT INTO Orders
VALUES 
(1001 , '2') , 
(1002 , '3') , 
(1003 , '7') , 
(1004 , '2') , 
(1005 , '5') , 
(1006 , '9') , 
(1007 , '2') , 
(1008 , '9') , 
(1009 , '8') , 
(1010 , '1');

/*Report all customers who never order anything.*/
SELECT * 
FROM Customers C
WHERE C.id not in (SELECT O.customerId FROM Orders O);

SELECT * FROM Customers;
