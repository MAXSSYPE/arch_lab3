#include <stdio.h>
#include <unistd.h>
#include <map>
#include <string>
#include <getopt.h>

using namespace std;

int main(int argc, char *argv[]) {
    int rez = 0;
    map<string, bool> used;

    int option_index = -1;
    //f-first;s-second;t-third;e-eights
    const char *short_options = "fste::?";

    const struct option long_options[] = {
            {"first",  0, NULL, 'f'},
            {"second", 0, NULL, 's'},
            {"third",  0, NULL, 't'},
            {"eights", 0, NULL, 'e'},
            {NULL,     0, NULL, 0},
    };

    while ((rez = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1) {
        switch (rez) {
            case 'f': {
                if (used["f"] == false) {
                    printf("First\n");
                    used["f"] = true;
                    break;
                }
                break;
            }
            case 's': {
                if (used["s"] == false) {
                    printf("Second\n");
                    used["s"] = true;
                    break;
                }
                break;
            }
            case 't': {
                if (used["t"] == false) {
                    printf("Third\n");
                    used["t"] = true;
                    break;
                }
                break;
            }
            case 'e': {
                if (used["e"] == false) {
                    printf("Eights\n");
                    used["e"] = true;
                    break;
                }
                break;
            }
            case '?':
            default: {
                printf("Key %c is not found\n", rez);
                break;
            }
        }
        option_index = -1;
    }
}