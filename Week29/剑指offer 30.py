# -*- coding:utf-8 -*-
class Solution:
    st=[]
    min_l=[]
    def push(self, node):
        # write code here
        self.st.append(node)
        if self.min_l:
            if node<self.min_l[-1]:
                self.min_l.append(node)
        else:
            self.min_l.append(node)
    def pop(self):
        # write code here
        if self.top()==self.min_l[-1]:
            self.min_l=self.min_l[:-1]
        self.st=self.st[:-1]
    def top(self):
        # write code here
        return self.st[-1]
    def min(self):
        # write code here
        return self.min_l[-1]