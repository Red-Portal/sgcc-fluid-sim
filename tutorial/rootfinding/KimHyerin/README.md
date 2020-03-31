### 참고한 method
 Newton's method

### 변형
 (x_n, f(x_n))의 tangent line의 x축과의 교점을 함수 f의 근으로 추정하는 것을 이용

 birdfunction을 x축 방향으로 미분한 함수와 y축 방향으로 미분한 함수를 이용해서 (x_n, y_n, f(x_n, y_n)) x축 방향 tangent line과 y축 방향 tangentline의 x축, y축 교점을 각각 x_n+1과 y_n+1로 잡고 함수 계산

### 코드 구현
오차 범위가 0.00000000001내로 들어서면 반복을 종료하도록 함
다만, 초기 가정치를 잘 지정하지 못해 수렴하지 못 할 경우를 대비해 반복을 30번으로 제한했다.

