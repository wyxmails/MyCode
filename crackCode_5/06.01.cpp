/*
 You have 20 bottles of pills. 19 bottles have 1.0 gram pills, 
 but one has pills of weight 1.1 grams. 
 Given a scale that provides an exact measurement, 
 how would you find the heavy bottle? 
 You can only use the scale once
 */
solution: 
	give each bootle a number_tag, from 1 to 20, choose 1 from number_tag=1 bootle, and 2 from number_tag=2 bottle, ... and 20 from number_tag=20 bottle, weight them, the decimal of the weight will be the number_tag of the bottle, for example the weight is 210.1, then the pills in the first bottle are heavy,if the weight is 210.5, then the fifth bottle's pills are heavy.
