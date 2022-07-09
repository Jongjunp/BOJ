NK = list(map(int,input().split(' ')))
N = NK[0]
order = list(map(int,input().split(' ')))
plugs = []
answer = 0
for i,device in enumerate(order):
    if (device in plugs):
        continue
    if (len(plugs)<N):
        plugs.append(device)
        continue
    plugged = False
    for j,plug in enumerate(plugs):
        if (not plug in order[i+1:]):
            plugs[j] = device
            answer += 1
            plugged = True
            break
    if plugged:
        continue
    else:
        plug_to_pull_order = dict()
        to_pull = 0
        last = 0
        for k,plug in enumerate(plugs):
            for l,ele in enumerate(order[i+1:]):
                if (plug==ele):
                    if k in plug_to_pull_order.keys():
                        continue
                    else:
                        plug_to_pull_order[k] = l
        for key in plug_to_pull_order.keys():
            if last < plug_to_pull_order[key]:
                last = plug_to_pull_order[key]
                to_pull = key
        plugs[to_pull] = device
        answer += 1
print(answer)