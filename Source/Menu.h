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

class bbg_Menu : public juce::ComboBox
{
public:
    bbg_Menu()
    {
        initProperties();
    }
    
    ~bbg_Menu() override
    {
        setLookAndFeel(nullptr);
    }
    
private:
    juce::ComboBoxOneStyle ComboBoxOneLAF;
    
    void initProperties();
};



}
