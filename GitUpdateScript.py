import os


system_message = ""
print("Welcome to the git updater for your robot code!")
while True:
    # def pushAll(self):
    output = os.system("ping -n 2 github.com")
    if output == 1:
        print("No connection to github servers. Please connect to a network.")
    else:
        os.system("git pull")
        print("Pull process complete.\n")
        os.system("git add -A")
        message = input("Commit Message? (enter to escape) :\n")
        if message != "":
            system_message = 'git commit -m "' + message + '"'
            os.system(system_message)
            os.system("git push")
            print("Push process complete.\n")
    rerun = input('Run again? (enter or "no")\n')
    if rerun == "no":
        break
    else:
        os.system("cls")
