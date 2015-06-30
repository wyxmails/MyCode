/*
Rank Scores Total Accepted: 3286 Total Submissions: 14580 My Submissions Question Solution 
Write a SQL query to rank scores. If there is a tie between two scores, both should have the same ranking. 
Note that after a tie, the next ranking number should be the next consecutive integer value. 
In other words, there should be no "holes" between ranks.

+----+-------+
| Id | Score |
+----+-------+
| 1  | 3.50  |
| 2  | 3.65  |
| 3  | 4.00  |
| 4  | 3.85  |
| 5  | 4.00  |
| 6  | 3.65  |
+----+-------+
For example, given the above Scores table, your query should generate the following report (order by highest score):

+-------+------+
| Score | Rank |
+-------+------+
| 4.00  | 1    |
| 4.00  | 1    |
| 3.85  | 2    |
| 3.65  | 3    |
| 3.65  | 3    |
| 3.50  | 4    |
+-------+------+
*/

# Write your MySQL query statement below
# @ starts with at signal means a local variable
# # starts with sharp signal means a temporary table or process
# := means assignment
select s.Score, r.Rank from Scores s 
inner join ( select @curRank := @curRank + 1 as Rank, Score
    from ( select Score from (select @curRank := 0 ) t, Scores group by Score order by Score desc
    ) r
) r 
on s.Score=r.Score
order by Score desc
