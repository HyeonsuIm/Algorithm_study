# [Diamond V] PIN - 3317 

[문제 링크](https://www.acmicpc.net/problem/3317) 

### 성능 요약

메모리: 59516 KB, 시간: 2624 ms

### 분류

백트래킹(backtracking), 문자열(string)

### 문제 설명

<p>Martin has just been hired as a computer administrator in a big company. The company did not change its authorization system since 1980s. Every person has a four-digit personal identification number (PIN). Nobody uses usernames or passwords, you can login just by typing your PIN. As the company grew, they added the possibility to use letters as well, but the length of the PIN remained the same.</p>

<p>Martin is not happy with the situation. Suppose there are people whose PINs differ only at a single place, for example <code>61ab</code> and <code>62ab</code>. If the first person accidentally presses 2 instead of 1, the system would still let him in. Martin would like to make the statistics about the PINs currently in use, in particular, compute the number of pairs of PINs that differ at 1, 2, 3 or 4 positions. He hopes that these numbers will be alarming enough to convince his boss to invest in a better system.</p>

<p>Given the list of PINs and an integer D, find the number of pairs of PINs that differ at exactly D positions.</p>

### 입력 

 <p>The first line of the input contains two space-separated positive integers N and D, where N is the number of PINs and D is the chosen number of differences. Each of the following N lines contains a single PIN.</p>

### 출력 

 <p>Output a single line with a single number: the number of pairs of PINs that differ at exactly D positions.</p>

