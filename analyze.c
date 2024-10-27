#include <stdio.h>

int main() {
    int something = 0;

    int port = 0;
    int status = 0;
    unsigned long long bytes = 0;

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;
    int countTotal = 0;

    unsigned long long httpBytes = 0;
    unsigned long long httpsBytes = 0;
    unsigned long long totalBytes = 0;

    while (1) {
        something = scanf("%d %d %llu", &port, &status, &bytes);
        //printf("hello %d ", something);
        if (something != EOF)
        //if (scanf("%d %d %llu", &port, &status, &bytes) != EOF)
        {
            if (something == 3)
            {
                //printf("port is: %d ", port);
                //printf("status is: %d ", status);
                //printf("bytes is: %llu\n", bytes);

                switch(port)
                {
                    case 443:
                        httpsBytes = httpsBytes + bytes;
                        break;
                    case 80:
                        httpBytes = httpBytes + bytes;
                        break;
                    default:
                        //printf("Not http(s) log ");
                        break;
                }

                switch(status/100 * 100)
                {
                    case 100:
                        count1 = count1 + 1;
                        break;
                    case 200:
                        count2 = count2 + 1;
                        break;
                    case 300:
                        count3 = count3 + 1;
                        break;
                    case 400:
                        count4 = count4 + 1;
                        break;
                    case 500:
                        count5 = count5 + 1;
                        break;
                    default:
                        break;
                }
            } else {
                printf("error\n");
            }
        } else {
            totalBytes = httpBytes + httpsBytes;
            countTotal = count1 + count2 + count3 + count4 + count5;

            printf("Requests:\n");
            printf("\t1xx: %d\n", count1);
            printf("\t2xx: %d\n", count2);
            printf("\t3xx: %d\n", count3);
            printf("\t4xx: %d\n", count4);
            printf("\t5xx: %d\n", count5);
            printf("\tTotal: %d\n", countTotal);
            printf("Bytes transferred:\n");
            printf("\thttp: %llu\n", httpBytes);
            printf("\thttps: %llu\n", httpsBytes);
            printf("\tTotal: %llu\n", totalBytes);
            break;
        }
    }

    return 0;
}