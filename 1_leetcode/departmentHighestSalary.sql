
# Write your MySQL query statement below
# no join in the following code will lead to time limit exceeded
select d.Name, e.Name, e.Salary from Department d join Employee e on e.DepartmentId=d.Id
where e.Salary in (select max(Salary) from Employee where DepartmentId=e.DepartmentId)
