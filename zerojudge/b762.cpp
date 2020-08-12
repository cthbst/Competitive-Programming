#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    char order[30];
    int i;

    int cnt_kill = 0;
    int cnt_assist = 0;
    int cnt_die = 0;
    int count = 0;

    for (i = 0; i < N; i++) {
        scanf("%s", order);
        if (strcmp(order, "Get_Kill") == 0) {
            const char talk[][30] = {"You have slain an enemie.",
                                     "You have slain an enemie.",
                                     "You have slain an enemie.",
                                     "KILLING SPREE!",
                                     "RAMPAGE~",
                                     "UNSTOPPABLE!",
                                     "DOMINATING!",
                                     "GUALIKE!",
                                     "LEGENDARY!"};
            count++;
            if (count >= 8) count = 8;
            puts(talk[count]);

            cnt_kill++;
        } else if (strcmp(order, "Get_Assist") == 0) {
            cnt_assist++;
        } else {
            cnt_die++;
            if (count < 3)
                puts("You have been slained.");
            else
                puts("SHUTDOWN.");
            count = 0;
        }
    }

    printf("%d/%d/%d\n", cnt_kill, cnt_die, cnt_assist);
}
