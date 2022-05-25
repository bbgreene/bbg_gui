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
    setTextValueSuffix(suffix);
    setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 25);
    
    // how can I continuously send a value to the slider when the textbox value is changed?
    
    // modifies the decimal places of the values displayed in the slider text box.
    // Using this member function and a lambda function called onValueChange, we set the value in the text box to always display three numbers.
    onValueChange = [&]()
    {
        if (getValue() == 0.0)
            setNumDecimalPlacesToDisplay(1);
        else if (getValue() < 10 && getValue() > -10)
            setNumDecimalPlacesToDisplay (2);
        else if (getValue() >= 10 && getValue() < 100)
            setNumDecimalPlacesToDisplay (1);
        else if (getValue() <= -10 && getValue() > -100)
            setNumDecimalPlacesToDisplay (1);
        else
            setNumDecimalPlacesToDisplay (0);
    };

    //modern dial using custom colours
    setColour (juce::Slider::textBoxTextColourId, CustomColours::black);
    setColour (juce::Slider::textBoxOutlineColourId, CustomColours::grey);
    
    //Dial colours used for filling arc with value
    setColour (juce::Slider::rotarySliderFillColourId, CustomColours::blue);
    //Colour used to fill full middle area of dial
    setColour (juce::Slider::thumbColourId, CustomColours::creamWhite);
    //Colour used for tick/back arc/dots in moderndotdial. Colour used for large back arc in moderndial.
    setColour (juce::Slider::rotarySliderOutlineColourId, CustomColours::blackGrey);

}

// function for a dial that needs different suffix for panning - returning C, L, R depending on value. Whatever dial is using this, it ignores the above onValueChange regarding decimal places.
void bbg_gui::bbg_Dial::panDialSuffixChange(Slider& slider)
{
    slider.onValueChange = [&]()
    {
        DBG(slider.getValue());
        if (slider.getValue() == 0.0)
            slider.setTextValueSuffix(" C");
        else if (slider.getValue() > 0.0)
            slider.setTextValueSuffix(" R");
        else if (slider.getValue() < 0.0)
            slider.setTextValueSuffix(" L");
        else {}
    };
}


