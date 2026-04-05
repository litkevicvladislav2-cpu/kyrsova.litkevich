#include <iostream>
#include <conio.h>  // для _getch()

int main() {
    std::cout << "Натискай клавіші (ESC - вихід)\n";

    while (true) {
        int key = _getch();  // отримуємо натиснуту клавішу

        // Вихід по ESC
        if (key == 27) {
            std::cout << "\nВихід...\n";
            break;
        }

        // Спец клавіші (стрілки, F1 і т.д.)
        if (key == 0 || key == 224) {
            int special = _getch();

            switch (special) {
                case 72: std::cout << "↑ (Up)\n"; break;
                case 80: std::cout << "↓ (Down)\n"; break;
                case 75: std::cout << "← (Left)\n"; break;
                case 77: std::cout << "→ (Right)\n"; break;

                case 59: std::cout << "F1\n"; break;
                case 60: std::cout << "F2\n"; break;
                case 61: std::cout << "F3\n"; break;
                case 62: std::cout << "F4\n"; break;
                case 63: std::cout << "F5\n"; break;
                case 64: std::cout << "F6\n"; break;
                case 65: std::cout << "F7\n"; break;
                case 66: std::cout << "F8\n"; break;
                case 67: std::cout << "F9\n"; break;
                case 68: std::cout << "F10\n"; break;

                default:
                    std::cout << "Special key: " << special << "\n";
            }
        }
        else {
            // Звичайні клавіші
            std::cout << "Key: " << (char)key << " (code: " << key << ")\n";
        }
    }

    return 0;
}