#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // 4 example dials. The colours of each can be edited here to override initProperties() in dial.cpp/h
    
    //Example of Live style dial...examples of changing the colours of certain elements of dial.
    gain.setDialStyle(bbg_gui::bbg_Dial::DialStyle::kDialLiveStyle);
    addAndMakeVisible(gain);

    //Example of solid coloured dial with a simple tick to define current position
    delay.setDialStyle(bbg_gui::bbg_Dial::DialStyle::kDialSimpleSolid);
    addAndMakeVisible(delay);
    
    //Example of dial with simple tick to define current position and dots on the outside 
    balance.setDialStyle(bbg_gui::bbg_Dial::DialStyle::kDialDotStyle);
    addAndMakeVisible(balance);
    
    //Example of modern style dial with text box/label in middle. Customisable colours used to override initProperties() in dial.cpp/h
    depth.setDialStyle(bbg_gui::bbg_Dial::DialStyle::kDialModernStyle);
    depth.setColour(juce::Slider::ColourIds::rotarySliderOutlineColourId, CustomColours::blackGrey);
    depth.setColour(juce::Slider::ColourIds::thumbColourId, CustomColours::creamWhite);
    addAndMakeVisible(depth);

    setSize (800, 400);
}

MainComponent::~MainComponent()
{
    juce::LookAndFeel::setDefaultLookAndFeel(nullptr);
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::grey);
}

void MainComponent::resized()
{
    auto dialSize = 150;
    
    gain.setBounds(0, getHeight() / 2 - 100, dialSize, dialSize);
    delay.setBounds(gain.getX() + dialSize, getHeight() / 2 - 100, dialSize, dialSize);
    balance.setBounds(delay.getX() + dialSize, getHeight() / 2 -100, dialSize, dialSize);
    depth.setBounds(balance.getX() + dialSize, getHeight() / 2 - 100, dialSize, dialSize);
}
