class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        stack=[]
        lens=len(S)
        new_s=''
        for i in range(lens):
            s=S[i]
            lens_1=len(stack)
            if s=='(':
                if lens_1>0:
                    new_s+=s
                stack.append(s)
            else:       
                if lens_1>1:
                    new_s+=s
                stack=stack[:-1]
        return new_s