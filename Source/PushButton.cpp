/*
  ==============================================================================

    PushButton.cpp
    Created: 20 May 2022 6:41:35pm
    Author:  Brian Greene

  ==============================================================================
*/

#include "PushButton.h"

void bbg_gui::bbg_PushButton::initProperties(juce::String labelText)
{
    setLookAndFeel(&customButton);
    setButtonText(labelText);
    setClickingTogglesState(true);
    
    setColour(juce::TextButton::ColourIds::buttonOnColourId, CustomColours::creamWhite);
    setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::whitesmoke);
    setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::black);
    setColour(juce::TextButton::ColourIds::textColourOnId, juce::Colours::black);
    setColour(0x1000c00, CustomColours::blackGrey); // outline colour ID
    
//    setColour(0x1000100, juce::Colours::black.brighter(0.1));
//    setColour(0x1000101, juce::Colours::lightgoldenrodyellow.darker(0.2f));
//    setColour(0x1000102, juce::Colours::whitesmoke.withAlpha(0.5f));
//    setColour(0x1000103, juce::Colours::black.brighter(0.1).withAlpha(0.85f));
}
