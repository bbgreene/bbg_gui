/*
  ==============================================================================

    Menu.cpp
    Created: 23 May 2022 12:03:56pm
    Author:  Brian Greene

  ==============================================================================
*/

#include "Menu.h"
void bbg_gui::bbg_Menu::initProperties()
{
    setLookAndFeel(&ComboBoxOneLAF);
    
    setColour(juce::ComboBox::ColourIds::backgroundColourId, juce::Colours::black.brighter(0.1));
    setColour(juce::ComboBox::ColourIds::outlineColourId, juce::Colours::whitesmoke.withAlpha(0.0f));
    setColour(juce::ComboBox::ColourIds::focusedOutlineColourId, juce::Colours::black.withAlpha(0.5f));
    setColour(juce::ComboBox::ColourIds::textColourId, juce::Colours::whitesmoke.withAlpha(0.5f));
    setColour(juce::ComboBox::ColourIds::arrowColourId, juce::Colours::whitesmoke.withAlpha(0.5f));

    getLookAndFeel().setColour(juce::PopupMenu::backgroundColourId, juce::Colours::black.brighter(0.1));
    getLookAndFeel().setColour(juce::PopupMenu::highlightedBackgroundColourId, juce::Colours::skyblue.withAlpha(0.1f));
    getLookAndFeel().setColour(juce::PopupMenu::textColourId, juce::Colours::whitesmoke.withAlpha(0.5f));
    getLookAndFeel().setColour(juce::PopupMenu::highlightedTextColourId, juce::Colours::whitesmoke.withAlpha(0.5f));

    setJustificationType(juce::Justification::centred);
}
