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

class bbg_Toggle : public juce::ToggleButton
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
      kPhaseToggle,
        kPowerToggle
    };
    
    void setToggleStyle (ToggleStyle toggleStyle)
    {
        switch (toggleStyle)
        {
            case ToggleStyle::kPhaseToggle:
            {
                setLookAndFeel(&phaseToggleStyleLAF);
                break;
            }
            case ToggleStyle::kPowerToggle:
            {
                setLookAndFeel(&powerToggleStyleLAF);
                break;
            }
        }
    }
    
    private:
    
        // Instantance of custom lookAndFeel from StyleSheet
        juce::phaseToggleStyle phaseToggleStyleLAF;
        juce::powerToggleStyle powerToggleStyleLAF;
    
    // properties of an individual button. When a button is instantiated with variables, these are passed to this function
        void initProperties(juce::String labelText);
    
};



}
