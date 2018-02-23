#include "SDLWindow.h"



SDLWindow::SDLWindow()
{
}

SDLWindow::~SDLWindow()
{
	JoystickDisconnect(0);
	JoystickDisconnect(1);
	SDL_Quit();
	//throw gcnew System::NotImplementedException();
}

bool SDLWindow::Busy()
{
	return Isbusy;
}

void SDLWindow::MainLoop() {
	Isbusy = true;
	/*SDL_HapticRumblePlay(JoystickFeedback, 0.75, 500);*/
	if (SDL_PollEvent(&Event) != 0) {
		if (Event.type.Equals(SDL_JOYAXISMOTION)) {
			if (Event.jaxis.axis == 0) {
				SDL_HapticRumblePlay(JoystickFeedback[0], (float) abs(SDL_JoystickGetAxis(Joystick[0], 0)) / 32767 , 0);
				//SDL_HapticRumblePlay(JoystickFeedback, 0.75, 500);
			}
		}
	}
	Isbusy = false;
}

bool SDLWindow::Start()
{
	if (SDL_Init(SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC) < 0) return false;
	return true;
}

int SDLWindow::JoystickCount()
{
	SDL_JoystickUpdate();
	return (int)SDL_NumJoysticks();
}

int SDLWindow::JoystickGetAxis(int id, int axis)
{
	return SDL_JoystickGetAxis(Joystick[id], axis);
}

bool SDLWindow::JoystickConnect(int id, int index)
{
	Joystick[id] = SDL_JoystickOpen(index);
	JoystickFeedback[id] = SDL_HapticOpenFromJoystick(Joystick[id]);
	if(Joystick[id] == NULL || JoystickFeedback == NULL) return false;
	if (SDL_HapticRumbleInit(JoystickFeedback[id])<0) return false;
	JoystickConnected[id] = true;
	return true;
}

void SDLWindow::JoystickDisconnect(int id) {
	SDL_HapticClose(JoystickFeedback[id]);
	SDL_JoystickClose(Joystick[id]);
	Joystick[id] = NULL;
	JoystickFeedback[id] = NULL;
	JoystickConnected[id] = false;
}

unsigned int SDLWindow::Joystick_255(int id, int axis)
{
	unsigned int ret;
	if(ret = SDL_JoystickGetAxis(Joystick[id], axis) - Deadzone[0][axis]<=0) return 0;
	else return ret / 128.3;
}

void SDLWindow::JoystickSetDZ(int id,int axis, int val) {
	Deadzone[id][axis] = (int)val * 128.4980392156863;
}

bool SDLWindow::IsJoyConnected(int i)
{
	return JoystickConnected[i];
}
