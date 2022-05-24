/*
  ==============================================================================

    Label.cpp
    Created: 24 May 2022 10:22:31am
    Author:  Brian Greene

  ==============================================================================
*/

#include "Label.h"

void bbg_gui::bbg_Label::initProperties(juce::String labelText)
{
    setText(labelText, juce::NotificationType::dontSendNotification);
    setColour(juce::Label::ColourIds::textColourId, CustomColours::creamWhite);
    setFont(juce::Font ("Avenir Next", 30.0f, juce::Font::FontStyleFlags::plain));
    setJustificationType(juce::Justification::centredTop);
}
