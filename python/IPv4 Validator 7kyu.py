import re
def ipValidator(ip):
    if ip=="":
        return False
    if re.search('[a-zA-Z ]+',ip):
        return False
    l = ip.split('.')
    if len(l) != 4:
        return False
    for x in l:
        if int(x) < 0 or int(x) > 255:
            return False
    return True

print(ipValidator("127.2506.0.1"))