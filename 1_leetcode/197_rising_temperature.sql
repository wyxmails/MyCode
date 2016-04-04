/*
197. Rising Temperature My Submissions QuestionEditorial Solution
Total Accepted: 13292 Total Submissions: 51139 Difficulty: Easy
Given a Weather table, write a SQL query to find all dates' Ids with higher temperature compared to its previous (yesterday's) dates.

+---------+------------+------------------+
| Id(INT) | Date(DATE) | Temperature(INT) |
+---------+------------+------------------+
|       1 | 2015-01-01 |               10 |
|       2 | 2015-01-02 |               25 |
|       3 | 2015-01-03 |               20 |
|       4 | 2015-01-04 |               30 |
+---------+------------+------------------+
For example, return the following Ids for the above Weather table:
+----+
| Id |
+----+
|  2 |
|  4 |
+----+

*/

# Write your MySQL query statement below
select w1.Id 
from Weather w1,Weather w2 
where TO_DAYS(w1.Date)-TO_DAYS(w2.Date) = 1 
  and w1.Temperature > w2.Temperature
