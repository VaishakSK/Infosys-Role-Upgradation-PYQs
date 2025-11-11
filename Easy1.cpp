/* Stream First Non-repeating
Difficulty: MediumAccuracy: 31.65%Submissions: 225K+Points: 4Average Time: 15m
Given a string s consisting of only lowercase alphabets, for each index i in the string (0 ≤ i < n), find the first non-repeating character in the prefix s[0..i]. If no such character exists, use '#'.

Examples:

Input: s = "aabc"
Output: a#bb
Explanation: 
At i=0 ("a"): First non-repeating character is 'a'.
At i=1 ("aa"): No non-repeating character, so '#'.
At i=2 ("aab"): First non-repeating character is 'b'.
At i=3 ("aabc"): Non-repeating characters are 'b' and 'c'; 'b' appeared first, so 'b'. 
Input: s = "bb" 
Output: "b#" 
Explanation: 
At i=0 ("b"): First non-repeating character is 'b'.
At i=1 ("bb"): No non-repeating character, so '#'.
Constraints:
1 ≤ s.size() ≤ 105
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string firstNonRepeating(string &s) {
        map<char, int> freq;        // to store frequency of each character
        queue<char> q;              // to maintain order of characters
        string result = "";

        for (char c : s) {
            freq[c]++;              // increment frequency
            q.push(c);              // add to queue

            // remove all repeating characters from the front of the queue
            while (!q.empty() && freq[q.front()] > 1) {
                q.pop();
            }

            // if queue empty, no non-repeating char
            if (q.empty())
                result += '#';
            else
                result += q.front();
        }

        return result;
    }
};
