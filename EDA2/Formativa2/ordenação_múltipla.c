#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double score;
    int member, problem;
} Problem;

int compare(const void *a, const void *b) {
    Problem *p1 = (Problem *)a;
    Problem *p2 = (Problem *)b;
    if (p1->score > p2->score) return -1;
    if (p1->score < p2->score) return 1;
    if (p1->member < p2->member) return -1;
    if (p1->member > p2->member) return 1;
    return p1->problem - p2->problem;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        Problem problems[n*m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%lf", &problems[i*m + j].score);
                problems[i*m + j].member = i + 1;
                problems[i*m + j].problem = j + 1;
            }
        }
        qsort(problems, n*m, sizeof(Problem), compare);
        for (int i = 0; i < n*m; i++) {
            printf("%d,%d ", problems[i].member, problems[i].problem);
        }
        printf("\n");
    }
    return 0;
}
