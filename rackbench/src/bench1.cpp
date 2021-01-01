#include "audiocore.h"
#include "plugin.hpp"

struct Bench1 : Module {
  enum ParamIds {
    P0_PARAM,
    P1_PARAM,
    P2_PARAM,
    P3_PARAM,
    P4_PARAM,
    P5_PARAM,
    NUM_PARAMS
  };
  enum InputIds { IN0_INPUT, IN1_INPUT, IN2_INPUT, NUM_INPUTS };
  enum OutputIds { OUT0_OUTPUT, OUT1_OUTPUT, NUM_OUTPUTS };
  enum LightIds { LED0_LIGHT, LED1_LIGHT, NUM_LIGHTS };

  float currentSampleRate = 0;

  Bench1() {
    config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
    configParam(P0_PARAM, 0.f, 1.f, 0.f, "");
    configParam(P1_PARAM, 0.f, 1.f, 0.f, "");
    configParam(P2_PARAM, 0.f, 1.f, 0.f, "");
    configParam(P3_PARAM, 0.f, 1.f, 0.f, "");
    configParam(P4_PARAM, 0.f, 1.f, 0.f, "");
    configParam(P5_PARAM, 0.f, 1.f, 0.f, "");
  }

  void process(const ProcessArgs& args) override {
    if (currentSampleRate != args.sampleRate) {
      currentSampleRate = args.sampleRate;
      AudioCoreInit(currentSampleRate);
    }
    float in[2];
    float out[2];
    AudioCoreKernel(in, out, 2);
    outputs[OUT0_OUTPUT].setVoltage(5.f * out[0]);
    outputs[OUT1_OUTPUT].setVoltage(5.f * out[1]);
  }
};

struct Bench1Widget : ModuleWidget {
  Bench1Widget(Bench1* module) {
    setModule(module);
    setPanel(
        APP->window->loadSvg(asset::plugin(pluginInstance, "res/bench1.svg")));

    addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
    addChild(
        createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
    addChild(createWidget<ScrewSilver>(
        Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
    addChild(createWidget<ScrewSilver>(Vec(
        box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

    addParam(createParamCentered<RoundBlackKnob>(
        mm2px(Vec(15.24, 25.81)), module, Bench1::P0_PARAM));
    addParam(createParamCentered<RoundBlackKnob>(
        mm2px(Vec(45.72, 25.81)), module, Bench1::P1_PARAM));
    addParam(createParamCentered<RoundBlackKnob>(
        mm2px(Vec(76.2, 25.81)), module, Bench1::P2_PARAM));
    addParam(createParamCentered<RoundBlackKnob>(
        mm2px(Vec(15.24, 55.81)), module, Bench1::P3_PARAM));
    addParam(createParamCentered<RoundBlackKnob>(
        mm2px(Vec(45.72, 55.81)), module, Bench1::P4_PARAM));
    addParam(createParamCentered<RoundBlackKnob>(
        mm2px(Vec(76.2, 55.81)), module, Bench1::P5_PARAM));

    addInput(createInputCentered<PJ301MPort>(
        mm2px(Vec(15.24, 83.713)), module, Bench1::IN0_INPUT));
    addInput(createInputCentered<PJ301MPort>(
        mm2px(Vec(45.72, 83.713)), module, Bench1::IN1_INPUT));
    addInput(createInputCentered<PJ301MPort>(
        mm2px(Vec(76.2, 83.713)), module, Bench1::IN2_INPUT));

    addOutput(createOutputCentered<PJ301MPort>(
        mm2px(Vec(38.545, 108.713)), module, Bench1::OUT0_OUTPUT));
    addOutput(createOutputCentered<PJ301MPort>(
        mm2px(Vec(52.895, 108.713)), module, Bench1::OUT1_OUTPUT));

    addChild(createLightCentered<MediumLight<RedLight>>(
        mm2px(Vec(15.24, 108.713)), module, Bench1::LED0_LIGHT));
    addChild(createLightCentered<MediumLight<RedLight>>(
        mm2px(Vec(76.2, 108.713)), module, Bench1::LED1_LIGHT));
  }
};

Model* modelBench1 = createModel<Bench1, Bench1Widget>("bench1");
