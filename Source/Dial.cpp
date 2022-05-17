/*
  ==============================================================================

    Dial.cpp
    Created: 16 May 2022 9:08:22pm
    Author:  Brian Greene

  ==============================================================================
*/

#include "Dial.h"

void bbg_gui::bbg_Dial::initProperties(juce::String suffix, double rangeStart, double rangeEnd, double intervalValue, double startValue, double returnValue)
{
    //changing the dial start and end angle... 1.5 = 9am start, 3.0 = 6pm end
//        auto rotaryParams = getRotaryParameters();
//        rotaryParams.startAngleRadians = juce::MathConstants<float>::pi * 1.5f;
//        rotaryParams.endAngleRadians = juce::MathConstants<float>::pi * 3.0f;
//        setRotaryParameters(rotaryParams);
    
    setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    setRange(rangeStart, rangeEnd, intervalValue);
    setValue(startValue);
    setDoubleClickReturnValue(true, returnValue);
    setLookAndFeel(&dialLiveStyleLAF);
    
    setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 25);
    setTextValueSuffix(suffix);
    // how can I continuously send a value to the slider when the textbox value is changed?
    
    setColour(juce::Slider::ColourIds::rotarySliderFillColourId, juce::Colours::orange);
    setColour(juce::Slider::ColourIds::thumbColourId, juce::Colours::orange);
    setColour(juce::Slider::ColourIds::trackColourId, juce::Colours::black);
}

