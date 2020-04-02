특정 함수의 근을 찾는 방법으로 Newton method를 사용했습니다.
이번에 찾는 함수의 형태가 2개의 변수를 가지는 Scalar function이므로, 인터넷에 나와있는 N-D Newton method를 사용하지는 않았습니다.

이 코드는 크게 Main 부분과 Newton function 부분으로 나뉘어 있는데, Main은 initial point에 대한 입력을 받는 부분과, Newton function을 이용해점차 해를 찾아가는 루프로 구성되어 있습니다.
Newton function은 현재의 위치와 현재의 함수값을 인풋으로 받습니다. 그리고 이 정보를 사용해 Gradient를 계산합니다.
Gradient를 알고 있으므로 현재 포인트에서 접선을 그릴 수 있고, 접선과 f=0 평면, 현재 포인트에서의 함수값을 가지고 삼각형을 그립니다.
이 삼각형에서 밑면의 길이 L을 함수값/gradient크기 를 통해 계산하고, Gradient의 방향 벡터를 사용해 f=0로 예상되는 그 다음 x, y 포인트와 현재 포인트의 차이값을 구합니다.
이것을 이용해 estRoot를 변화시킵니다.
