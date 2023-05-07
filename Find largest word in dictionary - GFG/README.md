# Find largest word in dictionary
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.</span><br>
<br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>: d = {"ale", "apple", "monkey", "plea"}
&nbsp;      S = "abpcplea"
<strong>Output:</strong>&nbsp;"apple"&nbsp;
<strong>Explanation</strong>: After deleting "b", "c"
"a" S became "apple" which is present
in d.</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>d = {"a", "b", "c"}
&nbsp;      S = "abpcplea"
<strong>Output:&nbsp;</strong>"a"
<strong>Explanation</strong>: After deleting "b", "p"
"c", "p", "l", "e", "a" S became 
"a" which is present in d.</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You dont need to read input or print anything. Complete the function <strong>findLongestWord()&nbsp;</strong>which takes S and d&nbsp;as input parameter and returns the longest word</span><span style="font-size:18px">.<br>
<br>
<strong>Expected Time Complexity:</strong> O(n*x)<br>
<strong>Expected Auxiliary Space:</strong> O(x)<br>
<br>
<strong>Constraints:</strong><br>
1 ≤ n,x&nbsp;≤ 10<sup>3</sup></span></p>
</div>