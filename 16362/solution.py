input_str = input().strip().replace(" ","")
expression = list(input_str)
operator=('+','-','*','/','%')
operand=('a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z')
open_parentheses = ('(')
close_parentheses = (')')

class IcpcParser:
    def __init__(self):
        self._INIT = "INIT"
        self._IN_PAREN = "IN_PAREN"
        self._OUT_PAREN = "OUT_PAREN"
        self._OPERAND = "OPERAND"
        self._OPERATOR = "OPERATOR"

        self._current_state = self._INIT
        self._stack = 0
        self._operand_num = 0
        self._total_operand_num = 0
        self._improper = False

    def _state_transition(self, charac):
        if self._current_state == self._INIT:
            if charac in open_parentheses:
                self._stack += 1
                self._operand_num = 0
                self._current_state = self._IN_PAREN
                return 1
            elif charac in operand:
                self._total_operand_num += 1
                self._operand_num += 1
                if self._operand_num > 2:
                    self._improper = True
                self._current_state = self._OPERAND
                return 1
            else:
                return -1
        elif self._current_state == self._IN_PAREN:
            if charac in open_parentheses:
                self._stack += 1
                self._operand_num = 0
                return 1
            elif charac in operand:
                self._total_operand_num += 1
                self._operand_num += 1
                if self._operand_num > 2:
                    self._improper = True
                self._current_state = self._OPERAND
                return 1
            else:
                return -1
        elif self._current_state == self._OPERAND:
            if charac in close_parentheses:
                self._stack -= 1
                self._current_state = self._OUT_PAREN
                return 1
            elif charac in operator:
                self._current_state = self._OPERATOR
                return 1
            else:
                return -1
        elif self._current_state == self._OPERATOR:
            if charac in operand:
                self._total_operand_num += 1
                self._operand_num += 1
                if self._operand_num > 2:
                    self._improper = True
                self._current_state = self._OPERAND
                return 1
            elif charac in open_parentheses:
                self._stack += 1
                self._current_state = self._IN_PAREN
                return 1
            else:
                return -1
        elif self._current_state == self._OUT_PAREN:
            if charac in operator:
                self._current_state = self._OPERATOR
                return 1
            elif charac in close_parentheses:
                self._stack -= 1
                return 1
            else:
                return -1
        else:
            return -1
    
    def parse(self, expr):
        status = 1
        for charac in expr:
            status = self._state_transition(charac)
            if status == -1:
                return "error"
            else:
                continue
        if (not (self._stack == 0)) or (self._current_state==self._OPERATOR):
            return "error"
        elif (self._total_operand_num == 1):
            if self._operand_num == 1:
                return "proper"
            else:
                return "improper"
        elif (not (self._operand_num == 2)) or self._improper:
            return "improper"
        else:
            return "proper"

icpc_parser = IcpcParser()
result = icpc_parser.parse(expression)
print(result)