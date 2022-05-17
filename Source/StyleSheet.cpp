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
    
    // Line.... (arcRadius - 10.0f) changes the length of the line
    Point<float> thumbPoint (bounds.getCentreX() + (arcRadius - 10.0f) * std::cos (toAngle - MathConstants<float>::halfPi),
                             bounds.getCentreY() + (arcRadius - 10.0f) * std::sin (toAngle - MathConstants<float>::halfPi));

    g.setColour (slider.findColour (Slider::thumbColourId));
    g.drawLine(backgroundArc.getBounds().getCentreX(), backgroundArc.getBounds().getCentreY(), thumbPoint.getX(), thumbPoint.getY(), lineW);
}

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
}
