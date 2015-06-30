/*
Department Highest Salary Total Accepted: 3469 Total Submissions: 18856 My Submissions Question Solution 
The Employee table holds all employees. Every employee has an Id, a salary, 
and there is also a column for the department Id.

+----+-------+--------+--------------+
| Id | Name  | Salary | DepartmentId |
+----+-------+--------+--------------+
| 1  | Joe   | 70000  | 1            |
| 2  | Henry | 80000  | 2            |
| 3  | Sam   | 60000  | 2            |
| 4  | Max   | 90000  | 1            |
+----+-------+--------+--------------+
The Department table holds all departments of the company.

+----+----------+
| Id | Name     |
+----+----------+
| 1  | IT       |
| 2  | Sales    |
+----+----------+
Write a SQL query to find employees who have the highest salary in each of the departments. For the above tables, 
Max has the highest salary in the IT department and Henry has the highest salary in the Sales department.

+------------+----------+--------+
| Department | Employee | Salary |
+------------+----------+--------+
| IT         | Max      | 90000  |
| Sales      | Henry    | 80000  |
+------------+----------+--------+
*/

# Write your MySQL query statement below
# no join in the following code will lead to time limit exceeded
select d.Name, e.Name, e.Salary from Department d join Employee e on e.DepartmentId=d.Id
where e.Salary in (select max(Salary) from Employee where DepartmentId=e.DepartmentId)
