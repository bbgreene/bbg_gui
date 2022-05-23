/*
  ==============================================================================

    PushButton.h
    Created: 20 May 2022 6:24:50pm
    Author:  Brian Greene

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "StyleSheet.h"
#include "CustomColours.h"

// my name space for calling an instantance of a bbg_PushButton
namespace bbg_gui
{

class bbg_PushButton : public juce::TextButton
{
public:
    bbg_PushButton (juce::String labelText)
    {
        initProperties(labelText);
    }
    
    ~bbg_PushButton() override
    {
        setLookAndFeel(nullptr);
    }
    
private:
    // Instantance of custom lookAndFeel from StyleSheet
    juce::PushButtonStyle customButton;
    
    // properties of an individual pushbutton. When a push button is instantiated with variables, these are passed to this function
    void initProperties(juce::String labelText);

};

}
