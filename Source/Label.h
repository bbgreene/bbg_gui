/*
  ==============================================================================

    Label.h
    Created: 24 May 2022 10:22:31am
    Author:  Brian Greene

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "StyleSheet.h"
#include "CustomColours.h"

namespace bbg_gui
{

class bbg_Label : public juce::Label
{
public:
    bbg_Label(juce::String labelText)
    {
        initProperties(labelText);
    }
    
    ~bbg_Label() override
    {
        
    }

private:
    
    void initProperties(juce::String labelText);
    
};


}
