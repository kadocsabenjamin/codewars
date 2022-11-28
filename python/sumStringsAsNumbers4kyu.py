

def sum_strings(x, y):
    if x=="" and y=="":
        return "0"
    if (x == ""):
        return y
    if (y ==""):
        return x

    
    if len(x) > len(y):
        cs = x
        x = y
        y = cs
    
    for gap in range (0, len(y)-len(x)):
        x = '0' + x
    c=0
    r = ''
    for i in range (len(x)-1,-1,-1):
        n = c + int(x[i]) + int(y[i])
        c = int(n/10)
        r = str(n%10) + r
    
    if c != 0:
        r = str(c) + r

    if r[0] == "0":
        r = r[1:]

    return r






print(sum_strings("111","999")) 