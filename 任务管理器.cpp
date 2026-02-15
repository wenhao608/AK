#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <string>

// 检查 taskmgr.exe 是否正在运行
bool IsTaskManagerRunning() {
    // 创建进程快照 
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE) {
        return false;
    }

    PROCESSENTRY32 pe32{};
    pe32.dwSize = sizeof(PROCESSENTRY32);

    // 遍历所有进程
    if (Process32First(hSnapshot, &pe32)) {
        do {
            // 使用宽字符比较（Windows API 通常使用 Unicode）
            if (_stricmp(pe32.szExeFile, "taskmgr.exe") == 0) {
                CloseHandle(hSnapshot);
                return true;
            }
        } while (Process32Next(hSnapshot, &pe32));
    }

    CloseHandle(hSnapshot);
    return false;
}

// 弹出提醒窗口（非阻塞，避免卡死主线程）
void ShowWarningMessage() {
	
    MessageBoxA(
        nullptr,
        "教学提示：\n\n请勿打开任务管理器。\n遵守课堂纪律，专注学习。",
        "课堂管理提醒",
        MB_OK | MB_ICONWARNING | MB_TOPMOST | MB_SYSTEMMODAL
    );
    for(int i=1;i<=5;++i){
	// 	for(int i=1;i<=1e9;++i){
	    	
	//	}
	//	std::cout << char(7); 
		Beep(800, 300);       // 频率 800Hz，持续 300ms
        Sleep(500);
	}
    
}

int main() {
    std::cout << "[教学辅助程序] 启动中... 正在监控任务管理器\n";

    // 每 5 秒检查一次
    const auto CHECK_INTERVAL = std::chrono::seconds(5);

    while (true) {
        if (IsTaskManagerRunning()) {
            // 在独立线程中弹出警告，避免阻塞检测循环
            std::thread warningThread([]() {
                ShowWarningMessage();
            });
            warningThread.detach(); // 后台运行，不等待
        }

        std::this_thread::sleep_for(CHECK_INTERVAL);
    }

    return 0;
}
