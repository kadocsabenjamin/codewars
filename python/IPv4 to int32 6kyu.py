def decimalToBinary(n):
    return bin(n).replace("0b", "")


def binaryToDecimal(n):
    return int(n, 2)


def ip_to_int32(ip):
    l = ip.split('.')
    IpAsInt32 = ""
    for x in l:
        s = decimalToBinary(int(x))
        for y in range(0, 8-len(s)):
            s = '0' + s
        IpAsInt32 += s
    return binaryToDecimal(IpAsInt32)


print(ip_to_int32("128.114.17.104"))
