#pragma once

#include "PluginProcessor.h"
#include "BinaryData.h"
#include "melatonin_inspector/melatonin_inspector.h"

/**
 * @brief AudioProcessorEditor for VsTPrompter.
 * Defines the GUI for the AudioProcessor.
 * @see
 *  <a href="https://docs.juce.com/master/classAudioProcessorEditor.html">
 *      juce::AudioProcessorEditor
 * </a>
 */
class PluginEditor : public juce::AudioProcessorEditor
{
public:
    /**
     * @brief Creates an editor for the specified processor.
     * @param  p    The target processor.
     * @see
     *  <a href="https://docs.juce.com/master/classAudioProcessorEditor.html#a213530cf58bc4e47354ed1a65520adbb">
     *      juce::AudioProcessorEditor::AudioProcessorEditor()
     *  </a>
     */
    explicit PluginEditor (PluginProcessor&);

    /**
     * @brief Destructor.
     * @see
     *  <a href="https://docs.juce.com/master/classAudioProcessorEditor.html#ad16d8f6168903a091ef7b9709367988f">
     *      juce::AudioProcessor::~AudioProcessorEditor()
     *  </a>
     */
    ~PluginEditor() override;

    /**
     * @brief Draw the content.
     * @param  g    The graphics component that must be used to do the draw
     *  operations.
     * @see
     *  <a href="https://docs.juce.com/master/classComponent.html#a7cf1862f4af5909ea72827898114a182">
     *      virtual juce::Component::paint()
     *  </a>
     */
    void paint (juce::Graphics&) override;

    /**
     * @brief Called when this component's size has been changed.
     * @see
     *  <a href="https://docs.juce.com/master/classComponent.html#ad896183a68d71daf5816982d1fefd960">
     *      virtual juce::Component::resized()
     *  </a>
     */
    void resized() override;

private:
    /** Reference to the audio processor. */
    PluginProcessor& processorRef;
    /** Melatonin Inspector to use for this GUI. */
    std::unique_ptr<melatonin::Inspector> inspector;
    /** Button to open the inspector for this GUI. */
    juce::TextButton inspectButton { "Inspect the UI" };
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
