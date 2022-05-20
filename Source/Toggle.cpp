/*
  ==============================================================================

    Toggle.cpp
    Created: 20 May 2022 12:29:41pm
    Author:  Brian Greene

  ==============================================================================
*/

#include "Toggle.h"

void bbg_gui::bbg_Toggle::initProperties(juce::String labelText)
{
    setButtonText(labelText);
    setClickingTogglesState(true);
    setLookAndFeel(&phaseToggleStyleLAF);
    
    setColour(juce::ToggleButton::tickDisabledColourId, juce::Colours::dimgrey.withAlpha(0.5f));
    setColour(juce::ToggleButton::tickColourId, juce::Colours::springgreen.withAlpha(0.5f));
    setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::lightgoldenrodyellow);
}
