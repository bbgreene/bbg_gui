/*
  ==============================================================================

    StyleSheet.h
    Created: 17 May 2022 12:48:27pm
    Author:  Brian Greene

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

namespace juce
{

// A Live style dial class
class dialLiveStyle : public LookAndFeel_V4
{
  
public:
    
    void drawRotarySlider (Graphics &, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider &);
    
};

// A solid dial and tick class
class dialSimpleSolid : public juce::LookAndFeel_V4
{
        
public:
        
    void drawRotarySlider(Graphics &, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider &) override;
};

// A dial with dots class
class dialDotStyle : public juce::LookAndFeel_V4
{
    
public:
    
    void drawRotarySlider (Graphics &, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider &) override;
};

}
