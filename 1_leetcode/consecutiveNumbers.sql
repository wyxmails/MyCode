/*
Consecutive Numbers Total Accepted: 2840 Total Submissions: 12031 My Submissions Question Solution 
Write a SQL query to find all numbers that appear at least three times consecutively.

+----+-----+
| Id | Num |
+----+-----+
| 1  |  1  |
| 2  |  1  |
| 3  |  1  |
| 4  |  2  |
| 5  |  1  |
| 6  |  2  |
| 7  |  2  |
+----+-----+
For example, given the above Logs table, 1 is the only number that appears consecutively for at least three times.
*/

# Write your MySQL query statement below

#solution 1
select distinct a.Num
from Logs a, Logs b, Logs c
where b.Id=a.Id+1 and a.Num=b.Num and c.Id=a.Id+2 and a.Num=c.Num

#solution 2
select distinct Num from 
(
    select Num, count(rank) as cnt from 
    (
        select Num, @curRank := @curRank + if(@preNum=Num, 0, 1) as rank, @preNum := Num
        from Logs s, (select @curRank := 0) r, (select @preNum := NULL) p
        order by Id asc
    ) t group by Rank having cnt>=3
) n;
