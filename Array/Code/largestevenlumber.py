n=input()
digit=["0","1","2","3","4","5","6","7","8","9"]
k=set()
for i in n:
    if i in digit:
        k.add(i)
e=list(k)
e.sort(reverse=True)
if int(e[-1])%2!=0:
    for i in range(len(e)-1,-1,-1):
        if int(e[i])%2==0:
            e.append(e.pop(i))
            break
    
            
print("".join(e))

    
    


        