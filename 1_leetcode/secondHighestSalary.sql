/*
Write a SQL query to get the second highest salary from the Employee table.

+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
For example, given the above Employee table, the second highest salary is 200. 
If there is no second highest salary, then the query should return null.
*/

# Write your MySQL query statement below

#solution 1
SELECT a.Salary AS SecondHighestSalary
FROM Employee a
WHERE 1 = (SELECT COUNT(*) FROM Employee b WHERE b.Salary > a.Salary)
UNION  ALL
SELECT NULL
LIMIT 1

#solution 2
select max(a.Salary) from Employee a where a.Salary not in (select max(b.Salary) from Employee b);
