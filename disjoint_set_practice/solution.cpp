#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 7;
int parent[MAX] = {0};
int size[MAX] = {0};
string members[] = {"유재석", "김종국", "송지효", "하하", "지석진", "양세찬", "전소민"};
int max_size = 0;
int max_person = 0;

int find_op(int x) {
    if (x==parent[x]) return x;
    parent[x] = find_op(parent[x]);
    return parent[x];
}

void union_op(int head, int tail) {
    int parent_head = find_op(head);
    int parent_tail = find_op(tail);
    if (parent_head==parent_tail) return;
    parent[parent_tail] = parent_head;
    size[parent_head] += size[parent_tail];
    size[parent_tail] = 0;
    if (max_size<size[parent_head]) {
        max_size = size[parent_head];
        max_person = parent_head;
    }
}

int main() {
    printf("런닝맨: 꼬리에 꼬리를 무는 런닝맨 게임\n");
    printf("1. 유재석\n");
    printf("2. 김종국\n");
    printf("3. 송지효\n");
    printf("4. 하하\n");
    printf("5. 지석진\n");
    printf("6. 양세찬\n");
    printf("7. 전소민\n");
    printf("게임 중 위의 멤버 ID를 이용하세요!\n");
    for (int i=0; i<MAX; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    int head_id, tail_id;
    while (true) {
        if (max_size==MAX) {
            printf("게임이 종료되었습니다!\n");
            printf("승자: %s\n", members[max_person].c_str());
            break;
        }
        printf("이름표를 발견한 멤버 이름: ");
        scanf("%d", &head_id);
        printf("이름표를 발견당한 멤버 이름: ");
        scanf("%d", &tail_id);
        union_op(head_id-1, tail_id-1);
        printf("%s가(이) %s의 꼬리가 되었습니다!\n", members[tail_id-1].c_str(), members[find_op(head_id-1)].c_str());
    }
}