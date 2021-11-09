#include <linux/input.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	FILE *out;
	FILE *fp;
	out = fopen("ex2.txt","w");
	struct input_event event;
	char *str =(char*) malloc(50 * sizeof(char));
	fp = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");
	if (fp != NULL) {
		while(1) {
			fread(&event, sizeof(struct input_event), 1, fp);
			if (event.type == EV_KEY) {
				if (event.value == 0)
					sprintf(str, "RELEASED 0x%04x (%d)", event.code, event.code);
				else if (event.value == 1)
					sprintf(str, "PRESSED 0x%04x (%d)", event.code, event.code);				else if (event.value == 2)
				sprintf(str, "HOLD 0x%04x (%d)", event.code, event.code);
				fprintf(out,"%s\n",str);
				fflush(out);
			}
		}
		fclose(fp);
		fclose(out);
	}
}
