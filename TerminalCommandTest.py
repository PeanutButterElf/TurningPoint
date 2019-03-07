import os

system_message = ""
print("Hi")
def pushAll(self):
    output = os.system("ping github.com")
    if output == 1:
        print("No connection to github servers. Please connect to a network.")
        return
    os.system("git add -A")
    message = input("Commit Message?  :")
    system_message = 'git commit -m "' + message + '"'

pushAll
os.system(system_message)
print("Hello")