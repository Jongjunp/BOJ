#include <iostream>
#include <queue>
#define pairs pair<int,string>
using namespace std;

int tc = 0;
int a, b;
char funcs[4] = {'D', 'S', 'L', 'R'};
int answers[10000][4];                
bool visited[10000];

int ret(int temp, int func)            
{
    if(func == 0)       temp = (temp * 2) % 10000;                
    else if(func == 1)  temp -= 1;                                 
    else if(func == 2)  temp = (temp % 1000) * 10 + (temp / 1000); 
    else                temp = (temp / 10) + (temp % 10) * 1000;   

    if(temp < 0) temp = 9999;
    return temp;
}

int main(void)
{
    cin >> tc;
    for(int i = 0 ; i < 10000 ; i++)            
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            answers[i][j] = ret(i, j);
        }
    }
    while(tc--)
    {
        for(int i = 0 ; i < 10000 ; i++) visited[i] = false;   
        cin >> a >> b;

        queue<pairs> q;
        int cur;
        q.push(pairs(a, ""));                  
        visited[a] = true;                    
        while(true)
        {
            cur = q.front().first;
            if(cur == b) break;                
            for(int i = 0, k ; i < 4 ; i++)  
            {
                k = answers[cur][i];
                if(visited[k]) continue;      
                visited[k] = true;             
                q.push(pairs(k, q.front().second + funcs[i]));  
            }
            q.pop();
        }
        cout << q.front().second << '\n';    
    }
}
//출처: https://bconfiden2.tistory.com/133