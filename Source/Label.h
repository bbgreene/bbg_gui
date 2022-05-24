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
//dialLabel class
class bbg_dialLabel : public juce::Label
{
public:
    bbg_dialLabel(juce::String labelText)
    {
        initProperties(labelText);
    }
    
    ~bbg_dialLabel() override
    {
        
    }
    
private:
    
    void initProperties(juce::String labelText);
    void componentMovedOrResized(Component& component, bool /*wasMoved*/, bool /*wasResized*/) override;
    
};

//toggleLabel class

class bbg_toggleLabel : public juce::Label
{
public:
    bbg_toggleLabel(juce::String labelText)
    {
        initProperties(labelText);
    }
    
    ~bbg_toggleLabel() override
    {
        
    }
    
private:
    
    void initProperties(juce::String labelText);
    void componentMovedOrResized(Component& component, bool /*wasMoved*/, bool /*wasResized*/) override;
    
};

}
