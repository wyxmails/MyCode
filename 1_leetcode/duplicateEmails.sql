/*
Duplicate Emails Total Accepted: 6455 Total Submissions: 17107 My Submissions Question Solution 
Write a SQL query to find all duplicate emails in a table named Person.

+----+---------+
| Id | Email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+
For example, your query should return the following for the above table:

+---------+
| Email   |
+---------+
| a@b.com |
+---------+
Note: All emails are in lowercase.
*/

# Write your MySQL query statement below
select distinct P.Email from Person P where (select count(*) from Person b where b.Email=P.Email)>1;
