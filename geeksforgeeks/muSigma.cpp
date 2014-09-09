/*
 You have 10 machine that produces many balls of different colors and identical weights( except one machine , which produce ball of weight 0.1 gram less than the others, but different color)

 all the other 9 machines produce balls of wt. 1 gm .

 now u have a digital weighin machine that can give u the wt. of any weight that has been kept on it.

 you are allowed just 1 reading on that wt. machine.

 now how will u tell which one is the faulty machine.

 (you can take any number of balls from any machine ) 
 */

solution:

select 1 ball from first machine, 2 from second machine, ... ,10 from tenth machine. weight them on the digital weighin machine, if the weight is 54.9 then the first machine is the one produce less weight ball. if the weight is 55-x*0.1, then the xth machine is the one produce less weight ball.
