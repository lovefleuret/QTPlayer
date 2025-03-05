@echo off
echo Select operation:
echo 1. Run qmake
echo 2. Run mingw32-make
echo 3. Run program
echo 4. Run all steps
echo 5. Clean build files
echo.

set /p choice=Enter your choice (1-5): 

if "%choice%"=="5" (
    if exist "build" (
        rd /s /q build
        echo Build directory cleaned.
        mkdir build
    )
    @REM goto end
)

if not exist "build" mkdir build
cd build

if "%choice%"=="1" (
    qmake ..
) else if "%choice%"=="2" (
    mingw32-make -f Makefile.Debug -j20
) else if "%choice%"=="3" (
    cd debug
    for %%i in (*.exe) do (
        %%i
        break
    )
    cd ..
) else if "%choice%"=="4" (
    qmake ..
    mingw32-make -f Makefile.Debug -j20
    if errorlevel 1 (
        echo Build failed! Skipping program execution.
    ) else (
        cd debug
        for %%i in (*.exe) do (
            %%i
            break
        )
        cd ..
    )
) else (
    echo Invalid choice!
)

:end
cd ..