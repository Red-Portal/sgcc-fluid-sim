# Rootfinding Exercise

예전에 잠깐 해봤던 Gradient Descent에서 조금 아이디어를 훔쳐왔다.

2D 평면 위에 정의되는 함수이기에 내가 아는 Bisection Method를 어떻게 써야 할 지 모르겠어서 고민하다가 Gradient Descent가 미끄럼틀 타듯 내려온다는 점에서 그냥 가져다가 썼다.

그라디언트를 구하는 루틴이 필요한 만큼 원래는 해석적 편미분을 구해서 코드에다가 집어넣는 게 제일 정확할 것 같았지만 나는 쏘가리 책을 감명 깊게 읽었고 ~~또 귀찮았기 때문에~~ 그냥 대충 작은 수 적어서 수치적으로 구해 보았다.

```c
void search(Function target, double init_x, double init_y)
{
    double x = init_x, y = init_y;
    
    int trials = 0;
    while (trials < MAX_ITERATION) {
        double value = target(x, y);
        
        // If the value is within tolerance, abort
        if (TOLERANCE < value && value < TOLERANCE)
            break;
        
        // Okay let's construct new values
        //   slope = run / rise
        // Therefore slope * function_value seems reasonable?
        // But we need to go back so we subtract
        x -= value / partial_x(target, x, y);
        y -= value / partial_y(target, x, y);
        
        trials++;
    }
}
```

위 코드가 탐색 함수에서 쓸데없는 출력 루틴을 뺀 코드인데 이제 다시 보니 그냥 Global Minima 찾는 알고리즘이 아닌가 싶기도 하다. ~~뭐가 다른지 잘 모르겠다.~~ `TOLERANCE`는 대충 적당한 값으로 잡아 주었고, 원래 `MAX_ITERATION`은 1,000,000으로 잡았는데 끝날 기미가 보이지 않길래 그냥 10,000으로 줄였다.

아무래도 그라디언트를 이용하다 보니 한 0.05 언저리에서의 스텝이 너무 작아져서 접근하는 속도가 너무 줄어들었다. 자꾸 지그재그로만 진행하고 실제로 해에 가까워지는 속도는 매우 느리다.

그리고 원래는 정의역 내에 클램핑을 해 보려고 했지만 클램핑을 하는 순간 숫자가 날아가버리는 문제가 있다. 편미분 값의 문제인 것 같은 의심은 들지만 따로 해결 방법을 찾아봐야 할 것 같다.

초기값에 따라 실제로 찾게 되는 해의 위치가 매-우 다르다. 그래도 한 번 해의 위치를 잡으면 대략 0.05의 오차를 보이며 수렴한다. (그러다 사이클 다 쓰고 포기한다.)

동봉된 [output.txt](output.txt)는 초깃값을 `(1, 1)`으로 주었을 때 계산된 결과이다.
