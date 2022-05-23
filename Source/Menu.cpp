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
    
    //Menu colours
    setColour(juce::ComboBox::ColourIds::backgroundColourId, CustomColours::creamWhite);
    setColour(juce::ComboBox::ColourIds::textColourId, CustomColours::black);
    setColour(juce::ComboBox::ColourIds::arrowColourId, CustomColours::black);
    setColour(juce::ComboBox::ColourIds::outlineColourId, CustomColours::blackGrey);
    setColour(juce::ComboBox::ColourIds::focusedOutlineColourId, CustomColours::blue);
    

    //drop down/pop up menu colours
    getLookAndFeel().setColour(juce::PopupMenu::backgroundColourId, CustomColours::blackGrey);
    getLookAndFeel().setColour(juce::PopupMenu::highlightedBackgroundColourId, CustomColours::grey);
    getLookAndFeel().setColour(juce::PopupMenu::textColourId, CustomColours::creamWhite);
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
    startTimer(100);
}

void bbg_gui::bbg_Menu::mouseExit(const juce::MouseEvent &event)
{
    setColour(juce::ComboBox::ColourIds::backgroundColourId, CustomColours::creamWhite);
    stopTimer();
}
