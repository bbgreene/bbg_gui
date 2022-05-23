/*
  ==============================================================================

    Menu.h
    Created: 23 May 2022 12:03:56pm
    Author:  Brian Greene

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "StyleSheet.h"
#include "CustomColours.h"

namespace bbg_gui
{

class bbg_Menu : public juce::ComboBox, private juce::Timer
{
public:
    bbg_Menu()
    {
        initProperties();
    }
    
    ~bbg_Menu()
    {
        hidePopup();
        setLookAndFeel(nullptr);
    }
    
private:
    juce::ComboBoxOneStyle ComboBoxOneLAF;
    
    void timerCallback() final;
    void mouseEnter (const juce::MouseEvent& event) override;
    void mouseExit (const juce::MouseEvent& event) override;
    
    void initProperties();
};

}
