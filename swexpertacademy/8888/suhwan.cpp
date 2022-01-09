#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
 
bool check[2001][2001];
int p_score[2001];
int score[2001]; //문제 배점 배열
int num[2001]; //사람 당 푼 문제 수 배열
int main()
{
    int t; scanf("%d", &t);
    int cnt = 0;
    while (t--) {
        cnt++;
        printf("#%d ", cnt);
        int N, T, P; 
        scanf("%d %d %d", &N, &T, &P);  
        getchar();
        memset(score, 0, sizeof(score));
        memset(num, 0, sizeof(num));
        memset(check, false, sizeof(check));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= T; j++) {
                char ch = getchar();
                getchar();
                if (ch == '0') score[j]++;
                else {
                    num[i]++;
                    check[i][j] = true;
                }
            }
        }
        //지학이의 최종 점수
        int ans_score = 0;
         
        memset(p_score, 0, sizeof(p_score));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= T; j++) {
                if (check[i][j] == true) {
                    p_score[i] += score[j];
                }
            }
        }
        ans_score = p_score[P];
        //지학이의 등수
        int ans_rank = 1;
        for (int i = 1; i <= N; i++) {
            if (i == P) continue;
            if (ans_score < p_score[i]) ans_rank++;
            else if (ans_score == p_score[i] && num[P] < num[i]) ans_rank++;
            else if (ans_score == p_score[i] && num[P] == num[i] && P > i) ans_rank++;
        }
        printf("%d %d\n", ans_score, ans_rank);
    }
    return 0;
}