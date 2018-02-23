#pragma once
#include "SDL.h"
class SDLWindow
{
private:

	bool IsRunning = true, Isbusy = false, JoystickConnected[2] = { false, false };
	int Deadzone[2][6]; //deadzone for each axys
	SDL_Joystick *Joystick[2] = { NULL,NULL };
	SDL_Haptic *JoystickFeedback[2] = { NULL, NULL };
	SDL_Event Event;

public:
	SDLWindow();
	~SDLWindow();
	bool Busy();
	void MainLoop();
	bool Start();
	int JoystickCount();
	int JoystickGetAxis(int, int);
	bool JoystickConnect(int, int);
	void JoystickDisconnect(int);
	unsigned int Joystick_255(int, int);
	void JoystickSetDZ(int, int, int);
	bool IsJoyConnected(int);
};