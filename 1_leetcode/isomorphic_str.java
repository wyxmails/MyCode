/*
Isomorphic Strings Total Accepted: 10568 Total Submissions: 43990 My Submissions Question Solution 
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/

public class Solution {
    public boolean isIsomorphic(String s, String t) {
        HashMap mark = new HashMap();
        HashMap mark1 = new HashMap();
        int n = s.length();
        if(t.length()!=n) return false;
        for(int i=0;i<n;++i){
            if(mark.containsKey(s.charAt(i))&&((char)mark.get(s.charAt(i)))!=t.charAt(i)) return false;
            if(mark1.containsKey(t.charAt(i))&&((char)mark1.get(t.charAt(i)))!=s.charAt(i)) return false;
            mark.put(s.charAt(i),t.charAt(i));
            mark1.put(t.charAt(i),s.charAt(i));
        }
        return true;
    }
}
