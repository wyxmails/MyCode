/*
Rectangle Area My Submissions Question Solution 
Total Accepted: 20076 Total Submissions: 74965 Difficulty: Easy
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.
*/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long len = max(0,min(C,G)-max(A,E));
        long long height = max(0,min(D,H)-max(B,F));
        long long res = (long long)(C-A)*(long long)(D-B)+(long long)(G-E)*(long long)(H-F);
        if(A>=G||B>=H||C<=E||D<=F) return res;
        res -= len*height;
        return res;
    }
};
