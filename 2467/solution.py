num_solution = int(input())
solution_list = list(map(int,input().split(' ')))

left = 0
right = len(solution_list)-1
mid = int((left+right)/2)
while (right > left):
    if (solution_list[mid] < 0):
        left = mid+1
    else:
        right = mid
    mid = int((left+right)/2)

answer = []
if (mid==0):
    answer = [solution_list[mid], solution_list[mid+1]]
elif ((mid==len(solution_list)-1) and (solution_list[mid]<=0)):
    answer = [solution_list[mid-1], solution_list[mid]]
else:
    if (mid==len(solution_list)-1):
        min_ph_sum = abs(solution_list[mid-2] + solution_list[mid-1])
        temp_answer = [solution_list[mid-2], solution_list[mid-1]]
    else:
        if (abs(solution_list[mid-2] + solution_list[mid-1]) < abs(solution_list[mid] + solution_list[mid+1])):
            min_ph_sum = abs(solution_list[mid-2] + solution_list[mid-1])
            temp_answer = [solution_list[mid-2], solution_list[mid-1]]
        else:
            min_ph_sum = abs(solution_list[mid] + solution_list[mid+1])
            temp_answer = [solution_list[mid], solution_list[mid+1]]
    for solution in solution_list[:mid]:
        sub_left = mid
        sub_right = len(solution_list)-1
        sub_mid = int((sub_left+sub_right)/2)
        while (sub_right > sub_left):
            if (solution_list[sub_mid] < abs(solution)):
                sub_left = sub_mid+1
            else:
                sub_right = sub_mid
            sub_mid = int((sub_left+sub_right)/2)
        if (sub_mid==mid):
            if (abs(solution_list[sub_mid]+solution) < min_ph_sum):
                min_ph_sum = abs(solution_list[sub_mid]+solution)
                temp_answer = [solution, solution_list[sub_mid]]
        else:
            if (abs(solution_list[sub_mid]+solution) <= abs(solution_list[sub_mid-1]+solution)):
                if (abs(solution_list[sub_mid]+solution) < min_ph_sum):
                    min_ph_sum = abs(solution_list[sub_mid]+solution)
                    temp_answer = [solution, solution_list[sub_mid]]
            else:
                if (abs(solution_list[sub_mid-1]+solution) < min_ph_sum):
                    min_ph_sum = abs(solution_list[sub_mid-1]+solution)
                    temp_answer = [solution, solution_list[sub_mid-1]]
    answer = temp_answer

print(str(answer[0])+" "+str(answer[1]))