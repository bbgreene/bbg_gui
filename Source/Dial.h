/*
  ==============================================================================

    Dial.h
    Created: 16 May 2022 9:08:22pm
    Author:  Brian Greene

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "StyleSheet.h"
#include "CustomColours.h"

// my name space for calling an instantance of a bbg_Dial
namespace bbg_gui
{

class bbg_Dial : public juce::Slider
{
public:
    bbg_Dial(juce::String suffix,
               double rangeStart,
               double rangeEnd,
               double intervalValue,
               double startValue,
               double returnValue)
    {
        initProperties(suffix, rangeStart, rangeEnd, intervalValue, startValue, returnValue);
    }
    
    ~bbg_Dial() override
    {
        setLookAndFeel(nullptr);
    }
    
    // selection of which dial style to use
    enum class DialStyle
    {
        kDialLiveStyle,
        kDialSimpleSolid,
        kDialDotStyle,
        kDialModernStyle,
        kDialDotModernStyle
    };
    
    // based on the selection above, each case will call a differenct custom lookAndFeel found in StyleSheet
    void setDialStyle(DialStyle dialStyle)
    {
        switch(dialStyle)
        {
            case DialStyle::kDialLiveStyle:
            {
                setLookAndFeel(&dialLiveStyleLAF);
                break;
            }
            case DialStyle::kDialSimpleSolid:
            {
                setLookAndFeel(&dialSimpleSolidLAF);
                break;
            }
            case DialStyle::kDialDotStyle:
            {
                setLookAndFeel(&dialDotStyleLAF);
                break;
            }
            case DialStyle::kDialModernStyle:
            {
                setLookAndFeel(&dialModernStyleLAF);
                break;
            }
            case DialStyle::kDialDotModernStyle:
            {
                setLookAndFeel(&dialDotModernStyleLAF);
                break;
            }
        }
    }
    
    // function for a dial that needs different suffix for panning - returning C, L, R depending on value
    void panDialSuffixChange (Slider& slider);
    
private:
    
    // Instantance of custom lookAndFeel from StyleSheet
    juce::dialLiveStyle dialLiveStyleLAF;
    juce::dialSimpleSolid dialSimpleSolidLAF;
    juce::dialDotStyle dialDotStyleLAF;
    juce::dialModernStyle dialModernStyleLAF;
    juce::dialDotModernStyle dialDotModernStyleLAF;
    
    // properties of an individual dial. When a dial is instantiated with variables, these are passed to this function
    void initProperties(juce::String suffix, double rangeStart, double rangeEnd, double intervalValue, double startValue, double returnValue);
};

}
