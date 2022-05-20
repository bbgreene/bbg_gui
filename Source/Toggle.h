/*
  ==============================================================================

    Toggle.h
    Created: 20 May 2022 12:29:41pm
    Author:  Brian Greene

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "StyleSheet.h"
#include "CustomColours.h"

// my name space for calling an instantance of a bbg_Toggle
namespace bbg_gui
{

class bbg_Toggle : public juce::TextButton
{
public:
    bbg_Toggle (juce::String labelText)
    
    {
        initProperties(labelText);
    }
    
    ~bbg_Toggle() override
    {
        setLookAndFeel(nullptr);
    }
    
    enum class ToggleStyle
    {
      kToggleOne,
        kToggleTwo
    };
    
    void setToggleStyle (ToggleStyle toggleStyle)
    {
        switch (toggleStyle)
        {
            case ToggleStyle::kToggleOne:
            {
                setLookAndFeel(&toggleOneStyleLAF);
                break;
            }
            case ToggleStyle::kToggleTwo:
            {
                setLookAndFeel(&toggleTwoStyleLAF);
                break;
            }
        }
    }
    
    private:
    
        // Instantance of custom lookAndFeel from StyleSheet
        juce::toggleButtonOneStyle toggleOneStyleLAF;
        juce::toggleButtonTwoStyle toggleTwoStyleLAF;
    
        void initProperties(juce::String labelText);
    
};



}
