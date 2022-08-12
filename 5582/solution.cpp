#include <iostream>
using namespace std;
const int MAX = 4001;
int lcs_mat[MAX][MAX] = {0};

int main() {
    char string1[MAX];
    char string2[MAX];
    int maxlen = 0;
    scanf("%s",string1);
    scanf("%s",string2);
    for (int i=0; string1[i]!='\0'; i++) {
        for (int j=0; string2[j]!='\0'; j++) {
            if (string1[i]==string2[j]) {
                lcs_mat[i+1][j+1] = lcs_mat[i][j]+1;
                if (maxlen<lcs_mat[i+1][j+1]) {
                    maxlen = lcs_mat[i+1][j+1];
                }
            }
        }
    }
    printf("%d\n", maxlen);
}