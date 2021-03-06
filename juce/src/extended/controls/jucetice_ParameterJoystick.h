/*
 ==============================================================================

 This file is part of the JUCETICE project - Copyright 2009 by Lucio Asnaghi.

 JUCETICE is based around the JUCE library - "Jules' Utility Class Extensions"
 Copyright 2007 by Julian Storer.

 ------------------------------------------------------------------------------

 JUCE and JUCETICE can be redistributed and/or modified under the terms of
 the GNU General Public License, as published by the Free Software Foundation;
 either version 2 of the License, or (at your option) any later version.

 JUCE and JUCETICE are distributed in the hope that they will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with JUCE and JUCETICE; if not, visit www.gnu.org/licenses or write to
 Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 Boston, MA 02111-1307 USA

 ==============================================================================
*/

#ifndef __JUCETICE_PARAMETERJOYSTICK_HEADER__
#define __JUCETICE_PARAMETERJOYSTICK_HEADER__

#include "jucetice_Joystick.h"
#include "../jucetice_AudioParameter.h"


//==============================================================================
/**
     A parameter listener slider
*/
class ParameterJoystick  : public Joystick,
                           public AudioParameterListener
{
public:

    //==============================================================================
    ParameterJoystick ()
        : Joystick (),
          Xindex (-1),
          Yindex (-1)
    {
    }

    //==============================================================================
    virtual ~ParameterJoystick()
    {
    }

    //==============================================================================
    void setIndexForValues (const int x, const int y)
    {
        Xindex = x;
        Yindex = y;
    }

    //==============================================================================
    void parameterChanged (AudioParameter* parameter, const int index)
    {
        if (index == Xindex)
            setValues (parameter->getValueMapped (), getVerticalValue(), false);
        else if (index == Yindex)
            setValues (getHorizontalValue(), parameter->getValueMapped (), false);

        repaint ();
    }

protected:

    int Xindex, Yindex;
};


#endif // __JUCETICE_PARAMETERSLIDER_HEADER__
