/* Create table*/
CREATE SCHEMA Performance;
USE Performance;

CREATE TABLE Performance
(
	Athleteld VARCHAR(255),
	Gender ENUM('M' , 'F'),
	Country VARCHAR(255),
	Score NUMERIC(5 , 2)
);

/* Insert values*/
INSERT INTO Performance
VALUES 
(1 , 'M' , 'Vietnam' , 90.25) , 
(2 , 'F' , 'China' , 80.3) , 
(3 , 'F' , 'Laos' , 85.12) , 
(4 , 'M' , 'India' , 87.3) , 
(5 , 'F' , 'Indonesia' , 92.51) , 
(6 , 'F' , 'Japan' , 100.00) , 
(7 , 'M' , 'Thailand' , 97.5) , 
(8 , 'M' , 'Syria' , 90.12) , 
(9 , 'F' , 'Qatar' , 78.52) , 
(10 , 'F' , 'Malaysia' , 83.81);

/*Get the second highest score*/
SELECT MAX(Score) as second_highest_score
FROM Performance
WHERE Score < (SELECT MAX(Score) FROM Performance);
