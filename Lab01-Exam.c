#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, examAmt;
    scanf("%d %d", &n, &examAmt);

    //Correct Answers
    int *Ans = (int *)malloc(examAmt * sizeof(int));

    //Scores Array
    int *Scores = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < examAmt; i++) {
        scanf("%d", &Ans[i]);
    }

    for (int i = 0; i < n; i++) {
        int score = 0;
        for (int j = 0; j < examAmt; j++) {
            int x;
            scanf("%d", &x);
            if (x == Ans[j]) {
                score++;
            }
        } 
        Scores[i] = score;
    }   

    for (int i = 0; i < n; i++) {
        printf("%d ", Scores[i]);
    }

    free(Ans);
    free(Scores);
}