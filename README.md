@@ -1,8 +1,25 @@
<<<<<<< HEAD
The detail of all the file related to the question are in the folder of that question, below is the detail explanation for each question.
---
---
### Q1
In this question we want to find the second highest score of athletes, firstly I try to use the ``` MAX``` statement but it only return the maximum score, so I think of the approve using the ``` WHERE``` statement to put in the condition that take the  highest score that is smaller than the maximum score.
=======
## Table of content
### [Q1](#Q1)
### [Q2](#Q2)
### [Q3](#Q3)
### [Q4](#Q4)
### [Q5](#Q5)
### [Q6](#Q6)
### [Q7](#Q7)
### [Q8](#Q8)
### [Q9](#Q9)
### [Q10](#Q10)
---
### Q1
In this question we want to find the second highest score of athletes, firstly I try to use the ``` MAX``` statement but it only return the maximum score, so I think of the approve using the ``` WHERE``` statement to put in the condition that take the  highest score that is smaller than the maximum score. 
>>>>>>> d5dbc5b21024124b19f41242b5be9918ce966fe9
```
SELECT MAX(Score) as second_highest_score
FROM Performance
@ -12,6 +29,7 @@ WHERE Score < (SELECT MAX(Score) FROM Performance);
### Q2
In this question we want to report all customers who never order anything, we know that the **orders** table store the list of the customerId that have make at least one order. So the idea is to take every customerId in **customers** table that not appear in the **orders** table using ``` WHERE NOT IN ```.
```
<<<<<<< HEAD
SELECT *
FROM Customers C
WHERE C.id not in (SELECT O.customerId FROM Orders O);
@ -140,3 +158,13 @@ We can only access the min element, to access random element ```i``` we need to
### Q8

---
=======
SELECT * 
FROM Customers C
WHERE C.id not in (SELECT O.customerId FROM Orders O);
```
### Q3
In this question we want to find the employees who are high earners in each of the departments,
 
  
>>>>>>> d5dbc5b21024124b19f41242b5be9918ce966fe9
