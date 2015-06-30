/*
Nth Highest Salary Total Accepted: 3253 Total Submissions: 21123 My Submissions Question Solution 
Write a SQL query to get the nth highest salary from the Employee table.

+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
For example, given the above Employee table, the nth highest salary where n = 2 is 200. 
If there is no nth highest salary, then the query should return null.
*/

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  declare M INT;
  set M = N-1;
  RETURN (
      # Write your MySQL query statement below.
      #solution 1
      select e.Salary from Employee e where M=(select count(distinct(Salary)) from Employee where Salary>e.Salary) union all select NULL limit 1
      #solution 2
      #select distinct Salary from Employee order by Salary desc limit M,1
  );
END
