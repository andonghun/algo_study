def solution(record):
    answer = []
    info = {}
    logs = []
    
    for rec in record:
        commands = rec.split(' ')
        if commands[0] == "Enter":
            info[commands[1]] = commands[2]
            logs.append(["%s님이 들어왔습니다.", commands[1]])
        elif commands[0] == "Leave":
            logs.append(["%s님이 나갔습니다.", commands[1]])
        elif commands[0] == "Change":
            info[commands[1]] = commands[2]
            
    for log in logs:
        answer.append(log[0]%info[log[1]])
        #print(log[0]%log[1])
    
    return answer
