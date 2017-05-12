/*
 *      Copyright (C) 2017 Garrett Brown
 *      Copyright (C) 2017 Team Kodi
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
 *  along with this Program; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 */
#pragma once

namespace JOYSTICK
{
  class CJoystick;

  class CJoystickUtils
  {
  public:
    /*!
     * \brief Check if joystick belongs to a wireless receiver that always
     *        reports a joystick attached, even though none is present
     */
    static bool IsGhostJoystick(const CJoystick& joystick);
  };
}
