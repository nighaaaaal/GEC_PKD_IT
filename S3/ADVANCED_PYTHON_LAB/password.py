import re
a=input("Enter the password:")
if (re.search(r"\d",a) and re.search(r"\w",a) and re.search(r"[a-z]",a) and re.search(r"[A-Z]",a) and re.search(r"[~,!,@,#,$,%,^,&,*,(,),-,_,+,=]",a) and len(a)>=8):
    print("Valid Password")
else:
    print("Invalid Password")