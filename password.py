import secrets
import string 

pw_Length = int(input("Enter the length of password: "))
n = 5

def generate_pw(pw_Length):
    alphabet = string.ascii_letters + string.digits + string.punctuation
    return ''.join(secrets.choice(alphabet) for _ in range(pw_Length))

for _ in range(n):
    print(generate_pw(pw_Length))

