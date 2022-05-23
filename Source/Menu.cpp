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
    
    setColour(juce::ComboBox::ColourIds::backgroundColourId, CustomColours::creamWhite);
    setColour(juce::ComboBox::ColourIds::textColourId, CustomColours::black);
    setColour(juce::ComboBox::ColourIds::arrowColourId, CustomColours::black);
    setColour(juce::ComboBox::ColourIds::outlineColourId, CustomColours::blackGrey);
    setColour(juce::ComboBox::ColourIds::focusedOutlineColourId, CustomColours::blue);
    

//    getLookAndFeel().setColour(juce::PopupMenu::backgroundColourId, juce::Colours::black.brighter(0.1));
//    getLookAndFeel().setColour(juce::PopupMenu::highlightedBackgroundColourId, juce::Colours::skyblue.withAlpha(0.1f));
//    getLookAndFeel().setColour(juce::PopupMenu::textColourId, juce::Colours::whitesmoke.withAlpha(0.5f));
//    getLookAndFeel().setColour(juce::PopupMenu::highlightedTextColourId, juce::Colours::whitesmoke.withAlpha(0.5f));

    setJustificationType(juce::Justification::centred);
}

void bbg_gui::bbg_Menu::timerCallback()
{
    setColour(juce::ComboBox::ColourIds::backgroundColourId, CustomColours::creamWhite);
}

void bbg_gui::bbg_Menu::mouseEnter(const juce::MouseEvent &event)
{
    setColour(juce::ComboBox::ColourIds::backgroundColourId, CustomColours::offCreamWhite);
    startTimer(100);;
}

void bbg_gui::bbg_Menu::mouseExit(const juce::MouseEvent &event)
{
    setColour(juce::ComboBox::ColourIds::backgroundColourId, CustomColours::creamWhite);
    stopTimer();
}
