#pragma once

#include <JuceHeader.h>
#include "Dial.h"
#include "Toggle.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
//    Create an instance like this:
//        * bbg_gui::bbg_Dial { " samples", 0.0, 50.0, 0.1, 0.0, 0.0};
//        * " samples" is the text in the dial's number textbox
//        * 0.0 is the range start
//        * 10.0 is the range end
//        * 0.1 is the interval between each dial setting
//        * 0.0 is the starting value
//        * 0.0 is the number the dial is reset to when double clicked
    
    bbg_gui::bbg_Dial gain { " dB", -24.0, 24.0, 0.1, 0.0, 0.0 };
    bbg_gui::bbg_Dial delay { " Samples", 0.0, 50.0, 0.1, 0.0, 0.0};
    bbg_gui::bbg_Dial balance { " Balance", -50.0, 50.0, 0.1, 0.0, 0.0 };
    bbg_gui::bbg_Dial depth { " Depth", 0.0, 10.0, 0.1, 0.0, 0.0 };
    
    bbg_gui::bbg_Toggle phase { "Phase" };
    bbg_gui::bbg_Toggle mute { "Mute" };
    //==============================================================================
    // Your private member variables go here...


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
