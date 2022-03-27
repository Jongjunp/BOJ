# 16362. Parentheses

# 문제 정의
> 해당 문제는 주어진 ICPC 언어에 맞는 문법과 아닌 문법을 구분하는 문제로 FSM 개념과 stack 자료구조를 활용해서 풀어야 한다.
> 이 때, stack을 이용해 parentheses가 열리고 닫힐 때, 그 사이에 있는 유효한 변수의 개수를 계속 추적하는 것이 문제풀이의 핵심이다.

# 문제 풀이
> FSM을 이용하여 주어진 문자열에서 문자를 한 문자씩 읽어들이면서 조건에 맞게 상태를 변화시키면 된다. 본 문제풀이에서는 IDLE, OPERAND, OPERATOR, PAREN_IN, PAREN_OUT을 상태로 사용하였다.
> 각각의 상태를 읽어들임과 동시에 피연산자를 만날 때마다 이를 스택에 추가한다. 해당 스택에서 피연산자의 개수가 3개 이상이 되면 ICPC에 맞지 않는, improper한 expression이 된다.
> 이 때, open parentheses 역시 스택에 추가한다. close parentheses를 만났을 때는 open parentheses를 만날 때까지 스택에서 값을 제거한다. 이 때, open parentheses를 만나지 못하면 error를 반환하고 open parentheses를 만나면 그 내부의 값들을 하나의 피연산자로 치환하여 스택에 추가한다. 또한 expression에 대한 평가가 끝났을 때, 스택에 open parentheses가 남아있어도 error를 반환한다. proper하기 위해서는 평가가 끝났을 때, 일반적으로는 스택에 피연산자 두 개만이 남아있어야 한다. 전체 피연산자 개수가 한 개인 예외 역시 따로 처리해 주어야 한다.
``` python
    def parse(self, expr):
        status = 1
        for charac in expr:
            status = self._state_transition(charac)
            if status == -1:
                return "error"
            else:
                continue
        if ('(' in self._operand_stack) or (self._current_state==self._OPERATOR):
            return "error"
        elif (self._total_operand_num == 1):
            if self._improper:
                return "improper"
            else:
                return "proper"
        elif (not (self._operand_stack==['.','.'])) or self._improper:
            return "improper"
        else:
            return "proper"
```

# 주의할 점
> parentheses 내에 들어있는 변수의 개수를 조건문을 이용해서 세아리기보다 스택에 parentheses와 변수를 구분해서 넣은 후, 최종 상태를 확인하는 것이 더욱 효울적이고 오류의 가능성을 줄일 수 있다.