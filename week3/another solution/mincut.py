import copy
import random

def contraCut(mapD,edgeList):
    while len(mapD)>2:
        [u,v]=edgeList.pop(random.randrange(0,len(edgeList)-1))
        while([v,u] in edgeList):
            edgeList.remove([v,u])
        while([u,v] in edgeList):
            edgeList.remove([u,v])
        for ind in range(0,len(edgeList)):
            if edgeList[ind][0]==v:edgeList[ind][0]=u
            if edgeList[ind][1]==v:edgeList[ind][1]=u
        mapD[u]=mapD[u]-{v}
        mapD[v]=mapD[v]-{u}
        for [x,y] in mapD.items():
            if v in y:
                mapD[x]=(mapD[x]|{u})-{v}
        mapD[u]=mapD[u]|mapD[v]
        del mapD[v]

    return len(edgeList)/2

if __name__ == '__main__':
    f=open('kargerMinCut.txt','r')
    mapDict={}
    for line in f.readlines():
        tmp=[int(x) for x in line.split()]
        mapDict[tmp[0]]=set(tmp[1:])
    f.close()
    
    edgeList=[]
    for [x,y] in mapDict.items():
        edgeList.extend([[x,v] for v in y])
    
    numList=[]
    for i in range(50):
        cpmapDict=copy.deepcopy(mapDict)
        cpedgeList=copy.deepcopy(edgeList)
        
        #print cpmapDict
        num=contraCut(cpmapDict,cpedgeList)
        numList.append(num)
        numList.sort()
        print (num),
        i+=1
    print (numList)