#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // set default font
    juce::LookAndFeel::getDefaultLookAndFeel().setDefaultSansSerifTypefaceName ("Avenir Next");

        //*** 5 example dials. The colours of each can be edited here to override initProperties() in Dial.cpp/h
    
    //Example of Live style dial...examples of changing the colours of certain elements of dial.
    gain.setDialStyle(bbg_gui::bbg_Dial::DialStyle::kDialLiveStyle);
    addAndMakeVisible(gain);

    //Example of solid coloured dial with a simple tick to define current position
    delay.setDialStyle(bbg_gui::bbg_Dial::DialStyle::kDialSimpleSolid);
    addAndMakeVisible(delay);
    
    //Example of dial with simple tick to define current position and dots on the outside 
    balance.setDialStyle(bbg_gui::bbg_Dial::DialStyle::kDialDotStyle);
//    balance.setColour(juce::Slider::ColourIds::rotarySliderOutlineColourId, CustomColours::yellow);
    addAndMakeVisible(balance);
    
    //Example of modern style dial with text box/label in middle. Customisable colours used to override initProperties() in Dial.cpp/h
    depth.setDialStyle(bbg_gui::bbg_Dial::DialStyle::kDialModernStyle);
//    depth.setColour(juce::Slider::ColourIds::rotarySliderOutlineColourId, CustomColours::blackGrey);
//    depth.setColour(juce::Slider::ColourIds::thumbColourId, CustomColours::creamWhite);
    addAndMakeVisible(depth);
    
    //Example of modern style dial with dots and text box/label in middle. Customisable colours used to override initProperties() in Dial.cpp/h
    freq.setDialStyle(bbg_gui::bbg_Dial::DialStyle::kDialDotModernStyle);
//    freq.setColour(juce::Slider::ColourIds::rotarySliderOutlineColourId, CustomColours::blackGrey);
//    freq.setColour(juce::Slider::ColourIds::thumbColourId, CustomColours::creamWhite);
    addAndMakeVisible(freq);
    
    //Attaching labels to dials. Customisable colours used to override initProperties() in Label.cpp/h
    depthLabel.attachToComponent(&depth, false);
    freqLabel.attachToComponent(&freq, false);
    
        //*** 2 examples of toggle buttons. The colours of each can be edited here to override initProperties() in Toggle.cpp/h
    
    //Example of phase button(utilising juce::toggleButton). Customisable colours used to override initProperties() in Toggle.cpp/h
    phase.setToggleStyle(bbg_gui::bbg_Toggle::ToggleStyle::kPhaseToggle);
    phase.setColour(juce::ToggleButton::ColourIds::tickDisabledColourId, CustomColours::blackGrey);
    phase.setColour(juce::ToggleButton::ColourIds::tickColourId, CustomColours::blue);
    addAndMakeVisible(phase);
    
    //Example of power button with text in middle (utilising juce::toggleButton).
    power.setToggleStyle(bbg_gui::bbg_Toggle::ToggleStyle::kPowerToggle);
    addAndMakeVisible(power);
    
    //Attaching labels to toggles. Customisable colours used to override initProperties() in Label.cpp/h
    phaseLabel.attachToComponent(&phase, false);
    powerLabel.attachToComponent(&power, false);

        //*** 1 example a push button. The colours can be edited here to override initProperties() in PushButton.cpp/h
    
    //Example of Push Button (utilising juce::textButton)
    addAndMakeVisible(mute);
    
        //*** 1 example of a Menu. The colours can be edited here to override initProperties() in Menu.cpp/h
    
    //Example of ComboBox Menu (utilising juce::textButton)
    box.setText("Waveform");
    box.addItem("Sine", 1);
    box.addItem("Triangle", 2);
    box.addItem("Square", 3);
    addAndMakeVisible(box);
    
    setSize (1200, 400);
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
    auto dialSize = 200;
    auto buttonWidth = dialSize * 0.7;
    auto buttonHeight = buttonWidth * 0.5;
    
    gain.setBounds(0, getHeight() / 2 - 100, dialSize, dialSize);
    delay.setBounds(gain.getX() + dialSize, getHeight() / 2 - 100, dialSize, dialSize);
    balance.setBounds(delay.getX() + dialSize, getHeight() / 2 -100, dialSize, dialSize);
    depth.setBounds(balance.getX() + dialSize, getHeight() / 2 - 100, dialSize, dialSize);
    freq.setBounds(depth.getX() + dialSize, getHeight() / 2 - 100, dialSize, dialSize);
    phase.setBounds(freq.getX() + dialSize + 25, getHeight() / 2 - 100, buttonWidth, buttonHeight);
    power.setBounds(phase.getX(), phase.getY() + 75, buttonWidth, buttonHeight);
    mute.setBounds(power.getX(), power.getY() + 75, buttonWidth, buttonHeight);
    box.setBounds(mute.getX(), mute.getY() + 75, buttonWidth, buttonHeight);
}
