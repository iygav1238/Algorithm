# [Diamond V] Building Bridges - 15249 

[문제 링크](https://www.acmicpc.net/problem/15249) 

### 성능 요약

메모리: 79372 KB, 시간: 4500 ms

### 분류

볼록 껍질을 이용한 최적화, 다이나믹 프로그래밍

### 제출 일자

2024년 9월 19일 22:01:41

### 문제 설명

<p>A wide river has n pillars of possibly different heights standing out of the water. They are arranged in a straight line from one bank to the other. We would like to build a bridge that uses the pillars as support. To achieve this we will select a subset of pillars and connect their tops into sections of a bridge. The subset has to include the first and the last pillar.</p>

<p>The cost of building a bridge section between pillars i and j is (h<sub>i</sub> − h<sub>j</sub>)<sup>2</sup> as we want to avoid uneven sections, where h<sub>i</sub> is the height of the pillar i. Additionally, we will also have to remove all the pillars that are not part of the bridge, because they obstruct the river traffic. The cost of removing the i-th pillar is equal to w<sub>i</sub>. This cost can even be negative—some interested parties are willing to pay you to get rid of certain pillars. All the heights h<sub>i</sub> and costs w<sub>i</sub> are integers.</p>

<p>What is the minimum possible cost of building the bridge that connects the first and last pillar?</p>

### 입력 

 <p>The first line contains the number of pillars, n. The second line contains pillar heights h<sub>i</sub> in the order, separated by a space. The third line contains w<sub>i</sub> in the same order, the costs of removing pillars.</p>

### 출력 

 <p>Output the minimum cost for building the bridge. Note that it can be negative.</p>

