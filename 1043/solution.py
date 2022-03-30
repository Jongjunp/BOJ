(num_people, num_party) = tuple(map(int,input().split(' ')))
snd_input = tuple(map(int,input().split(' ')))
people_who_know = []
bfs_queue = []
party_graph = dict()
for i in range(1,num_people+1):
    party_graph[i] = []
if not (snd_input[0]==0):
    for p in snd_input[1:]:
        people_who_know.append(p)
        bfs_queue.append(p)
total_party_list = []
for i in range(num_party):
    party_list = list(map(int,input().split(' ')))
    total_party_list.append(party_list[1:])
    for person in party_list[1:]:
        for other in party_list[1:]:
            if (other!=person) and (not (other in party_graph[person])):
                party_graph[person].append(other)

while bfs_queue:
    person_who_know = bfs_queue.pop(0)
    for pe in party_graph[person_who_know]:
        if not pe in people_who_know:
            bfs_queue.append(pe)
            people_who_know.append(pe)

can_not_go = 0
for party in total_party_list:
    for know in people_who_know:
        if know in party:
            can_not_go += 1
            break

answer = num_party-can_not_go
print(answer)