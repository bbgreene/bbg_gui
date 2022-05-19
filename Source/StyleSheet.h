/*
  ==============================================================================

    StyleSheet.h
    Created: 17 May 2022 12:48:27pm
    Author:  Brian Greene

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "CustomColours.h"

namespace juce
{

// A Live style dial class
class dialLiveStyle : public LookAndFeel_V4
{
  
public:
    
    void drawRotarySlider (Graphics &, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider &) override;

};

// A solid dial and tick class
class dialSimpleSolid : public LookAndFeel_V4
{
        
public:
        
    void drawRotarySlider(Graphics &, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider &) override;
};

// A dial with dots class
class dialDotStyle : public LookAndFeel_V4
{
    
public:
    
    void drawRotarySlider (Graphics &, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider &) override;
};

//A modern dial style
class dialModernStyle : public LookAndFeel_V4
{
  
public:
    
    // overriding this function to put textbox in centre of slider/dial
    Slider::SliderLayout getSliderLayout (Slider& slider) override;
    
    void drawRotarySlider (Graphics &, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider &) override;
    
    //creating a label and params to put in centre
    Label* createSliderTextBox (Slider& slider) override;
};

}//my namespace
