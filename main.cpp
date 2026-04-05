#include <windows.h>
#include <iostream>

// Обробка клавіш
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION && wParam == WM_KEYDOWN) {
        KBDLLHOOKSTRUCT* key = (KBDLLHOOKSTRUCT*)lParam;

        switch (key->vkCode) {
            case VK_LEFT:  std::cout << "LEFT\n"; break;
            case VK_RIGHT: std::cout << "RIGHT\n"; break;
            case VK_UP:    std::cout << "UP\n"; break;
            case VK_DOWN:  std::cout << "DOWN\n"; break;

            case VK_DELETE: std::cout << "DELETE\n"; break;
            case VK_INSERT: std::cout << "INSERT\n"; break;
            case VK_HOME:   std::cout << "HOME\n"; break;
            case VK_END:    std::cout << "END\n"; break;

            case VK_ADD:      std::cout << "NUM +\n"; break;
            case VK_SUBTRACT: std::cout << "NUM -\n"; break;
            case VK_MULTIPLY: std::cout << "NUM *\n"; break;
            case VK_DIVIDE:   std::cout << "NUM /\n"; break;

            default:
                std::cout << "Key code: " << key->vkCode << std::endl;
        }
    }

    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int main() {
    HHOOK hook;

    hook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);

    if (!hook) {
        std::cout << "Hook error!\n";
        return 1;
    }

    std::cout << "Натискай клавіші (Ctrl+C для виходу)\n";

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
    }

    UnhookWindowsHookEx(hook);
    return 0;
}