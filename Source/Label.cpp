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

void bbg_gui::bbg_Label::componentMovedOrResized (Component& component, bool /*wasMoved*/, bool /*wasResized*/)
{
    auto& lf = getLookAndFeel();
    auto f = lf.getLabelFont (*this);
    auto borderSize = lf.getLabelBorderSize (*this);
   
    auto height = borderSize.getTopAndBottom() + 6 + juce::roundToInt (f.getHeight() + 0.5f);
    setBounds (component.getX(), component.getY() - 30.0f, component.getWidth(), height);
   

    
}

