account={'Zhangsan':'123456'}

def sign_up():
    user_name = input("Please input your name: ")
    while user_name in account.keys():
        user_name = input("User name exists,please choose another one: ")
    password = input("Please input your password: ")
    account[user_name] = password
    print("Successfully sign up!")
def sign_in():
    user_name = input("Please input your name: ")
    if user_name not in account.keys():
        print("User name not found.")
    else:
        count=0
        password = input("Please input your password: ")
        while account[user_name]!=password:
            count+=1
            if count>=3:
                print("Bye -- bye")
                break
            password = input("Wrong password, please input again: ")
        if account[user_name]==password:
            print("Login success!")
if __name__ == "__main__":
    while True:
        cmd=input("Sign up or Sign In? Please input 0 or 1:")
        while cmd != '0' and cmd != '1':
            print('Wrong command.please input again: ')
            cmd=input("Sign up: 0, Sign up: 1")
        if cmd == '0':
            sign_up()
            continue
        if cmd == '1':
            sign_in()
            break