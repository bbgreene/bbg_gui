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
    
    // makes the start and end points closer together in terms of range...
    setRotaryParameters(juce::MathConstants<float>::pi * 1.25f, juce::MathConstants<float>::pi * 2.75f, true);
    
    //Changes aspects of the scaling used when in velocity-sensitive mode. setVelocityBasedMode (true) hides mouse when dragging
//    setVelocityBasedMode (true);
//    setVelocityModeParameters (1.0, 1, 0.1, false);
    
    setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    setRange(rangeStart, rangeEnd, intervalValue);
    setValue(startValue);
    setDoubleClickReturnValue(true, returnValue);
    setLookAndFeel(&dialLiveStyleLAF);
    
    setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 25);
    setTextValueSuffix(suffix);
    // how can I continuously send a value to the slider when the textbox value is changed?
    
    // modifies the decimal places of the values displayed in the slider text box.
    // Using this member function and a lambda function called onValueChange, we set the value in the text box to always display three numbers.
    onValueChange = [&]()
        {
            if (getValue() < 10 && getValue() > -10)
                setNumDecimalPlacesToDisplay (2);
            else if (getValue() >= 10 && getValue() < 100)
                setNumDecimalPlacesToDisplay (1);
            else if (getValue() <= -10 && getValue() > -100)
                setNumDecimalPlacesToDisplay (1);
            else
                setNumDecimalPlacesToDisplay (0);
        };
    
    //previous colours used
//    setColour(juce::Slider::ColourIds::rotarySliderFillColourId, juce::Colours::orange);
//    setColour(juce::Slider::ColourIds::thumbColourId, juce::Colours::orange);
//    setColour(juce::Slider::ColourIds::trackColourId, juce::Colours::black);
    
    //modern dial using custom colours
    setColour (juce::Slider::textBoxTextColourId, CustomColours::creamWhite);
    setColour (juce::Slider::textBoxOutlineColourId, CustomColours::grey);
    setColour (juce::Slider::rotarySliderFillColourId, CustomColours::blue);
}

