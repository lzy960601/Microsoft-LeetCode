class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        cp=[]
        if target:
            prev=target[0]
            for i in range(1,prev):
                cp.append('Push')
                cp.append('Pop')
            cp.append('Push')
            for i in range(1,len(target)):
                if target[i]-prev==1:
                    cp.append('Push')
                    prev=target[i]
                else:
                    for j in range(target[i]-prev-1):
                        cp.append('Push')
                        cp.append('Pop')
                    prev=target[i]
                    cp.append('Push')
        return cp

