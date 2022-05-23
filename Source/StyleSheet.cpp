/*
  ==============================================================================

    StyleSheet.cpp
    Created: 17 May 2022 12:48:27pm
    Author:  Brian Greene

  ==============================================================================
*/

#include "StyleSheet.h"

namespace  juce
{

// A Live style dial class
void dialLiveStyle::drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider & slider)
{
    auto outline = slider.findColour (Slider::rotarySliderOutlineColourId);
    auto fill    = slider.findColour (Slider::rotarySliderFillColourId);

    auto bounds = Rectangle<int> (x, y, width, height).toFloat().reduced (10);

    auto radius = jmin (bounds.getWidth(), bounds.getHeight()) / 2.0f;
    auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    auto lineW = jmin (4.0f, radius * 0.5f); // lower first values creates smaller lines/circles. although depends on size of dial
    auto arcRadius = radius - lineW * 0.5f;

    // dial background path
    Path backgroundArc;
    backgroundArc.addCentredArc (bounds.getCentreX(),
                                 bounds.getCentreY(),
                                 arcRadius,
                                 arcRadius,
                                 0.0f,
                                 rotaryStartAngle,
                                 rotaryEndAngle,
                                 true);

    g.setColour (outline);
    g.strokePath (backgroundArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));

    if (slider.isEnabled())
    {   // Dial fill path minus or plus
        if(slider.getMinimum() < 0)
        {
            auto radian = juce::MathConstants<float>::twoPi - rotaryStartAngle;

            if(slider.getValue() < 0)
            {
                Path valueArcMinus;
                valueArcMinus.addCentredArc (bounds.getCentreX(),
                                             bounds.getCentreY(),
                                             arcRadius,
                                             arcRadius,
                                             0.0f,
                                             0.0f,
                                             juce::jmap (sliderPos, 0.5f, 0.0f, 0.0f, -radian),
                                             true);
                g.setColour (fill);
                g.strokePath (valueArcMinus, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));
            }
            else
            {
                Path valueArcPlus;
                valueArcPlus.addCentredArc (bounds.getCentreX(),
                                            bounds.getCentreY(),
                                            arcRadius,
                                            arcRadius,
                                            0.0f,
                                            0.0f,
                                            juce::jmap (sliderPos, 0.5f, 1.0f, 0.0f, radian),
                                            true);
                g.setColour (fill);
                g.strokePath (valueArcPlus, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));
            }
        }
        else
        {
        // Dial fill path
        Path valueArc;
        valueArc.addCentredArc (bounds.getCentreX(),
                                bounds.getCentreY(),
                                arcRadius,
                                arcRadius,
                                0.0f,
                                rotaryStartAngle,
                                toAngle,
                                true);

        g.setColour (fill);
        g.strokePath (valueArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));
        }
    }
    
    // Line.... (arcRadius - 10.0f) changes the length of the line
    Point<float> thumbPoint (bounds.getCentreX() + (arcRadius - 10.0f) * std::cos (toAngle - MathConstants<float>::halfPi),
                             bounds.getCentreY() + (arcRadius - 10.0f) * std::sin (toAngle - MathConstants<float>::halfPi));

    g.setColour (slider.findColour (Slider::thumbColourId));
    g.drawLine(backgroundArc.getBounds().getCentreX(), backgroundArc.getBounds().getCentreY(), thumbPoint.getX(), thumbPoint.getY(), lineW);
}

// A solid dial and tick class
void juce::dialSimpleSolid::drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider & slider)
{
    float diameter = fmin(width, height) * .9;
    float radius = diameter * 0.5;
    float centerX = x + width * 0.5;
    float centerY = y + height * 0.5;
    float rx = centerX - radius;
    float ry = centerY - radius;
    float angle = rotaryStartAngle + (sliderPos * (rotaryEndAngle - rotaryStartAngle));
    
    juce::Rectangle<float> dialArea (rx, ry, diameter, diameter);
    g.setColour(slider.findColour(Slider::thumbColourId).withAlpha(0.7f)); //center
    g.fillEllipse(dialArea);
    
    g.setColour(slider.findColour(juce::Slider::ColourIds::rotarySliderOutlineColourId)); //outline
    g.drawEllipse(rx, ry, diameter, diameter, 4.0f);
    
    juce::Path dialTick;
    g.setColour(slider.findColour(juce::Slider::ColourIds::trackColourId)); //tick color
    dialTick.addRectangle(0, -radius + 2, 4.0f, radius * 0.6);
    g.fillPath(dialTick, juce::AffineTransform::rotation(angle).translated(centerX, centerY));
}

// A dial with dots class
void juce::dialDotStyle::drawRotarySlider
(Graphics & g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider & slider)
{
    /** Define color variables for customization. */
    const auto outlineColor  = slider.findColour (juce::Slider::rotarySliderOutlineColourId);
    const auto fillColor     = slider.findColour(Slider::rotarySliderFillColourId);
    const auto mainColor     = slider.findColour(Slider::thumbColourId).withAlpha(0.5f);
    const auto brighterColor = slider.findColour(Slider::thumbColourId).withAlpha(0.5f).brighter(0.15);
    const auto textColor     = slider.findColour (juce::Slider::trackColourId);
    const auto trackColor    = slider.findColour(juce::Slider::ColourIds::trackColourId);

    auto dialBounds = juce::Rectangle<int> (x, y, width, height).toFloat().reduced(10.0);
    auto centre = dialBounds.getCentre();
    auto fullRadius = juce::jmin (dialBounds.getWidth() / 2.0f, dialBounds.getHeight() / 2.0f);

    /** Dot color*/
    g.setColour (textColor);

    centre = dialBounds.getCentre();

    /** Draw dots */
    if (fullRadius > 50.0f)
    {
        /** How many dots to draw, works well as num dial intervals + 1 for small ranges, e.g. [0 - 10]*/
        for (int i = 0; i < 11; ++i)
        {
            /** IF you change the number of dots, do i / (num dots - 1) */
            const auto angle = juce::jmap (i / 10.0f, rotaryStartAngle, rotaryEndAngle);
            const auto point = centre.getPointOnCircumference (fullRadius - 2.0f, angle);
            
            /** Dot thickness*/
            g.fillEllipse (point.getX() - 3, point.getY() - 3, 7, 7);
        }
        
        fullRadius -= 10.0f;
    }

    auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    
    /** Track thickness*/
    auto lineWidth = juce::jmin (6.0f, fullRadius * 0.5f);
    auto arcRadius  = fullRadius - lineWidth;

    juce::Path backgroundArc;
    backgroundArc.addCentredArc
    (
        dialBounds.getCentreX(),
        dialBounds.getCentreY(),
        arcRadius,
        arcRadius,
        0.0f,
        rotaryStartAngle,
        rotaryEndAngle,
        true
     );

    /** Dial fill track color*/
    g.setColour (outlineColor);
    g.strokePath (backgroundArc, juce::PathStrokeType (lineWidth, juce::PathStrokeType::curved, juce::PathStrokeType::rounded));

    auto dialRadius = std:: max (fullRadius - 3.0f * lineWidth, 10.0f);
    {
        juce::Graphics::ScopedSaveState saved (g);
        if (slider.isEnabled())
        {
            juce::ColourGradient fillGradient
            (
                brighterColor,
                centre.getX() + lineWidth * 2.0f,
                centre.getY() - lineWidth * 4.0f,
                mainColor,
                centre.getX() + dialRadius,
                centre.getY() + dialRadius,
                true
            );
            
            /** Dial center color gradient*/
            g.setGradientFill (fillGradient);
        }
        
        g.fillEllipse (centre.getX() - dialRadius, centre.getY() - dialRadius, dialRadius * 2.0f, dialRadius * 2.0f);
    }
    
    dialRadius = std:: max (dialRadius - 4.0f, 10.0f);
    
    /** Dial outline color*/
    g.setColour (outlineColor.brighter());
    
    /** Dial outline thickness*/
    g.drawEllipse (centre.getX() - dialRadius, centre.getY() - dialRadius, dialRadius * 2.0f, dialRadius * 2.0f, 4.0f);
            
    /** Fill Math*/
    juce::Path dialValueTrack;
    dialValueTrack.addCentredArc
    (
        dialBounds.getCentreX(),
        dialBounds.getCentreY(),
        arcRadius,
        arcRadius,
        0.0f,
        toAngle,
        rotaryEndAngle,
        true
     );

    /** Value track fill color*/
    g.setColour (fillColor);
    g.strokePath (dialValueTrack, juce::PathStrokeType (lineWidth, juce::PathStrokeType::curved, juce::PathStrokeType::rounded));
    
    /** Dial tick color*/
    g.setColour (trackColor);
    juce::Path dialTick;
    dialTick.startNewSubPath (centre.getPointOnCircumference (dialRadius - lineWidth, toAngle));
    
    /** Dial tick length*/
    dialTick.lineTo (centre.getPointOnCircumference ((dialRadius - lineWidth) * 0.6f, toAngle));
    
    /** Dial tick thickness*/
    g.strokePath (dialTick, juce::PathStrokeType (lineWidth * 0.75, juce::PathStrokeType::curved, juce::PathStrokeType::rounded));
}


//A modern dial style
void juce::dialModernStyle::drawRotarySlider(Graphics & g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider & slider)
{
    auto fill = slider.findColour (Slider::rotarySliderFillColourId);
    auto stickDial = slider.findColour(Slider::thumbColourId);
    auto backArc = slider.findColour(Slider::rotarySliderOutlineColourId);
    
    auto bounds = juce::Rectangle<float> (x, y, width, height).reduced (2.0f);
    auto radius = juce::jmin (bounds.getWidth(), bounds.getHeight()) / 2.0f;
    auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    auto lineW = radius * 0.085f;
    auto arcRadius = radius - lineW * 1.6f;

    juce::Path backgroundArc;
    backgroundArc.addCentredArc (bounds.getCentreX(),
                                 bounds.getCentreY(),
                                 arcRadius,
                                 arcRadius,
                                 0.0f,
                                 rotaryStartAngle,
                                 rotaryEndAngle,
                                 true);

    g.setColour (backArc);
    g.strokePath (backgroundArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));

    juce::Path valueArc;
    valueArc.addCentredArc (bounds.getCentreX(),
                            bounds.getCentreY(),
                            arcRadius,
                            arcRadius,
                            0.0f,
                            rotaryStartAngle,
                            toAngle,
                            true);

    g.setColour (fill);
    g.strokePath (valueArc, PathStrokeType (lineW, PathStrokeType::curved, PathStrokeType::rounded));

    juce::Path stick;
    auto stickWidth = lineW * 2.0f;

    stick.addRectangle (-stickWidth / 2, -stickWidth / 2, stickWidth, radius + lineW);
    g.setColour (stickDial);
    g.fillPath (stick, juce::AffineTransform::rotation (toAngle + 3.12f).translated (bounds.getCentre()));

    g.fillEllipse (bounds.reduced (radius * 0.25));
}

// modern dial. overriding this function to put textbox in centre of slider/dial
Slider::SliderLayout dialModernStyle::getSliderLayout(Slider &slider)
{
    auto localBounds = slider.getLocalBounds();
    
    Slider::SliderLayout layout;
    
    layout.textBoxBounds = localBounds.withY (-1);
    layout.sliderBounds = localBounds;
    
    return layout;
}

//modern dial. creating a label and params to put in centre
Label* dialModernStyle::createSliderTextBox(Slider & slider)
{
    auto* l = new Label();
    
    l->setJustificationType(Justification::centred);
    l->setColour(Label::textColourId, slider.findColour(Slider::textBoxTextColourId));
    l->setColour (Label::textWhenEditingColourId, slider.findColour (Slider::textBoxTextColourId));
    l->setColour (Label::outlineWhenEditingColourId, juce::Colours::transparentWhite);
    l->setInterceptsMouseClicks (false, false);
    l->setFont (18.0f);

    return l;
}

//Phase Button Style
void juce::phaseToggleStyle::drawToggleButton(Graphics & g, ToggleButton & toggleButton, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown)
{
    Path button;
            
    auto bounds = toggleButton.getLocalBounds();
            
    auto size = jmin(bounds.getWidth(), bounds.getHeight()) - 6;
    auto sr = bounds.withSizeKeepingCentre(size / 2.5, size / 2.5).toFloat();

    button.addEllipse(sr);

    button.startNewSubPath(sr.getX(), sr.getY() + sr.getHeight());
    button.lineTo(sr.getX() + sr.getWidth(), sr.getY());
            
    PathStrokeType pst(2.0f, PathStrokeType::JointStyle::curved);
            
    auto color =
    toggleButton.getToggleState() ? toggleButton.findColour(juce::ToggleButton::tickColourId) : toggleButton.findColour(juce::ToggleButton::tickDisabledColourId);
            
    g.setColour(color);
    g.strokePath(button, pst);
}

//Power Button Style
void juce::powerToggleStyle::drawToggleButton(Graphics & g, ToggleButton & toggleButton, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown)
{
    Path button;
           
    auto bounds = toggleButton.getLocalBounds();
           
    auto size = jmin(bounds.getWidth(), bounds.getHeight()) - 6;
    auto r = bounds.withSizeKeepingCentre(size, size).toFloat();
           
    float ang = 30.f;
           
    size -= 9;


    button.addCentredArc(r.getCentreX(),
                               r.getCentreY(),
                               size * 0.25,
                               size * 0.25,
                               0.f,
                               degreesToRadians(ang),
                               degreesToRadians(360.f - ang),
                               true);
           
    button.startNewSubPath(r.getCentreX(), r.getY() + r.getHeight() * 0.21);
    button.lineTo(r.getCentre());
           
    PathStrokeType pst(2.0f, PathStrokeType::JointStyle::curved);
           
    auto color =
    toggleButton.getToggleState() ? toggleButton.findColour(juce::ToggleButton::tickColourId) : toggleButton.findColour(juce::ToggleButton::tickDisabledColourId);

    g.setColour(color);
    g.strokePath(button, pst);
}

//Push Button from juce::TextButton
void juce::PushButtonStyle::drawButtonText (Graphics& g, TextButton& button,
                     bool /*shouldDrawButtonAsHighlighted*/, bool /*shouldDrawButtonAsDown*/)
{
    Font font (juce::Font ("Helvetica", 16.0f, juce::Font::FontStyleFlags::bold));
    g.setFont (font);
    g.setColour (button.findColour (button.getToggleState() ? TextButton::textColourOnId
                                                            : TextButton::textColourOffId)
                       .withMultipliedAlpha (button.isEnabled() ? 1.0f : 0.5f));

    const int yIndent = jmin (4, button.proportionOfHeight (0.3f));
    const int cornerSize = jmin (button.getHeight(), button.getWidth()) / 2;

    const int fontHeight = roundToInt (font.getHeight() * 0.6f);
    const int leftIndent  = jmin (fontHeight, 2 + cornerSize / (button.isConnectedOnLeft() ? 4 : 2));
    const int rightIndent = jmin (fontHeight, 2 + cornerSize / (button.isConnectedOnRight() ? 4 : 2));
    const int textWidth = button.getWidth() - leftIndent - rightIndent;

    if (textWidth > 0)
        g.drawFittedText (button.getButtonText(),
                          leftIndent, yIndent, textWidth, button.getHeight() - yIndent * 2,
                          Justification::centred, 2);
}

//ComboBox One Style
void juce::ComboBoxOneStyle::drawComboBox(Graphics &g, int width, int height, bool, int, int, int, int, ComboBox &box)
{
    auto cornerSize = box.findParentComponentOfClass<ChoicePropertyComponent>() != nullptr ? 0.0f : 6.0f;
    Rectangle<int> boxBounds (0, 0, width, height);

    g.setColour (box.findColour (ComboBox::backgroundColourId));
    g.fillRoundedRectangle (boxBounds.toFloat(), cornerSize);

    g.setColour (box.findColour (ComboBox::outlineColourId));
    g.drawRoundedRectangle (boxBounds.toFloat().reduced (0.5f, 0.5f), cornerSize, 1.0f);

    Rectangle<int> arrowZone (width - 30, 0, 20, height);
    Path path;
    path.startNewSubPath ((float) arrowZone.getX() + 3.0f, (float) arrowZone.getCentreY() - 2.0f);
    path.lineTo ((float) arrowZone.getCentreX(), (float) arrowZone.getCentreY() + 3.0f);
    path.lineTo ((float) arrowZone.getRight() - 3.0f, (float) arrowZone.getCentreY() - 2.0f);

    //g.setColour (box.findColour (ComboBox::arrowColourId));
    g.setColour (CustomColours::blue);
    g.strokePath (path, PathStrokeType (2.0f));
}

}
