/*
 *      Copyright (C) 2016-2017 Sam Lantinga
 *      Copyright (C) 2014-2015 Team XBMC
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "JoystickSDL.h"
#include "api/JoystickTypes.h"

#include <SDL2/SDL.h>

using namespace JOYSTICK;

#define MAX_AXIS      32768

CJoystickSDL::CJoystickSDL(SDL_GameController* pController) :
  CJoystick(INTERFACE_SDL),
  m_pController(pController)
{
  SetName("SDL Game Controller");
  SetButtonCount(SDL_CONTROLLER_BUTTON_MAX);
  SetAxisCount(SDL_CONTROLLER_AXIS_MAX);
}

CJoystickSDL::~CJoystickSDL(void)
{
  SDL_GameControllerClose(m_pController);
}

bool CJoystickSDL::Equals(const CJoystick* rhs) const
{
  if (rhs == nullptr)
    return false;

  const CJoystickSDL* rhsSDL = dynamic_cast<const CJoystickSDL*>(rhs);
  if (rhsSDL == nullptr)
    return false;

  return m_pController == rhsSDL->m_pController;
}

bool CJoystickSDL::ScanEvents(void)
{
  SetButtonValue(0,  SDL_GameControllerGetButton(m_pController, SDL_CONTROLLER_BUTTON_A)             ? JOYSTICK_STATE_BUTTON_PRESSED : JOYSTICK_STATE_BUTTON_UNPRESSED);
  SetButtonValue(1,  SDL_GameControllerGetButton(m_pController, SDL_CONTROLLER_BUTTON_B)             ? JOYSTICK_STATE_BUTTON_PRESSED : JOYSTICK_STATE_BUTTON_UNPRESSED);
  SetButtonValue(2,  SDL_GameControllerGetButton(m_pController, SDL_CONTROLLER_BUTTON_X)             ? JOYSTICK_STATE_BUTTON_PRESSED : JOYSTICK_STATE_BUTTON_UNPRESSED);
  SetButtonValue(3,  SDL_GameControllerGetButton(m_pController, SDL_CONTROLLER_BUTTON_Y)             ? JOYSTICK_STATE_BUTTON_PRESSED : JOYSTICK_STATE_BUTTON_UNPRESSED);
  SetButtonValue(4,  SDL_GameControllerGetButton(m_pController, SDL_CONTROLLER_BUTTON_LEFTSHOULDER)  ? JOYSTICK_STATE_BUTTON_PRESSED : JOYSTICK_STATE_BUTTON_UNPRESSED);
  SetButtonValue(5,  SDL_GameControllerGetButton(m_pController, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER) ? JOYSTICK_STATE_BUTTON_PRESSED : JOYSTICK_STATE_BUTTON_UNPRESSED);
  SetButtonValue(6,  SDL_GameControllerGetButton(m_pController, SDL_CONTROLLER_BUTTON_BACK)          ? JOYSTICK_STATE_BUTTON_PRESSED : JOYSTICK_STATE_BUTTON_UNPRESSED);
  SetButtonValue(7,  SDL_GameControllerGetButton(m_pController, SDL_CONTROLLER_BUTTON_START)         ? JOYSTICK_STATE_BUTTON_PRESSED : JOYSTICK_STATE_BUTTON_UNPRESSED);
  SetButtonValue(8,  SDL_GameControllerGetButton(m_pController, SDL_CONTROLLER_BUTTON_LEFTSTICK)     ? JOYSTICK_STATE_BUTTON_PRESSED : JOYSTICK_STATE_BUTTON_UNPRESSED);
  SetButtonValue(9,  SDL_GameControllerGetButton(m_pController, SDL_CONTROLLER_BUTTON_RIGHTSTICK)    ? JOYSTICK_STATE_BUTTON_PRESSED : JOYSTICK_STATE_BUTTON_UNPRESSED);
  SetButtonValue(10, SDL_GameControllerGetButton(m_pController, SDL_CONTROLLER_BUTTON_DPAD_UP)       ? JOYSTICK_STATE_BUTTON_PRESSED : JOYSTICK_STATE_BUTTON_UNPRESSED);
  SetButtonValue(11, SDL_GameControllerGetButton(m_pController, SDL_CONTROLLER_BUTTON_DPAD_RIGHT)    ? JOYSTICK_STATE_BUTTON_PRESSED : JOYSTICK_STATE_BUTTON_UNPRESSED);
  SetButtonValue(12, SDL_GameControllerGetButton(m_pController, SDL_CONTROLLER_BUTTON_DPAD_DOWN)     ? JOYSTICK_STATE_BUTTON_PRESSED : JOYSTICK_STATE_BUTTON_UNPRESSED);
  SetButtonValue(13, SDL_GameControllerGetButton(m_pController, SDL_CONTROLLER_BUTTON_DPAD_LEFT)     ? JOYSTICK_STATE_BUTTON_PRESSED : JOYSTICK_STATE_BUTTON_UNPRESSED);
  SetButtonValue(14, SDL_GameControllerGetButton(m_pController, SDL_CONTROLLER_BUTTON_GUIDE)         ? JOYSTICK_STATE_BUTTON_PRESSED : JOYSTICK_STATE_BUTTON_UNPRESSED);

  SetAxisValue(0, (long)SDL_GameControllerGetAxis(m_pController, SDL_CONTROLLER_AXIS_LEFTX), MAX_AXIS);
  SetAxisValue(1, (long)SDL_GameControllerGetAxis(m_pController, SDL_CONTROLLER_AXIS_LEFTY), MAX_AXIS);
  SetAxisValue(2, (long)SDL_GameControllerGetAxis(m_pController, SDL_CONTROLLER_AXIS_RIGHTX), MAX_AXIS);
  SetAxisValue(3, (long)SDL_GameControllerGetAxis(m_pController, SDL_CONTROLLER_AXIS_RIGHTY), MAX_AXIS);
  SetAxisValue(4, (long)SDL_GameControllerGetAxis(m_pController, SDL_CONTROLLER_AXIS_TRIGGERLEFT), MAX_AXIS);
  SetAxisValue(5, (long)SDL_GameControllerGetAxis(m_pController, SDL_CONTROLLER_AXIS_TRIGGERRIGHT), MAX_AXIS);

  return true;
}
