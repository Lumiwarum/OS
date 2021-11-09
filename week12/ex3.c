#include <linux/input.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main() {
	FILE *out;
	FILE *fp;
	out = fopen("ex3.txt","w");
	bool pPressed=0,ePressed=0,cPressed=0,aPressed=0,oPressed=0;
	struct input_event event;
	char *str =(char*) malloc(50 * sizeof(char));
	printf("Possible shortcuts:P+E; C+A+P; O+P\n");
	fprintf(out,"Possible shortcuts:P+E; C+A+P; O+P\n");
	fp = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");
	if (fp != NULL) {
		while(1) {
			fread(&event, sizeof(struct input_event), 1, fp);
			if (event.type == EV_KEY) {
				if (event.value == 0){
					switch (event.code){
						case KEY_P: pPressed=0; break;
						case KEY_E: ePressed=0; break;
						case KEY_C: cPressed=0; break;
						case KEY_A: aPressed=0; break;
						case KEY_O: oPressed=0; break;
					}
				}
				else if (event.value == 1){
					switch (event.code){
                                        	case KEY_P: pPressed=1; break;
                                        	case KEY_E: ePressed=1; break;
                                        	case KEY_C: cPressed=1; break;
                                        	case KEY_A: aPressed=1; break;
                                        	case KEY_O: oPressed=1; break;
					}
				}
				if (pPressed && ePressed){
					printf ("I passed the exam!\n");
					fprintf(out,"I passes the exam!\n");
				}
				if (cPressed && aPressed && pPressed){
                                        printf ("Get some cappuccion!\n");
                                        fprintf(out,"Get some cappuccino!\n");
                                }
				if (oPressed && pPressed){
                                        printf ("I'm gonna become the pirate king!\n");
                                        fprintf(out,"I'm gonna become the pirate king!\n");
                                }
				fflush(out);
			}
		}
		fclose(fp);
		fclose(out);
	}
}
