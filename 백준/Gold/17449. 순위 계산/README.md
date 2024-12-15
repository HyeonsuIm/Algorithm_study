# [Gold II] 순위 계산 - 17449 

[문제 링크](https://www.acmicpc.net/problem/17449) 

### 성능 요약

메모리: 139424 KB, 시간: 136 ms

### 분류

애드 혹, 그리디 알고리즘, 수학

### 제출 일자

2024년 12월 15일 19:55:15

### 문제 설명

<p>SNUPC(Seoul National University Painting Contest)는 서울대학교 최고의 그림 대회이다. 참가자는 순서대로 한 명씩 심사위원 앞에서 제한된 시간 동안 제시된 단어에 맞는 그림을 그리고, 심사위원이 이를 채점하는 방식으로 대회가 진행된다.</p>

<p>단순히 그림을 잘 그리는지를 평가하는 것이 아니라 그리는 과정에서의 퍼포먼스, 주제어를 창의적으로 해석하는 능력 등 여러 가지 기준으로 채점하기 때문에 결과로 나오는 점수도 매우 복잡하여 그대로 외우기 힘들다. 참가자였던 탐레프는 자신의 정확한 점수를 기억하는 대신 자신이 받은 중간 순위만 기억하기로 했다.</p>

<p>한 명의 평가가 끝나면 지금까지 점수가 매겨진 참가자 중 자신보다 점수가 높은 사람의 수 + 1이 중간 순위가 된다. 즉, 자신보다 점수가 높은 사람이 세 명이라면 4위가 되고, 점수가 더 높은 사람이 없다면 1위가 되는 식이다. 이후 다음 참가자의 점수에 따라 순위가 밀릴 수도 있다.</p>

<p>탐레프는 자신이 받았던 중간 순위와 이후 참가자들이 받았던 순위를 기억하고 있다. 이 정보를 바탕으로 탐레프의 최종 순위가 어떻게 될 수 있는지를 계산하는 프로그램을 작성해보자.</p>

### 입력 

 <p>첫 줄에 정수 <span style="font-style: italic;">R</span>이 입력되며, 이는 탐레프가 평가 직후 받은 중간 순위를 의미한다. (1 ≤ <span style="font-style: italic;">R</span> ≤ 200,000)</p>

<p>다음 줄에 정수 <span style="font-style: italic;">N</span>이 입력되며, 이는 탐레프 이후 참가한 사람의 수를 의미한다. (1 ≤ <span style="font-style: italic;">N</span> ≤ 200,000)</p>

<p>이후 공백으로 구분된 <span style="font-style: italic;">N</span>개의 정수가 입력되며, <span style="font-style: italic;">i</span>번째 정수 <span style="font-style: italic;">R</span><sub><span style="font-style: italic;">i</span></sub>는 <span style="font-style: italic;">i</span>번째 참가자의 해당 시점 순위를 의미한다. (1 ≤ <span style="font-style: italic;">R</span><sub><span style="font-style: italic;">i</span></sub> ≤ 200,000)</p>

### 출력 

 <p>탐레프의 가능한 가장 높은(1등에 가까운) 순위와 가장 낮은 순위를 공백을 사이에 두고 출력한다.</p>

