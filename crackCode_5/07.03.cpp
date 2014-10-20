/*
 Given two lines on a Cartesian plane, 
 determine whether the two lines would intersect.
 */
struct Line{
	double epsilon=0.000001;
	double slope;
	double yintercept;
	bool intersect(Line line2){
		return fabs(slope-line2.slope)>epsilon
			||fabs(yintercept-line2.yintercept)<epsilon;
	}
};
