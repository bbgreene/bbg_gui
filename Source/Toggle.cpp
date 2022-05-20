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
    setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::lightgoldenrodyellow);
    setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::dimgrey);
    setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
}
