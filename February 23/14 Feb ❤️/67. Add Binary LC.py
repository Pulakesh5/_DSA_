class Solution:
    def addBinary(self, a: str, b: str) -> str:
        sum=""
        bitsum=0
        carry=0
        length_a=len(a)-1
        length_b=len(b)-1

        while( length_a >=0 and length_b>=0):
            bitsum = (int(a[length_a]) + int(b[length_b])-int('0')*2 +carry)
            sum+=str(int(bitsum%2))
            carry=bitsum/2
            length_a-=1
            length_b-=1
        print("first loop:"+sum)
        while(length_a>=0):
            bitsum = (int(a[length_a])-int('0') +carry)
            sum+=str(int(bitsum%2))
            carry=bitsum/2
            length_a-=1
        print("Second loop:"+sum)
        while(length_b>=0):
            bitsum = (int(b[length_b])-int('0') +carry)
            sum+=str(int(bitsum%2))
            carry=bitsum/2
            length_b-=1
        print("third loop:"+sum)
        if int(carry)>0:
            sum+=str(int(carry))
        print("forth loop:"+sum)
        return sum[::-1]
        

        
