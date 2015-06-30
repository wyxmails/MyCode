/*
Department Top Three Salaries Total Accepted: 2172 Total Submissions: 15259 My Submissions Question Solution 
The Employee table holds all employees. Every employee has an Id, and there is also a column for the department Id.

+----+-------+--------+--------------+
| Id | Name  | Salary | DepartmentId |
+----+-------+--------+--------------+
| 1  | Joe   | 70000  | 1            |
| 2  | Henry | 80000  | 2            |
| 3  | Sam   | 60000  | 2            |
| 4  | Max   | 90000  | 1            |
| 5  | Janet | 69000  | 1            |
| 6  | Randy | 85000  | 1            |
+----+-------+--------+--------------+
The Department table holds all departments of the company.

+----+----------+
| Id | Name     |
+----+----------+
| 1  | IT       |
| 2  | Sales    |
+----+----------+
Write a SQL query to find employees who earn the top three salaries in each of the department. 
For the above tables, your SQL query should return the following rows.

+------------+----------+--------+
| Department | Employee | Salary |
+------------+----------+--------+
| IT         | Max      | 90000  |
| IT         | Randy    | 85000  |
| IT         | Joe      | 70000  |
| Sales      | Henry    | 80000  |
| Sales      | Sam      | 60000  |
+------------+----------+--------+
*/

# Write your MySQL query statement below

#The following two methods both work
#select d.Name as Department, e.Name as Employee, e.Salary as Salary from Department d, Employee e
select d.Name, e.Name, e.Salary from Department d, Employee e
where (select count(distinct(Salary)) from Employee where DepartmentId=e.DepartmentId and Salary>e.Salary)<3
and e.DepartmentId=d.Id
order by e.DepartmentId, e.Salary desc

#Another solution to learn
#link: http://bookshadow.com/weblog/2015/01/24/leetcode-department-top-three-salaries/
SELECT d.NAME AS Department, t.NAME AS Employee, Salary FROM (
  SELECT    DepartmentId,
            NAME,
            Salary, 
            @rank := IF(@prevDeptId != DepartmentId, 1, 
                         IF(@prevSalary = Salary, @rank, @rank + 1) ) AS Rank,
            @prevDeptId := DepartmentId AS prevDeptId,
            @prevSalary := Salary AS prevSalary
  FROM      Employee e, (SELECT @rank := 0, @prevDeptId := NULL, @prevSalary := NULL) r
  ORDER BY  DepartmentId ASC, Salary DESC
) t INNER JOIN Department d ON t.DepartmentId = d.ID
WHERE t.rank <= 3
