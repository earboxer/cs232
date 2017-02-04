/* Hello World program */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<unistd.h>

char *message = "ALERT";
void signal_handler(int sig_num) {
    printf("\n Cannot be terminated using Ctrl+C\n");
}

void signal_alarm(int sig_num) {
    printf("%s\n", message);
    fflush(stdout);
}

int main (int argc, char *argv[])
{
    bool interrupts = false;
    int time = 5;

    int temp;
    for(temp = 0; temp < argc; temp++) {
        //read in the params
        if (strcmp(argv[temp], "+i") == 0) {
            interrupts = true;
        } else if (strcmp(argv[temp], "+t") == 0) {
            time = atoi(argv[temp  + 1]);
        } else if (strcmp(argv[temp], "-m") == 0) {
            message = argv[temp + 1];
        }
    }

    if (!interrupts) {
        signal(SIGINT, signal_handler);
    }

    signal(SIGALRM, signal_alarm);

    for(;;) {
        alarm(time);
        pause();
    }
    return 0;
}

