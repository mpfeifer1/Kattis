import fileinput

def process(data):
    # Find duplicate people
    projects = []
    for line in data:
        if line.isupper():
            projects.append([line])
        else:
            projects[-1].append(line)

    actualprojects = []

    # Ignore duplicate people
    for project in projects:
        users = set()
        for person in project[1:]:
            users.add(person)

        actualprojects.append([project[0]])
        actualprojects[-1].extend(users)

    projects = actualprojects

    # Find users to skip
    users = set()
    skipusers = set()
    for project in projects:
        for user in project[1:]:
            if user in users:
                skipusers.add(user)
            users.add(user)

    # Remove users to skip
    actualprojects = []
    for project in projects:
        actualprojects.append([project[0]])
        for user in project[1:]:
            if user not in skipusers:
                actualprojects[-1].append(user)

    # Switch to list of service, users
    projects = actualprojects
    projects = [[len(i)-1, i[0]] for i in projects]

    # Sort all the projects
    projects.sort(key=lambda k: (-k[0], k[1]))

    # Print each value
    for i in projects:
        print(i[1], i[0])

    return

def main():
    data = []
    for line in fileinput.input():
        line = line[:-1]
        if line == "0":
            return

        if line == "1":
            # Process the case, then clear stuff
            process(data)
            data = []

        else:
            data.append(line)


if __name__ == "__main__":
    main()
