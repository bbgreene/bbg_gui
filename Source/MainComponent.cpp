#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    //Example of Live style dial...examples of changing the colours of certain elements of dial
    gain.setDialStyle(bbg_gui::bbg_Dial::DialStyle::kDialLiveStyle);
    gain.setColour(juce::Slider::ColourIds::rotarySliderFillColourId, juce::Colours::orange);
    gain.setColour(juce::Slider::ColourIds::rotarySliderOutlineColourId, juce::Colours::white);
    addAndMakeVisible(gain);

    //Example of solid coloured dial with a simple tick to define current position
    delay.setDialStyle(bbg_gui::bbg_Dial::DialStyle::kDialSimpleSolid);
    addAndMakeVisible(delay);

    
    setSize (400, 400);
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
    gain.setBounds(0, getHeight() / 2 - 100, 200, 200);
    delay.setBounds(200, getHeight() / 2 - 100, 200, 200);
}
