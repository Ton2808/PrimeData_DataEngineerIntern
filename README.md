The detail of all the file related to the question are in the folder of that question, below is the detail explanation for each question.
---

---
### Q1
In this question we want to find the second highest score of athletes, firstly I try to use the ``` MAX``` statement but it only return the maximum score, so I think of the approve using the ``` WHERE``` statement to put in the condition that take the  highest score that is smaller than the maximum score.
```
SELECT MAX(Score) as second_highest_score
FROM Performance
WHERE Score < (SELECT MAX(Score) FROM Performance);
```
---
### Q2
In this question we want to report all customers who never order anything, we know that the **orders** table store the list of the customerId that have make at least one order. So the idea is to take every customerId in **customers** table that not appear in the **orders** table using ``` WHERE NOT IN ```.
```
SELECT *
FROM Customers C
WHERE C.id not in (SELECT O.customerId FROM Orders O);
```
---
### Q3
In this question we want to find the employees who are high earners in each of the departments.

First let consider a sub problem, how to find the global top three unique salaries, to solve this we use a function name ```DENSE_RANK()```. This function will return the rank of each row with no gap between them.

Next we want to find the top three unique salaries but for each department, if we use the ```GROUP``` statement for department, SQL will understand that the result also return as one group for each department but that not what we want. We want SQL to understand that it need to do the math for each department but the return result will not be group and SQL provide ```PARTITION``` statement to do that.

```
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
WHERE rk <= 3
```
---
### Q4
We have the lemma

```0 + 1 + 2 + ... + n = n * (n + 1) / 2```


We also know that there is only one missing element from 0 to n, so if we take ```n * (n + 1) / 2``` and subtract it with the sum of all the appeared  elements we will get the missing value.

```
long long sum = 0;
for(int i = 1 ; i <= n ; i++)
{
    long long val;
    cin >> val;
    sum += val;
}
cout << "The missing number is: " << n * (n + 1) / 2 - sum << endl;

```
---
### Q5
To find the median of two sorted, the easy way is to create a merged sorted array from the two sorted array. We can do that by using the **two pointer** technique.
```
int cnt = 0;
for(int i = 1 , j = 1 ; i <= m || j <= n ; i++){
    while(j <= n && (i > m || arrF[i] > arrS[j])){ // if the next element of the second array is smaller than the first array
        arrM[++cnt] = arrS[j]; // take j as the next element in the sorted array
        j++;
    }
    arrM[++cnt] = arrF[i]; // take i as the next element in the sorted array
}
```

After having a merge sorted array, the only thing left is to take care of the case the ```sz``` of the array is odd or even .
```
int sz = n + m;
if(sz % 2 == 0)
    cout << (double)(arrM[sz / 2] + arrM[sz / 2 + 1]) / 2;
else
    cout << arrM[sz / 2 + 1];
```
---
### Q6
This problem is difficult to implement, but the idea is straight forward, we just need to loop from the start to the end of the linked list and check if the current value is equal to the next value, if yes we will delete the next value and link the current value to the next of the next value, else just loop to the next value. The trick here is to set the default value of the next node is ```NULL``` it will help us avoid many errors.
```
struct Node{
    int val;
    Node *next = NULL; // every next node will auto assign NULL value
};
```
```
void delDup(Node *&head)
{
    if(head == NULL)
        return;
    Node *p = head;
    if(p -> next == NULL) // if there is only 1 element
        return;

    while(p -> next != NULL) // while the next element is not NULL
    {
        if(p -> val == p -> next -> val) // check if the current value equal to the next value
        {
            Node *temp = p -> next; // temp equal to the next value
            p -> next = temp -> next; // assign the next of the next value to the current value, if it not exist p -> next will equal to NULL
            delete temp;
        }
        else // if delete the next value, no need to p to go to the next value
            p = p -> next;
    }
}
```
---
### Q7
First we need to design a score to measure how sensitive is a website, let call that ```sc```, the ```sc``` score is depending on many different scenario like if the company care about the product may be out of date, we can set something like ```sc = how many day the product expired```. Let assume that we already calculate ```sc``` now let create a solution to maintain this list of websites.

---
#### Solution 1
We will maintain an 1D sorted array ```arr``` of size ```1000``` in decreasing order of the ```sc``` score,  when there is a new website we will calculate the ```sc``` and loop throw the ```arr``` to find the position ```pos``` of the first website that is less sensitive then the current website, than insert the current website to the ```pos``` position to extend the list of website. If it get over ```1000``` website than delete the last website of the array ```arr``` or if ```pos``` is not exist than we ignore the new website.
##### Pro
Easy to implement.
##### Con
The overall complexity is ```O(N)``` which is acceptable because ```N = 1000```, but is not fast enough to handle bigger ```N```.

---
#### Solution 2
Instead of maintain a 1D sorted array, we will maintain a min-heap. When there is a new website, if the min-heap size is less than ```1000``` than we will insert the new website, else we will compare the ```sc``` score of the new website with the top element of the min-heap, if the ```sc``` score of the new website is greater, we will pop the top element than insert the new website, else we just ignore the new website.

##### Pro
The overall complexity is ```O(log(N))```, harder to implement by hand but almost every language has a library that support pre-built heap. For example the ```STL``` library in ```C++```.
##### Con
We can only access the min element, to access random element ```i``` we need to pop all element of the current heap and maintain all the pop element in another heap. The complexity of random access is ```O(Nlog(N))```

---
### Q8

---
### Q9

---
### Q10
