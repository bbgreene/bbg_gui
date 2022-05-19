#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    //Example of Live style dial...examples of changing the colours of certain elements of dial
    gain.setDialStyle(bbg_gui::bbg_Dial::DialStyle::kDialLiveStyle);
//    gain.setColour(juce::Slider::ColourIds::rotarySliderFillColourId, juce::Colours::orange);
//    gain.setColour(juce::Slider::ColourIds::rotarySliderOutlineColourId, juce::Colours::white);
    addAndMakeVisible(gain);

    //Example of solid coloured dial with a simple tick to define current position
    delay.setDialStyle(bbg_gui::bbg_Dial::DialStyle::kDialSimpleSolid);
//    delay.setColour(juce::Slider::ColourIds::thumbColourId, juce::Colours::pink);
    addAndMakeVisible(delay);
    
    //Example of dial with simple tick to define current position and dots on the outside 
    balance.setDialStyle(bbg_gui::bbg_Dial::DialStyle::kDialDotStyle);
//    balance.setColour(juce::Slider::ColourIds::thumbColourId, juce::Colours::pink);
    addAndMakeVisible(balance);
    
    depth.setDialStyle(bbg_gui::bbg_Dial::DialStyle::kDialModernStyle);
    // CustomColours::creamWhite stick
    // CustomColours::blackGrey
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
